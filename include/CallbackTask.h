//
// Created by Ailin on 4/22/2016.
//

#ifndef PI_TREES_CALLBACKTASK_H
#define PI_TREES_CALLBACKTASK_H


//#include "Task.h"
#include <../include/Task.h>
#include <std_msgs/Bool.h>

class CallbackTask : virtual public Task {

public:
	//void (*cb)(std_msgs::Bool);//(*cb_)(std_msgs::Bool);
	//std_msgs::Bool *msg;
	int (*cb_)(std_msgs::Bool);
	std_msgs::Bool msg_;

    CallbackTask(const string &argName, int (*cb)(std_msgs::Bool), std_msgs::Bool msg)://, void (*cb)(std_msgs::Bool), std_msgs::Bool *msg) :
            Task(argName){ 
            	cb_ = cb;
            	msg_ = msg;
            }

    int run() override;//void (*cb)(std_msgs::Bool), std_msgs::Bool *msg);
};


#endif //PI_TREES_CALLBACKTASK_H
