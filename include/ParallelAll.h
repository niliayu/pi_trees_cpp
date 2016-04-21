//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_PARALLELALL_H
#define PI_TREES_PARALLELALL_H

#include <../include/Task.h>

class ParallelAll : public Task {

public:
    ParallelAll(const string &argName) : Task(argName) { }

    int run();

};


#endif //PI_TREES_PARALLELALL_H
