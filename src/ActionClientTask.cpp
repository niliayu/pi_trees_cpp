//
// Created by Ailin on 4/20/2016.
//

#include <../include/ros/ActionClientTask.h>

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <example_action_server/demoAction.h> //reference action message in this package
#include <iostream>
#include <string>
#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>

using namespace std;

int ActionClientTask::run(){

    geometry_msgs::Pose pose;
    nav_msgs::Path paths;
    std::vector<geometry_msgs::PoseStamped> plan;
    geometry_msgs::PoseStamped pose_stamped;

    while(!alarm){
        plan.clear();//empty old poses

        //make sure orientation is set to 0 here; may just have exited alarm state
        pose.orientation.x = 0.0; //always, for motion in horizontal plane
        pose.orientation.y = 0.0; // ditto
        pose.orientation.z = 0.0; // implies oriented at yaw=0, i.e. along x axis
        pose.orientation.w = 1.0; //sum of squares of all components of unit quaternion is 1

        pose.position.x = 3.0;
        pose.position.y = 0.0;
        pose.position.z = 0.0;
        pose_stamped.pose = pose;
        plan.push_back(pose_stamped);

        pose.position.x = 3.0;
        pose.position.y = 0.0;
        pose.position.z = 0.0;
        pose_stamped.pose = pose;
        plan.push_back(pose_stamped);

        pose.position.x = 3.0;
        pose.position.y = 0.0;
        pose.position.z = 0.0;
        pose_stamped.pose = pose;
        plan.push_back(pose_stamped);

        paths.poses = plan;
        ROS_INFO("sending pose goal");
        goal.input = paths; //populate a goal message
        action_client.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);
        ros::spinOnce();

        ROS_INFO("Alarm (off) state is: %d", alarm);
        usleep(500000);
    }
    ROS_INFO("cancelling goal");
    action_client.cancelGoal(); //this is how one can cancel a goal in process

    plan.clear();//empty old poses
    pose.position.x = 0.0;
    pose.position.y = 0.0;
    pose.position.z = 0.0;
    pose_stamped.pose = pose;
    plan.push_back(pose_stamped);
    pose.position.x = 0.0;
    pose.position.y = 0.0;
    pose.position.z = 0.0;
    pose_stamped.pose = pose;
    plan.push_back(pose_stamped);
    paths.poses = plan;
    ROS_INFO("sending stop");
    goal.input = paths;

    while(alarm){
        plan.clear();//empty old poses
        ROS_INFO("Client: Entered alarm loop");
        pose.position.y = 1.0;
        pose_stamped.pose = pose;
        plan.push_back(pose_stamped);
        paths.poses = plan;
        ROS_INFO("sending turn goal");
        goal.input = paths; //populate a goal message
        action_client.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);
        ros::spinOnce();
        usleep(500000);
        ROS_INFO("Alarm (on) state is: %d", alarm);
    }
}

int ActionClientTask::reset(){}

//specific to example

void doneCB(const actionlib::SimpleClientGoalState& state,
            const example_action_server::demoResultConstPtr& result){
    ROS_INFO(" doneCb: server responded with state [%s]", state.toString().c_str());
    ROS_INFO("got result output = %d",result->output);
    g_result_output= result->output;
    g_goal_active=false;
}

void feedbackCB(const example_action_server::demoFeedbackConstPtr& fdbk_msg){
    ROS_INFO("feedback status = %d",fdbk_msg->fdbk);
    g_fdbk = fdbk_msg->fdbk; //make status available to "main()"
}

void activeCB(){
    ROS_INFO("Goal just went active");
    g_goal_active=true; //let main() know that the server responded that this goal is in process
}

void alarmCB(const std_msgs::Bool& alarm_msg){
    ROS_INFO("Alarm!");
    g_goal_active = false;
    alarm = alarm_msg.data;

}

void locationCB(const std_msgs::Int32& location_message){
    //turn here based on value
    if(location_message.data > 0){//turn left
        g_turn_dir = -1;
    }else{//turn right
        g_turn_dir = 1;
    }
    ROS_INFO("Got location");
}

int main(int argc, char** argv){

    ros::init(argc, argv, "path_client_node"); // name this node
    ros::NodeHandle n;
    ros::Rate main_timer(1.0);
    // here is a "goal" object compatible with the server, as defined in example_action_server/action
    example_action_server::demoGoal goal;
    geometry_msgs::Quaternion quat;

    ros::Subscriber lidar_alarm_sub = n.subscribe("/lidar_alarm", 1, alarmCB);
    ros::Subscriber lidar_location_sub = n.subscribe("/lidar_location", 1, locationCB);

    // use the name of our server, which is: path_action (named in path_action_server.cpp)
    // the "true" argument says that we want our new client to run as a separate thread (a good idea)
    actionlib::SimpleActionClient<example_action_server::demoAction> action_client(servTopic, true);//"path_action", true);

    if(waitForServer){
        ROS_INFO("attempting to connect to server: ");
        bool server_exists = action_client.waitForServer(ros::Duration(1.0)); // wait for up to 1 second
        // something odd in above: sometimes does not wait for specified seconds,
        //  but returns rapidly if server not running; so we'll do our own version
        while (!server_exists) { // keep trying until connected
            ROS_WARN("could not connect to server; retrying...");
            server_exists = action_client.waitForServer(ros::Duration(1.0)); // retry every 1 second
        }
        ROS_INFO("connected to action server");  // if here, then we connected to the server;
    }

    while(ros::ok()){
        run();
    }
}