//
// Created by Ailin on 4/18/2016.
//

#include "headers/Selector.h"
#include "headers/TaskStatus.h"

/*A selector runs each task in order until one succeeds,
 * at which points is returns SUCCESS.  If all tasks fail,
 * a FAILURE status is returned.  If a subtask is still RUNNING,
 * then a RUNNING status is returned and processing continues
 * until either SUCCESS or FAILURE is returned from the subtask.
 * */
int Selector::run(){
    for(Task &t : children){
        t.status = t.run();

        if(t.status != FAILURE)
            return t.status;
    }

    return FAILURE;
}