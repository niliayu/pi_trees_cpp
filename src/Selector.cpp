//
// Created by Ailin on 4/18/2016.
//

#include <../include/Selector.h>
#include <../include/TaskStatus.h>

/*A selector runs each task in order until one succeeds,
 * at which points is returns SUCCESS.  If all tasks fail,
 * a FAILURE status is returned.  If a subtask is still RUNNING,
 * then a RUNNING status is returned and processing continues
 * until either SUCCESS or FAILURE is returned from the subtask.
 * */
int Selector::run(){
	ROS_INFO("Selector running");
    for(Task *t : children){
        t->status = t->run();
        cout << "Selector running child: " << t->name << "with status" << t->status<< endl;
        if(t->status != FAILURE)
            return t->status;
    }

    return FAILURE;
}