#pragma once
#include "IndexedList.h"


class ListIterator{
    //DO NOT CHANGE THIS PART
	friend class IndexedList;
private:
	const IndexedList& list;
	int currentIndex;
		
    explicit ListIterator(const IndexedList& list);
public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;

};

