//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_SELECTOR_H
#define PI_TREES_SELECTOR_H


#include "Task.h"

class Selector: public Task {

public:
    Selector(const string &argName, int argNumChildren) : Task(argName) { }

    int run();
};


#endif //PI_TREES_SELECTOR_H
