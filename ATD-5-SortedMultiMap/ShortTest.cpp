#include <assert.h>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>
#include <iostream>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());
}

void testReplace(){
    cout << "Test replace" << endl;
    SortedMultiMap smm = SortedMultiMap(relation1);
    smm.add(1,2);
    smm.add(1,3);
    smm.add(1,4);
    smm.replace(1, 2, 6);
    vector<TValue> v= smm.search(1);
    assert(v.size()==3);
    assert(v[0]==6);

    smm.replace(1, 10, 11);
    v= smm.search(1);
    assert(v.size()==3);
    assert(v[0]==6);
    assert(v[1]==3);
    assert(v[2]==4);
}
