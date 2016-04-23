//
// Created by Ailin on 4/22/2016.
//

//#include "headers/CallbackTask.h"
#//include "headers/TaskStatus.h"
#include <ros/ros.h>
#include <../include/CallbackTask.h>
#include <../include/TaskStatus.h>

int CallbackTask::run(){//void (*cb)(std_msgs::Bool), std_msgs::Bool *msg){
    status = (*cb_)(msg_);
    return status;
}