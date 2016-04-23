//
// Created by Ailin on 4/16/2016.
//

#ifndef PI_TREES_TASK_H
#define PI_TREES_TASK_H

#include <ros/ros.h>
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
    vector<Task> children;
    string name;
    int numChildren;
    int status;

    Task(string argName): name(argName), numChildren(children.size()), status(-1){} //constructor

    int run();

    void reset();

    void addChild(Task c);

    void removeChild(Task c);

    void prependChild(Task c);

    void insertChild(Task c, int pos);

    int getStatus();

    int setStatus(int status);

    void printTree();

    void listChildren();

    bool operator==(const Task& c);
};

#endif //PI_TREES_TASK_H