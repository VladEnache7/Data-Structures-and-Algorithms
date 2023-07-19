#include "ExtendedTest.h"
#include "ShortTest.h"

#include "Map.h"


#include <iostream>
#include <cassert>

using namespace std;

bool even(TKey key) {
    return key % 2 == 0;
}

void testFilter(){
    cout << "Test filter\n" << endl;
    Map m;
    for(int i = 0; i < 10; i++)
        m.add(i, i);
    m.filter((Condition)even);
    assert(m.size() == 5);
    for(int i = 0; i < 10; i += 2)
        assert(m.search(i) == i);
    cout << "Test filter passed\n" << endl;
}


int main() {
	testAll();
	testAllExtended();
    testFilter();
	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


