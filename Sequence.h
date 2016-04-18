//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_SEQUENCE_H
#define PI_TREES_SEQUENCE_H

#include "Task.h"

class Sequence : public Task {

public:
    Sequence(const string &argName, int argNumChildren) : Task(argName, argNumChildren), name(argName), numChildren(argNumChildren), status(-1) { }

    
};


#endif //PI_TREES_SEQUENCE_H
