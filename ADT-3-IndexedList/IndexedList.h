#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111
class ListIterator;

typedef struct DLLA{
    int head;   // the index of head of the DLLA
    int tail;   // the index of tail of the DL
    int firstEmpty;     // the index of the first empty space in the array
    TElem* elems;   // the data of the nodes
    TElem* next;    // the index of the next node
    TElem* prev;    // the index of the previous node

    // info about the array
    int size;
    int capacity;
}DLLA;


class IndexedList {
private:
	DLLA dllaList{};
	
	//DO NOT CHANGE THIS PART
    friend class ListIterator;    
public:
    // constructor
    IndexedList ();

    // returns the number of elements from the list
    int size() const;

    // resizes the underlying array to a new capacity
    void resize();

    // checks if the list is empty
    bool isEmpty() const;

    // returns an element from a position
    //throws exception if the position is not valid
    TElem getElement(int pos) const;

    // modifies an element from a given position
	//returns the old value from the position
    //throws an exception if the position is not valid
    TElem setElement(int pos, TElem newElem); // why Clang-Tidy suggest me to make function const?

    // adds an element to the end of the list
    void addToEnd(TElem newElem);

    // adds an element to a given position
    //throws an exception if the position is not valid
    void addToPosition(int pos, TElem newElem);

    // removes an element from a given position
	// returns the removed element
    // throws an exception if the position is not valid
    TElem remove(int pos);

    // searches for an element and returns the first position where the element appears or -1 if the element is not in the list
    int search(TElem elemSearched)  const;

    // returns an iterator set to the first element of the list or invalid if the list is empty
    ListIterator iterator() const;

    //destructor
    ~IndexedList();


    /// extra function
    // returns the last index of a given element
    // if the element is not in the list, returns -1
    int lastIndexOf(TElem elemSearched) const;
};
