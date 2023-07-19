#include <exception>

#include "IndexedList.h"
#include "ListIterator.h"

using namespace std;

IndexedList::IndexedList() {
    dllaList.size = 0;
    dllaList.capacity = 10;
    dllaList.elems = new TElem[dllaList.capacity];
    dllaList.next = new TElem[dllaList.capacity];
    dllaList.prev = new TElem[dllaList.capacity];
    dllaList.head = -1; // the index of head of the DLLA is firstly -1
    dllaList.tail = -1; // the index of tail of the DLLA is firstly -1

    // the index of the first empty space in the array is firstly 0
    dllaList.firstEmpty = 0;
    for (int i = 0; i < dllaList.capacity - 1; ++i) {
        dllaList.next[i] = i + 1;
    }
    dllaList.next[dllaList.capacity -
                  1] = -1; // the last element of the array is -1 and it means that there is no next free element

    for (int i = dllaList.capacity - 1; i > 0; --i) {
        dllaList.prev[i] = i - 1;
    }
    dllaList.prev[0] = -1; // the first element of the array is -1 and it means that there is no previous free element
}
// Theta(capacity)

int IndexedList::size() const {
    int size = 0;
//    return dllaList.size;
    int indexCurrent = dllaList.head;
    while (indexCurrent != -1) {
        indexCurrent = dllaList.next[indexCurrent];
        size++;
    }
    return size;
}
// Theta(1)


bool IndexedList::isEmpty() const {
    if (dllaList.size == 0)
        return true;
    else
        return false;
}
// Theta(1)

TElem IndexedList::getElement(int pos) const {
    if (pos > dllaList.size || pos < 0)
        throw exception();
    int indexCurrent = dllaList.head;
    int indexDLLA = 0;
    while (indexDLLA < pos) {
        indexCurrent = dllaList.next[indexCurrent];
        indexDLLA++;
    }
    return dllaList.elems[indexCurrent];
}
// BestCase: Theta(1) - if the element is the first element of the DLLA WorstCase: Theta(size) - if the element is the last element of the DLLA

TElem IndexedList::setElement(int pos, TElem newElem) {
    if (pos > dllaList.size || pos < 0)
        throw exception();
    int indexCurrent = dllaList.head;
    int indexDLLA = 0;
    while (indexDLLA < pos) {
        indexCurrent = dllaList.next[indexCurrent];
        indexDLLA++;
    }
    TElem oldValue = dllaList.elems[indexCurrent];
    dllaList.elems[indexCurrent] = newElem;
    return oldValue;
}
// BestCase: Theta(1) - if the element is the first element of the DLLA WorstCase: Theta(size) - if the element is the last element of the DLLA

void IndexedList::addToEnd(TElem newElem) {
    if (dllaList.firstEmpty == -1)
        resize();

    // the case when the list is empty
    if (dllaList.size == 0) {
        int posToBePlaced = dllaList.firstEmpty;
        dllaList.firstEmpty = dllaList.next[dllaList.firstEmpty];
        dllaList.elems[posToBePlaced] = newElem;
        dllaList.next[posToBePlaced] = -1;
        dllaList.prev[posToBePlaced] = -1;
        dllaList.head = posToBePlaced;
        dllaList.tail = posToBePlaced;
        dllaList.size++;

    } else { // the case when the list is not empty
        int posToBePlaced = dllaList.firstEmpty;
        dllaList.firstEmpty = dllaList.next[dllaList.firstEmpty];
        dllaList.elems[posToBePlaced] = newElem;
        dllaList.next[posToBePlaced] = -1;
        dllaList.prev[posToBePlaced] = dllaList.tail;
        dllaList.next[dllaList.tail] = posToBePlaced;
        dllaList.tail = posToBePlaced;
        dllaList.size++;
    }
} // Theta(1)

/// after one check it seems correct on theory
void IndexedList::addToPosition(int pos, TElem newElem) {
    if (pos > dllaList.size || pos < 0)
        throw exception();
    if (dllaList.firstEmpty == -1)
        resize();

    // the case when the list is empty
    if (pos == 0 && dllaList.size == 0) {
        int posToBePlaced = 0;
        dllaList.firstEmpty = dllaList.next[dllaList.firstEmpty];   //  move the firstEmpty to the next free space
        dllaList.elems[posToBePlaced] = newElem;
        dllaList.next[posToBePlaced] = -1;
        dllaList.prev[posToBePlaced] = -1;
        dllaList.head = posToBePlaced;
        dllaList.tail = posToBePlaced;
        dllaList.size++;

    } else if (pos == 0){
        int posToBePlaced = dllaList.firstEmpty;
        dllaList.firstEmpty = dllaList.next[dllaList.firstEmpty];
        dllaList.elems[posToBePlaced] = newElem;
        dllaList.next[posToBePlaced] = dllaList.head;
        dllaList.prev[posToBePlaced] = -1;
        dllaList.prev[dllaList.head] = posToBePlaced;
        dllaList.head = posToBePlaced;
        dllaList.size++;

    } else {
        int currentPos = 0;
        int indexCurrent = dllaList.head;
        while (currentPos < pos - 1) { // why pos - 1? because we want to place the new element before the element at position pos
            indexCurrent = dllaList.next[indexCurrent];
            currentPos++;
        }
        int posToBePlaced = dllaList.firstEmpty;
        dllaList.firstEmpty = dllaList.next[dllaList.firstEmpty];
        dllaList.elems[posToBePlaced] = newElem;
        dllaList.next[posToBePlaced] = dllaList.next[indexCurrent];
        dllaList.next[indexCurrent] = posToBePlaced;
        dllaList.prev[posToBePlaced] = indexCurrent;
        dllaList.prev[dllaList.next[posToBePlaced]] = posToBePlaced;
        dllaList.size++;
    }

} // BestCase: Theta(1) - if the element is the first element of the DLLA WorstCase: Theta(size) - if the element is the last element of the DLLA

TElem IndexedList::remove(int pos) {
    if (pos >= dllaList.size || pos < 0)
        throw std::exception();
    // search for the element at position pos without using iterator
    int indexCurrent = dllaList.head;
    int indexPos = 0;
    while (indexPos < pos) {
        indexCurrent = dllaList.next[indexCurrent];
        indexPos++;
    }
    int indexElemToBeRemoved = indexCurrent;
    TElem oldValue = dllaList.elems[indexElemToBeRemoved];

    // the case when the list has only one element
    if (dllaList.size == 1) { //  check if this is correct - theoretically seems correct
        /// update head and tail and size
        dllaList.head = -1;
        dllaList.tail = -1;
        dllaList.size = 0;

        /// update the firstEmpty
        dllaList.next[indexElemToBeRemoved] = dllaList.firstEmpty;
        dllaList.prev[dllaList.firstEmpty] = indexElemToBeRemoved;
        dllaList.firstEmpty = indexElemToBeRemoved;
        dllaList.prev[indexElemToBeRemoved] = -1;

    } else {
        // the case when the element to be removed is the head
        if (indexElemToBeRemoved == dllaList.head) { //  check if this is correct - theoretically seems correct
            // update the head
            dllaList.head = dllaList.next[indexElemToBeRemoved];
            dllaList.prev[dllaList.head] = -1;

            // update the firstEmpty
            if (dllaList.firstEmpty == -1) {
                dllaList.firstEmpty = indexElemToBeRemoved;
                dllaList.next[indexElemToBeRemoved] = -1;
                dllaList.prev[indexElemToBeRemoved] = -1;
            } else { //  check if this is correct - theoretically seems correct
                dllaList.prev[dllaList.firstEmpty] = indexElemToBeRemoved;
                dllaList.next[indexElemToBeRemoved] = dllaList.firstEmpty;
                dllaList.prev[indexElemToBeRemoved] = -1;
                dllaList.firstEmpty = indexElemToBeRemoved;
            }

            // update the size and the element to be removed
            dllaList.elems[indexElemToBeRemoved] = NULL_TELEM;
            dllaList.size--;
            return oldValue;
        } else {
            // the case when the element to be removed is the tail
            if (indexElemToBeRemoved == dllaList.tail) { //  check if this is correct - theoretically seems correct
                // update the tail
                dllaList.tail = dllaList.prev[indexElemToBeRemoved];
                dllaList.next[dllaList.tail] = -1;

                // update the firstEmpty
                if (dllaList.firstEmpty == -1) {
                    dllaList.firstEmpty = indexElemToBeRemoved;
                    dllaList.next[indexElemToBeRemoved] = -1;
                    dllaList.prev[indexElemToBeRemoved] = -1;
                } else { //  check if this is correct (theoretically seems correct)
                    dllaList.prev[dllaList.firstEmpty] = indexElemToBeRemoved;
                    dllaList.next[indexElemToBeRemoved] = dllaList.firstEmpty;
                    dllaList.prev[indexElemToBeRemoved] = -1;
                    dllaList.firstEmpty = indexElemToBeRemoved;
                }

                // update the size and the element to be removed
                dllaList.elems[indexElemToBeRemoved] = NULL_TELEM;
                dllaList.size--;
                return oldValue;
            } else {
                // the case when the element to be removed is in the middle //  check if this is correct - theoretically seems correct
                if (true) {


                    // update the links between the previous and the next element
                    dllaList.next[dllaList.prev[indexElemToBeRemoved]] = dllaList.next[indexElemToBeRemoved];
                    dllaList.prev[dllaList.next[indexElemToBeRemoved]] = dllaList.prev[indexElemToBeRemoved];

                    // update the firstEmpty
                    if (dllaList.firstEmpty == -1) {
                        dllaList.firstEmpty = indexElemToBeRemoved;
                        dllaList.next[indexElemToBeRemoved] = -1;
                        dllaList.prev[indexElemToBeRemoved] = -1;
                    } else { //  check if this is correct (theoretically seems correct)
                        dllaList.prev[dllaList.firstEmpty] = indexElemToBeRemoved;
                        dllaList.next[indexElemToBeRemoved] = dllaList.firstEmpty;
                        dllaList.prev[indexElemToBeRemoved] = -1;
                        dllaList.firstEmpty = indexElemToBeRemoved;
                    }

                    // update the size and the element to be removed
                    dllaList.elems[indexElemToBeRemoved] = NULL_TELEM;
                    dllaList.size--;
                    return oldValue;
                }
            }
        }
    }
} // BestCase: Theta(1) - if the element is the first element of the DLLA WorstCase: Theta(size) - if the element is the last element of the DLLA

int IndexedList::search(TElem elemSearched) const {
    // do the search without using the iterator
    int currentPos = 0;
    int currentIndex = dllaList.head;
    while (currentPos < dllaList.size && dllaList.elems[currentIndex] != elemSearched) {
        currentIndex = dllaList.next[currentIndex];
        currentPos++;
    }
    if (dllaList.elems[currentIndex] != elemSearched)
        return -1;
    else
        return currentPos;
} // BestCase: Theta(1) - if the element is the first element of the DLLA WorstCase: Theta(size) - if the element is the last element of the DLLA


ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
} // Theta(1)

IndexedList::~IndexedList() {
    delete [] dllaList.elems;
    delete [] dllaList.next;
    delete [] dllaList.prev;
} // Theta(1)

void IndexedList::resize() {
    int newCapacity = dllaList.capacity * 2;
    auto *newElems = new TElem[newCapacity];
    int *newNext = new int[newCapacity];
    int *newPrev = new int[newCapacity];

    // copy the old elements
    for (int i = 0; i < dllaList.capacity; ++i) {
        newElems[i] = dllaList.elems[i];
        newNext[i] = dllaList.next[i];
        newPrev[i] = dllaList.prev[i];
    }

    // initialize the new elements
    for (int i = dllaList.capacity; i < newCapacity; ++i) {
        newElems[i] = NULL_TELEM;
        newNext[i] = i + 1;
        newPrev[i] = i - 1;
    }
    newNext[newCapacity - 1] = -1;
    newPrev[dllaList.capacity] = -1;

    // delete the old DLLA
    delete[] dllaList.elems;
    delete[] dllaList.next;
    delete[] dllaList.prev;

    // update the DLLA
    dllaList.elems = newElems;
    dllaList.next = newNext;
    dllaList.prev = newPrev;
    dllaList.firstEmpty = dllaList.capacity;
    dllaList.capacity = newCapacity;
    // head and tail index remain the same
} // Theta(n)

int IndexedList::lastIndexOf(TElem elemSearched) const {
    // do the search without using the iterator
    int currentPos = dllaList.size - 1;
    int currentIndex = dllaList.tail;
    while (currentPos >= 0 && dllaList.elems[currentIndex] != elemSearched) {
        currentIndex = dllaList.prev[currentIndex];
        currentPos--;
    }
    if (dllaList.elems[currentIndex] != elemSearched)
        return -1;
    else
        return currentPos;
} // BestCase: Theta(1) - if the element is the last element of the DLLA WorstCase: Theta(size) - if the element is the first element of the DLLA
