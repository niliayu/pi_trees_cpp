//
// Created by Ailin on 4/16/2016.
//

#ifndef PI_TREES_TASK_H
#define PI_TREES_TASK_H

//#include <ros/ros.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Base Task class
class Task
{
public:
    Task();

    Task(string argName, int argNumChildren); //constructor

    void run();

    void reset();

    void addChild(Task c);

    void removeChild(Task c);

    void prependChild(Task c);

    void insertChild(Task c, int pos);

    int getStatus();

    bool operator==(const Task& c);

    string name;
    int numChildren;
    vector<Task> children;
    int status;
};

#endif //PI_TREES_TASK_H
