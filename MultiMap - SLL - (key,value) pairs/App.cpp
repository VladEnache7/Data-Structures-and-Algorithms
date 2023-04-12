#include <iostream>
#include "MultiMap.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include "MultiMapIterator.h"
#include <cassert>

using namespace std;

// test for the new functionality filter
bool odd(TKey key) {
    return key % 2 == 1;
}

void testFilter() {
    MultiMap m;
    m.add(1, 100);
    m.add(2, 200);
    m.add(3, 300);
    m.add(1, 500);
    m.add(2, 600);
    m.add(4, 800);
    m.filter(odd);
    assert(m.size() == 3);
    MultiMapIterator iterator = m.iterator();
    while (iterator.valid()) {
        TKey key = iterator.getCurrent().first;
        assert(key % 2 == 1);
        iterator.next();
    }

}

int main() {


	testAll();
    testFilter();
	testAllExtended();
	cout << "Yeey, all test run correctly!!" << endl;
	system("pause");

}
