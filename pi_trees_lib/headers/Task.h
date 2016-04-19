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
    //Task();

    Task(string argName): name(argName), numChildren(children.size()), status(-1){} //constructor

    int run();

    void reset();

    void addChild(Task c);

    void removeChild(Task c);

    void prependChild(Task c);

    void insertChild(Task c, int pos);

    int getStatus();

    void printTree();

    bool operator==(const Task& c);

    string name;
    int numChildren;
    vector<Task> children;
    int status;
};

#endif //PI_TREES_TASK_H
