//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_MONITORTASK_H
#define PI_TREES_MONITORTASK_H

#include "../../pi_trees_lib/headers/Task.h"
//#include "ros/ros.h"
//#include "std_msgs/Empty.h"

class MonitorTask : public Task {

public:
    bool waitForMessage;
    string topic;

    MonitorTask(const string &argName, string topic) : Task(argName), waitForMessage(true), topic(topic) { }

    /**
     * In C++, ROS cannot create callbacks without knowing the message type,
     * so the callback must be overloaded in an instantiation of this class.
     */

    //void msgCB(const std_msgs::Int32::ConstPtr& msg);

    int run();

    int reset();

    int main(int argc, char **argv);
};

#endif //PI_TREES_MONITORTASK_H