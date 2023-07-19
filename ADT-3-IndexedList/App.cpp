#include <iostream>
#include <cassert>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "IndexedList.h"

using namespace std;

/// test for the extra assignment
void testLastIndexOf(){
    IndexedList list = IndexedList();
    list.addToEnd(1);
    list.addToEnd(2);
    list.addToEnd(3);
    list.addToEnd(2);
    list.addToEnd(1);
    assert(list.lastIndexOf(1) == 4);
    assert(list.lastIndexOf(2) == 3);
    assert(list.lastIndexOf(3) == 2);
    assert(list.lastIndexOf(4) == -1);
    assert(list.lastIndexOf(0) == -1);
    assert(list.lastIndexOf(-100) == -1);
    assert(list.lastIndexOf(100) == -1);
}


int main(){
    testAll();
    testAllExtended();
    testLastIndexOf();
    cout<<"Finished LI Tests!"<<endl;
}