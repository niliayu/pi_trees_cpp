//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_AUTOREMOVESEQUENCE_H
#define PI_TREES_AUTOREMOVESEQUENCE_H

#include "Task.h"

class AutoRemoveSequence : public Task {

public:
    AutoRemoveSequence(const string &argName) : Task(argName) { }

    int run();
};


#endif //PI_TREES_AUTOREMOVESEQUENCE_H
