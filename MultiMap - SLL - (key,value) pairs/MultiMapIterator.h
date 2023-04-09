#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& multiMap;
	SLLNode* currentElement;

	//DO NOT CHANGE THIS PART
	explicit MultiMapIterator(const MultiMap& multiMapToBeSet);

public:
	TElem getCurrent()const;
	bool valid() const;
	void next();
	void first();
};

