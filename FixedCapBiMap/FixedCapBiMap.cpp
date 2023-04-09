#include <exception>
#include <stdlib.h>

#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"

using namespace std;

FixedCapBiMap::FixedCapBiMap(int capacity) {
    if (capacity <= 0)
        throw exception();
    this->capacity = capacity;
    this->nrPairs = 0;
    this->elements = new TElem[capacity];
}
//Theta(1)

FixedCapBiMap::~FixedCapBiMap() {
    delete[] this->elements;
}
//Theta(1)

bool FixedCapBiMap::add(TKey c, TValue v) {
    if (this->nrPairs == this->capacity)
        throw exception();
    int keyAppearances = 0;
    int index = 0;
    while (keyAppearances < 2 && index < this->nrPairs) {
        if (this->elements[index].first == c)
            keyAppearances++;
        index++;
    }
    if (keyAppearances == 2) {
        return false;
    } else {
        this->elements[this->nrPairs].first = c;
        this->elements[this->nrPairs].second = v;
        this->nrPairs++;
        return true;
    }
}
//Best case: Theta(1), Worst case: Theta(nrPairs) => Total complexity: O(nrPairs)

ValuePair FixedCapBiMap::search(TKey c) const {
    ValuePair returnedValue = NULL_TELEM;
    int found = 0, index = 0;
    while (found < 2 && index < this->nrPairs) {
        if (this->elements[index].first == c) {
            if (found == 0) {
                returnedValue.first = this->elements[index].second;
            } else {
                returnedValue.second = this->elements[index].second;
            }
            found++;
        }
        index++;
    }
    return returnedValue;
}
//Best case: Theta(1), Worst case: Theta(nrPairs) => Total complexity: O(nrPairs)

bool FixedCapBiMap::remove(TKey c, TValue v) {
    for (int i = 0; i < this->nrPairs; ++i) {
        if (this->elements[i].first == c && this->elements[i].second == v) {
            this->elements[i] = this->elements[this->nrPairs - 1];
            this->nrPairs--;
            return true;
        }
    }
    return false;
}
//Best case: Theta(1), Worst case: Theta(nrPairs) => Total complexity: O(nrPairs)

int FixedCapBiMap::size() const {
    return this->nrPairs;
}
//Theta(1)

bool FixedCapBiMap::isEmpty() const {
    return (this->nrPairs == 0);
}
//Theta(1)

bool FixedCapBiMap::isFull() const {
    return (this->nrPairs == this->capacity);
}
//Theta(1)

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
    return FixedCapBiMapIterator(*this);
}
//Theta(1)



