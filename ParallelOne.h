//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_PARALLELONE_H
#define PI_TREES_PARALLELONE_H

#include "Task.h"

class ParallelOne : public Task{

public:
    ParallelOne(const string &argName, int argNumChildren) : Task(argName, argNumChildren) { }

    int run();
};


#endif //PI_TREES_PARALLELONE_H
