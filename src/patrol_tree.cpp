/*Description here */

#include <ros/ros.h>
#include <std_msgs/Bool.h>

#include <../include/Task.h>
#include <../include/Sequence.h>
#include <../include/Selector.h>
#include <../include/Loop.h>
#include <../include/CallbackTask.h>

using namespace std;

std_msgs::Bool t;
std_msgs::Bool f;
ros::NodeHandle nh;

int main(int argc, char **argv){
  ros::init(argc, argv, "patrol_tree");

  Sequence behave("BEHAVE");
  Selector stay_healthy("STAY_HEALTHY");
  Loop loop_patrol("LOOP_PATROL", 5);

  behave.addChild(stay_healthy);
  behave.addChild(loop_patrol);

  //CallbackTask patrol_task("PATROL");


}

int patrol(std_msgs::Bool bool_msg){
	ros::Publisher patrol_move = nh.advertise<std_msgs::Bool>("/patrol_move", 1);
	bool_msg.data = true;
	patrol_move.publish(bool_msg);
}