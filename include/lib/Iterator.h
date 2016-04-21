//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_ITERATOR_H
#define PI_TREES_ITERATOR_H

#include "Task.h"

class Iterator : public Task{

public:
    Iterator(const string &argName) : Task(argName) { }

    int run();
};


#endif //PI_TREES_ITERATOR_H
