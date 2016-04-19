//
// Created by Ailin on 4/18/2016.
//

#include "ParallelOne.h"
#include "TaskStatus.h"

/* *
 * A parallel task runs each child task at (roughly) the same time.
 * The ParallelOne task returns success as soon as any child succeeds.
 */
int ParallelOne::run(){
    for(Task &t : children){
        t.status = t.run();

        if(t.status == SUCCESS){
            return SUCCESS;
        }
    }

    return FAILURE;
}