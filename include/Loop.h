//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_LOOP_H
#define PI_TREES_LOOP_H

#include <../include/Task.h>

class Loop : virtual public Task {

public:
    Loop(const string &argName, int numIt) : Task(argName), iterations(numIt), count(0) { }

    int run() override;

    void restart();

    int iterations, count;
    Task *child;
};


#endif //PI_TREES_LOOP_H
