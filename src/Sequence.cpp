//
// Created by Ailin on 4/18/2016.
//

#include <../include/Sequence.h>
#include <../include/TaskStatus.h>
#include <vector>

//Runs each task in sequence until one fails or we run out of tasks
int Sequence::run(){
	ROS_INFO("Sequence running.");
    /*for(Task &t : children){
        t.status = t.run();

        if(t.status != SUCCESS)
                return t.status;
    }*/

    for(int i = 0; i < children.size(); i++){
    	cout << "Running child: " << children[i].name << endl;
    	children[i].run();
    }

    return SUCCESS;
}