#include <iostream>
#include "pi_trees_lib/headers/Task.h"
#include "pi_trees_lib/headers/Sequence.h"

using namespace std;

int main() {
    Task test("task_test");
    cout << test.name << endl;
    cout << test.children.size() << endl;
    cout << test.numChildren << endl;
}