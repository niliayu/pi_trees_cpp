//
// Created by Ailin on 4/18/2016.
//

#include <../include/Iterator.h>
#include <../include/TaskStatus.h>

/**
 * Iterate through all child tasks, ignoring any failures.
 */
int Iterator::run(){
    for(Task &t : children){
        t.status = t.run();

        if(t.status != SUCCESS && t.status != FAILURE)
            return t.status;
    }

    return SUCCESS;
}