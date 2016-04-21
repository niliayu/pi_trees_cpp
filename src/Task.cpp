//
// Created by Ailin on 4/16/2016.
//

#include <../include/Task.h>
#include <../include/TaskStatus.h>
#include <vector>
#include <algorithm>

using namespace std;

//Task::Task(){};

//Task::Task(string argName, int argNumChildren): name(argName), numChildren(argNumChildren), status(-1){ };

int Task::run(){ } //when using this class, override this method with the wanted task

void Task::reset(){
    //clear children
    for(int i = 0; i < children.size(); i++){
        children[i].reset();
    }
    status = -1; //reset status to invalid value
}

void Task::addChild(Task c){
    children.push_back(c);
}

void Task::removeChild(Task c){
    vector<Task>::iterator toRemove = find(children.begin(), children.end(), c);
    children.erase(toRemove);
}

void Task::prependChild(Task c){
    children.insert(children.begin(), c);
}

void Task::insertChild(Task c, int pos){
    vector<Task>::iterator insertPos = pos + children.begin();
    children.insert(insertPos, c);
}

int Task::getStatus(){
    return status;
}

int Task::setStatus(int status){
    Task::status = status;
    return status;
}

bool Task::operator==(const Task& c){
    return (numChildren == c.numChildren) &&
            (status == c.status)&&
            (name.compare(c.name)==0);
}
