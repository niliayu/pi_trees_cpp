#include <iostream>
#include "Task.h"
#include "Sequence.h"

using namespace std;

int main() {
    Sequence seqTest("test", 2);
    cout << seqTest.name << endl;
    cout << seqTest.numChildren << endl;
}