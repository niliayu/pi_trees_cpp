//
// Created by Ailin on 4/19/2016.
//

#ifndef PI_TREES_SERVICETASK_H
#define PI_TREES_SERVICETASK_H

#include "../../pi_trees_lib/headers/Task.h"
//#include "ros/ros.h"

class ServiceClientTask : public Task {

public:
    bool waitForServer;
    string servTopic;
    ServiceClientTask(const string &argName, string servTopic, bool waitForServer) :
            Task(argName), servTopic{servTopic}, waitForServer(waitForServer){ }

    int run();

    int reset();

    int main(int argc, char** argv);
};


#endif //PI_TREES_SERVICETASK_H