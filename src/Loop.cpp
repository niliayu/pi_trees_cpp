//
// Created by Ailin on 4/18/2016.
//

#include <../include/Loop.h>
#include <../include/TaskStatus.h>


/**
 * Loop over one or more subtasks for the given number of iterations.
 * Use the value -1 to indicate a continual loop.
 */
int Loop::run(){
    while(true){
        if(iterations != -1 && count >= iterations)
            return SUCCESS;

        for(Task &t : children) {
            while (true) {
                t.status = t.run();

                if (t.status == SUCCESS)
                    break;

                return t.status;
            }
            t.reset();
        }
        count += 1;
        cout << "Loop" << name << "completed with" << count << "iterations" << endl;
    }
}