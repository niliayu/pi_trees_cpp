//
// Created by Ailin on 4/18/2016.
//

#include "headers/IgnoreFailure.h"
#include "headers/TaskStatus.h"

/**
 * Always returns either RUNNING or SUCCESS.
 */
int IgnoreFailure::run(){
    for(Task &t : children){
        t.status = t.run();

        if(t.status == FAILURE)
            return SUCCESS; //it literally just lies.
        else
            return t.status;
    }

    return SUCCESS;
}