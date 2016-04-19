//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_MONITORTASK_H
#define PI_TREES_MONITORTASK_H

#include "../../pi_trees_lib/headers/Task.h"
//#include "ros/ros.h"

class MonitorTask : public Task {

public:
    MonitorTask(const string &argName, int argNumChildren) : Task(argName, argNumChildren), waitForMessage(true) { }

    bool waitForMessage;
    int timeout;
    string topic, msgCB;
};


#endif //PI_TREES_MONITORTASK_H
