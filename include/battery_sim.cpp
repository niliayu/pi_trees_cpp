#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Bool.h"

/**
 * Simulates a really bad battery.
 */


void chargingCB(const std_msgs::Bool& msg){
  battery_level.data = 110;
  charge_pub.publish(battery_level);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "battery_node");
  ros::NodeHandle nh;

  ros::Publisher battery_pub = n.advertise<std_msgs::Float32>("battery_level", 1);
  ros::Publisher charge_pub = n.advertise<std_msgs::Float32>("charge_amt", 1);
  ros::Subscriber charge_sub = n.subscribe("charging", 1, chargingCB);

  std_msgs::Float32 battery_level;

  battery_level.data = 100;

  ros::Rate loop_rate(1);
  int count = 0;
  while (ros::ok())
  {
    if(battery_level.data > 0){
        battery_level.data -= 10;
    }

    ROS_INFO("Current battery level: %f", battery_level.data);

    battery_pub.publish(battery_level);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}