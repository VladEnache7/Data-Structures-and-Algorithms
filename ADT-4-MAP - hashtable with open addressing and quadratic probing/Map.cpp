#include <cmath>
#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	this->capacity = 1024;
    this->nrElems = 0;
    this->elems = new pair[this->capacity];
} // Theta(1)

int Map::hash(TKey key, int iteration) const {
    double A = 0.6180339887;
    // c=c1=c2=0.5
    // m power of 2
    // =>
    // the hash function will allways be a permutation
    double c = 0.5;

    if(key < 0)
        key = ~key + 1;

    return (int)(floor(this->capacity * fmod(key * A, 1)) + c * iteration + c * iteration * iteration) % this->capacity;
} // Theta(1)

void Map::resize() {
    // double the capacity
    this->capacity *= 2;
    pair* newElems = new pair[this->capacity];

    // rehash all the elements
    for(int i = 0; i < this->capacity / 2; i++) {
        if(this->elems[i].occupied) {
            int j = 0;
            int index = this->hash(this->elems[i].key, j);
            while(newElems[index].occupied) {
                j++;
                index = this->hash(this->elems[i].key, j);
            }
            newElems[index].key = this->elems[i].key;
            newElems[index].value = this->elems[i].value;
            newElems[index].occupied = true;
        }
    }

    // delete the old array and set the new one
    delete[] this->elems;
    this->elems = newElems;
} // Theta(capacity)


TValue Map::add(TKey key, TValue newValue){
    // If the load factor is reached, resize the array
    if (this->nrElems >= this->capacity * LoadFactor)
        this->resize();

    // If the element is already in the map, update its newValue
    int i = 0;
    int index = this->hash(key, i);
    while(this->elems[index].occupied && this->elems[index].key != key) {
        i++;
        index = this->hash(key, i);
    }
    if(this->elems[index].occupied) {
        TValue oldValue = this->elems[index].value;
        this->elems[index].value = newValue;
        return oldValue;
    }

    // If the element is not in the map, add it
    this->elems[index].key = key;
    this->elems[index].value = newValue;
    this->elems[index].occupied = true;
    this->nrElems++;

    return NULL_TVALUE;
} // O(capacity)

TValue Map::search(TKey key) const{
	// if the element is in the map, return its value
    int i = 0;
    int index = this->hash(key, i);
    while(this->elems[index].occupied && this->elems[index].key != key) {
        i++;
        index = this->hash(key, i);
    }
    if(this->elems[index].occupied)
        return this->elems[index].value;

    // if the element is not in the map, return NULL_TVALUE
    return NULL_TVALUE;
} // O(capacity)

TValue Map::remove(TKey key){
	// if the element is in the map, remove it and return its value
    int iteration = 0;
    int index = this->hash(key, iteration);
    while(iteration < this->capacity){
        if(this->elems[index].occupied && this->elems[index].key == key) {
            TValue oldValue = this->elems[index].value;
            this->elems[index].occupied = false;
            this->nrElems--;
            return oldValue;
        } else {
            iteration++;
            index = this->hash(key, iteration);
        }
    }

    // if the element is not in the map, return NULL_TVALUE
    return NULL_TVALUE;
} // O(capacity)


int Map::size() const {
	return this->nrElems;
}   // Theta(1)

bool Map::isEmpty() const{
    return this->nrElems == 0;
} // Theta(1)

MapIterator Map::iterator() const {
	return MapIterator(*this);
} // Theta(1)

Map::~Map() {
    delete[] this->elems;
} // Theta(1)

void Map::filter(Condition condition) {
    // going through all the elements and remove those that does not respect the condition
    MapIterator mi = this->iterator();
    while(mi.valid()){
        if(!condition(mi.getCurrent().first))
            this->remove(mi.getCurrent().first);
        mi.next();
    }
} // O(capacity)




