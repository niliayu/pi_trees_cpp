//
// Created by Ailin on 4/18/2016.
//

#include "Sequence.h"
#include "TaskStatus.h"
#include <vector>

//Runs each task in sequence until one fails or we run out of tasks
int Sequence::run(){
    for(Task &t : children){
        t.status = t.run();

        if(t.status != SUCCESS)
                return t.status;
    }

    return SUCCESS;
}