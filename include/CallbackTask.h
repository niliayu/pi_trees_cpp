//
// Created by Ailin on 4/22/2016.
//

#ifndef PI_TREES_CALLBACKTASK_H
#define PI_TREES_CALLBACKTASK_H


//#include "Task.h"
#include <../include/Task.h>

class CallbackTask : public Task {

public:
    CallbackTask(const string &argName, void (*cb)(int), bool *msg) :
            Task(argName){ }

    int run(void (*cb)(bool), bool *msg);
};


#endif //PI_TREES_CALLBACKTASK_H
