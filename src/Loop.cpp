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
        cout << "Children: " << children.size() << endl;
        cout << "Count: " << count << endl;
        cout << "Iterations: " << iterations << endl;
        if(iterations != -1 && count >= iterations){
            count = 0;
            return SUCCESS;
        }
        for(Task *t : children) {
        
        ROS_INFO("Loop running");
            while (true) {
                t->status = t->run();

                if (t->status == SUCCESS)
                    break;

                return t->status;
            }
        //child = children[0]; //for reset
        //t->reset();
        }

    count += 1;
    cout << "Loop " << name << "completed with " << count << "iterations" << endl;
    }
}

void Loop::restart(){
    //ROS_INFO("Restarting loop");
    count = 0;
    //addChild(child);
    //Task *temp = children[0];
    //reset();
    //addChild(temp);
    //run();
}