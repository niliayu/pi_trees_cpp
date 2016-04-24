//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_SELECTOR_H
#define PI_TREES_SELECTOR_H


#include <../include/Task.h>

class Selector: virtual public Task {

public:
    Selector(const string &argName) : Task(argName) { }

    int run() override;
};


#endif //PI_TREES_SELECTOR_H
