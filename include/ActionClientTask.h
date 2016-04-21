//
// Created by Ailin on 4/20/2016.
//

#ifndef PI_TREES_ACTIONCLIENTTASK_H
#define PI_TREES_ACTIONCLIENTTASK_H

#include <ros/ros.h>
#include <../include/lib/Task.h>
//#include "ros/ros.h"

class ActionClientTask : public Task{

public:
    bool goal_active, waitForServer;
    int result_output, fdbk, turn, alarm;
    string servTopic;

    ActionClientTask(const string &argName, string servTopic, bool waitForServer) :
            Task(argName), servTopic(servTopic), waitForServer(waitForServer) { }

    int run();

    int reset();

    //specific to example
    /*
    void doneCB(const actionlib::SimpleClientGoalState& state,
                const example_action_server::demoResultConstPtr& result);

    void feedbackCB(const example_action_server::demoFeedbackConstPtr& fdbk_msg);

    void activeCB();

    void alarmCB(const std_msgs::Bool& alarm_msg);

    void locationCB(const std_msgs::Int32& location_message);

    int main(int argc, char** argv);*/
};


#endif //PI_TREES_ACTIONCLIENTTASK_H
