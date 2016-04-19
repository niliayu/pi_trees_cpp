#include <iostream>
#include "pi_trees_lib/headers/Task.h"
#include "pi_trees_lib/headers/Sequence.h"

using namespace std;

int main() {
    Sequence seqTest("test", 2);
    cout << seqTest.name << endl;
    cout << seqTest.numChildren << endl;
}