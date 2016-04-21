//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_SEQUENCE_H
#define PI_TREES_SEQUENCE_H

#include "Task.h"

class Sequence : public Task {

public:
    Sequence(const string &argName) : Task(argName){ }

    int run();
};


#endif //PI_TREES_SEQUENCE_H
