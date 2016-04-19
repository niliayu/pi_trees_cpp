//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_LOOP_H
#define PI_TREES_LOOP_H

#include "Task.h"

class Loop : public Task {

public:
    Loop(const string &argName, int argNumChildren, int numIt) : Task(argName), iterations(numIt), count(0) { }

    int run();

    int iterations, count;
};


#endif //PI_TREES_LOOP_H
