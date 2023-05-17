#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const IndexedList& list) : list(list){
   currentIndex = list.dllaList.head;
} // theta(1)

void ListIterator::first(){
    currentIndex = list.dllaList.head;
} // theta(1)

void ListIterator::next(){
    if (currentIndex == -1)
        throw exception();
    currentIndex = list.dllaList.next[currentIndex];
} // theta(1)

bool ListIterator::valid() const{
    if (this->currentIndex == -1)
        return false;
    return true;
} // theta(1)

TElem ListIterator::getCurrent() const{
    if (this->currentIndex == -1)
        throw exception();
    return this->list.dllaList.elems[this->currentIndex];
} // theta(1)