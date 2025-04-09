#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main() {

    testAll();
    //testAll2();
    cout << "Short tests over" << endl;

    testAllExtended();
    cout << "All test over" << endl;
}