//
// Created by Ailin on 4/18/2016.
//

#include "headers/MonitorTask.h"

//void MonitorTask::msgCB(const std_msgs::Int32::ConstPtr& msg){ }

int MonitorTask::run(){
    return status;
}

int MonitorTask::reset(){}

int MonitorTask::main(int argc, char **argv) {
    //ros::init(argc, argv, "monitor");

    cout << "Subscribing to topic" << topic << endl;

    //ros::NodeHandle nh;
    //ros::Subscriber sub = nh.subscribe(topic, 1, msgCB);

    //ros::spin();

    return 0;
}