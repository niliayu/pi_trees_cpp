//
// Created by Ailin on 4/18/2016.
//

#include "ParallelAll.h"
#include "TaskStatus.h"

/**
 * A parallel task runs each child task at (roughly) the same time.
 * The ParallelAll task requires all subtasks to succeed for it to succeed.
 */
int ParallelAll::run(){
    int nSuccess = 0;
    int nChildren = children.size();

    for(Task &t : children){
        t.status = t.run();

        if(t.status == SUCCESS)
            nSuccess += 1;

        if(t.status == FAILURE)
            return FAILURE;
    }

    if(nSuccess == nChildren)
        return SUCCESS;
    else
        return RUNNING;
}