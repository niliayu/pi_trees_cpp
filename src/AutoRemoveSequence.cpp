//
// Created by Ailin on 4/18/2016.
//

#include <../include/AutoRemoveSequence.h>
#include <../include/TaskStatus.h>

/**
 * Remove each successful task from a sequence.
 */
int AutoRemoveSequence::run(){
    for(Task *t : children){
        if(t->status == FAILURE)
            return FAILURE;

        if(t->status == RUNNING)
            return RUNNING;

        // below is altered from python version logic
        if(t->status == SUCCESS)
            removeChild(t);
    }

    return SUCCESS;
}