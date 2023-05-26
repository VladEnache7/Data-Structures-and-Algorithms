#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
    this->current = 0;
    while(this->current < this->map.capacity && !this->map.elems[this->current].occupied)
        this->current++;
} // O(capacity)


void MapIterator::first() {
    this->current = 0;
    while(this->current < this->map.capacity && !this->map.elems[this->current].occupied)
        this->current++;
} // O(capacity)


void MapIterator::next() {
    if(!this->valid())
        throw exception();
    this->current++;
    while(this->current < this->map.capacity && !this->map.elems[this->current].occupied)
        this->current++;
} // O(capacity)


TElem MapIterator::getCurrent(){
	    if(!this->valid())
        throw exception();
    return make_pair(this->map.elems[this->current].key, this->map.elems[this->current].value);
} // Theta(1)


bool MapIterator::valid() const {
	    return 0 <= this->current && this->current < this->map.capacity;
} // Theta(1)



