//
// Created by Ailin on 4/19/2016.
//

#include "headers/ServiceClientTask.h"
/*
#include <ros/ros.h>
#include <example_ros_service/PathSrv.h> // this message type is defined in the current package
#include <iostream>
#include <string>
#include <nav_msgs/Path.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
using namespace std;*/

/*
 * Turns a service client into a task.
 *
 * In python this is made generic, but since in C++ this is not possible,
 * this version is created as an example with the path_client service
 * from class;
 */
int ServiceClientTask::run(){
    //client.call(path_srv);
}

int ServiceClientTask::reset(){}

int ServiceClientTask::main(int argc, char** argv){
    /*
    ros::init(argc, argv, "path_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<example_ros_service::PathSrv>(servTopic);//"path_service");
    geometry_msgs::Quarternion quat;

     if(waitForServer){
        while (!client.exists()) {
            ROS_INFO("waiting for service...");
            ros::Duration(1.0).sleep();
        }
        ROS_INFO("connected client to service");
        }
    example_ros_service::PathSrv path_srv;

    geometry_msgs::PoseStamped pose_stamped;
    geometry_msgs::Pose pose;
    pose.position.x = 1.0; // say desired x-coord is 1
    pose.position.y = 0.0;
    pose.position.z = 0.0; // let's hope so!
    pose.orientation.x = 0.0; //always, for motion in horizontal plane
    pose.orientation.y = 0.0; // ditto
    pose.orientation.z = 0.0; // implies oriented at yaw=0, i.e. along x axis
    pose.orientation.w = 1.0; //sum of squares of all components of unit quaternion is 1
    pose_stamped.pose = pose;
    path_srv.request.nav_path.poses.push_back(pose_stamped);

    // some more poses...
    pose_stamped.pose.position.x=1.0;
    path_srv.request.nav_path.poses.push_back(pose_stamped);

    pose_stamped.pose.position.x=1.0;
    path_srv.request.nav_path.poses.push_back(pose_stamped);
*/
    run();

    return 0;
}