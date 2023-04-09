#include "MultiMapIterator.h"
#include "MultiMap.h"
#include <exception>

MultiMapIterator::MultiMapIterator(const MultiMap& multiMapToBeSet): multiMap(multiMapToBeSet) {
    currentElement = multiMap.linkedList.head;
}
// Theta(1)

TElem MultiMapIterator::getCurrent() const{
    if (currentElement == nullptr)
        throw std::exception();
	return currentElement->data;
}
// Theta(1)

bool MultiMapIterator::valid() const {

    if (currentElement == nullptr)
        return false;
    else
        return true;
}
// Theta(1)

void MultiMapIterator::next() {
    if (currentElement == nullptr)
        throw std::exception();
	currentElement = currentElement->next;
}
// Theta(1)

void MultiMapIterator::first() {
	currentElement = multiMap.linkedList.head;
}
// Theta(1)

