/*Description here */

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float32.h>

#include <../include/Task.h>
#include <../include/TaskStatus.h>
#include <../include/Sequence.h>
#include <../include/Selector.h>
#include <../include/Loop.h>
#include <../include/CallbackTask.h>

using namespace std;

//Standard fields for callbacks
std_msgs::Bool t;
std_msgs::Bool f;

//Battery level of robot
std_msgs::Float32 battery_level;
std_msgs::Float32 charge_level;

//Patrol publishers and subscribers
ros::Publisher patrol_move;

//"Health" publishers and subscribers
ros::Subscriber battery_level_sub;
ros::Publisher nav_dock;
ros::Publisher charge;
ros::Subscriber check_charge;
bool need_charge = false;

int patrol(std_msgs::Bool bool_msg){
	//bool_msg.data = true;
	ROS_INFO("Publishing patrol move");
	patrol_move.publish(bool_msg);
	return SUCCESS;
}

int check_battery_fnc(std_msgs::Bool bool_msg){
	ROS_INFO("Checking battery");
	if(battery_level.data < 30){ //0 < value < 100
		ROS_INFO("Low battery! Level: %f", battery_level.data);
    need_charge = true;
		return FAILURE;
	}else{
		ROS_INFO("Battery okay. Level: %f", battery_level.data);
		return SUCCESS;
    need_charge = false;
	}
}

void battery_level_cb(const std_msgs::Float32& level){
	//ROS_INFO("Recieved battery level");
	battery_level = level;
}

int nav_dock_fnc(std_msgs::Bool bool_msg){
	ROS_INFO("Navigating to dock");
	nav_dock.publish(bool_msg);
	return SUCCESS;
}

int charging_fnc(std_msgs::Bool bool_msg){
	ROS_INFO("Charging");
	charge.publish(bool_msg);
	return SUCCESS;
}

void charge_cb(const std_msgs::Float32& amt){
	ROS_INFO("Recieved charge amount");
	charge_level = amt;
}

int charge_complete_check(std_msgs::Bool bool_msg){
	ROS_INFO("Checking if charge is complete");
	if(charge_level.data >= 100){
		return SUCCESS;
	}else{
		return RUNNING;
	}
}

int main(int argc, char **argv){
  ros::init(argc, argv, "patrol_tree");
  ros::NodeHandle nh;

  //TREE ROOT
  Sequence behave("BEHAVE");


  //PATROL BEHAVIOR
  Loop loop_patrol("LOOP_PATROL", 5);

  behave.addChild(&loop_patrol);

  int (*patrol_ref)(std_msgs::Bool); //references to patrol function for CallbackTask
  patrol_ref = &patrol;
  t.data = true;
  patrol_move = nh.advertise<std_msgs::Bool>("/patrol_move", 1);//publisher to activate client
  CallbackTask patrol_task("PATROL", patrol_ref, t);
  
  loop_patrol.addChild(&patrol_task);

  //BATTERY MONITORING BEHAVIOR

  Selector stay_healthy("STAY_HEALTHY");
  behave.addChild(&stay_healthy);

  int (*check_battery_ref)(std_msgs::Bool);
  check_battery_ref = &check_battery_fnc;
  f.data = false;
  battery_level_sub = nh.subscribe("/battery_level", 1, battery_level_cb);
  CallbackTask check_battery("CHECK_BATTERY", check_battery_ref, f);

  stay_healthy.addChild(&check_battery);

  Sequence recharge("RECHARGE");

  stay_healthy.addChild(&recharge);

  int (*nav_to_dock)(std_msgs::Bool); //references to patrol function for CallbackTask
  nav_to_dock = &nav_dock_fnc;
  nav_dock = nh.advertise<std_msgs::Bool>("/nav_dock", 1);//publisher to activate client
  CallbackTask navdock("NAVDOCK", nav_to_dock, t);


  int (*charging_ref)(std_msgs::Bool); //references to patrol function for CallbackTask
  charging_ref = &charging_fnc;
  charge = nh.advertise<std_msgs::Bool>("/charging", 1);//publisher to activate client
  CallbackTask charging("CHARGING", charging_ref, t);

  int (*charge_complete_ref)(std_msgs::Bool);
  charge_complete_ref = &charging_fnc;
  check_charge = nh.subscribe("/charge_amt", 1, charge_cb);
  CallbackTask charge_complete("CHARGE_COMPLETE", charge_complete_ref, f);

  recharge.addChild(&navdock);
  recharge.addChild(&charging);
  recharge.addChild(&charge_complete);

  ros::Rate loop_rate(1);

  while(ros::ok()){
  	behave.run();
  	behave.listChildren();
  	ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}