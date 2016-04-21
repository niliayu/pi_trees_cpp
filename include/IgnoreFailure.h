//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_IGNOREFAILURE_H
#define PI_TREES_IGNOREFAILURE_H

#include <../include/Task.h>

class IgnoreFailure : public Task {

public:
    IgnoreFailure(const string &argName) : Task(argName) { }

    int run();
};


#endif //PI_TREES_IGNOREFAILURE_H
