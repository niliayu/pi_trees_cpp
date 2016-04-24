//
// Created by Ailin on 4/18/2016.
//

#ifndef PI_TREES_SEQUENCE_H
#define PI_TREES_SEQUENCE_H

#include <../include/Task.h>

class Sequence : virtual public Task {

public:
    Sequence(const string &argName) : Task(argName){ }

    int run() override;
};


#endif //PI_TREES_SEQUENCE_H
