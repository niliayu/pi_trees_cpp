//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_IGNOREFAILURE_H
#define PI_TREES_IGNOREFAILURE_H

#include "Task.h"

class IgnoreFailure : public Task {

public:
    IgnoreFailure(const string &argName, int argNumChildren) : Task(argName, argNumChildren) { }

    int run();
};


#endif //PI_TREES_IGNOREFAILURE_H