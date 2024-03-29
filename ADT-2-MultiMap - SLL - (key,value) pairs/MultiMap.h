#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)
class MultiMapIterator;

typedef struct SLLNode{
    TElem data;
    SLLNode* next;
}SLLNode;

typedef struct SLL{
    SLLNode* head;
    SLLNode* tail;
}SLL;


// suplimentary requirements:
// keeps int the MultiMap only those pairs whose key respects the given condition
// void filter(Condition cond);

// where Condition is a function takes as parameter a TKey and returns a bool
// typedef bool(*Condition)(TKey);

typedef bool(*Condition)(TKey);

class MultiMap
{
	friend class MultiMapIterator;

private:
	int sizeMap;
    SLL linkedList{};

public:
	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey key, TValue value);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey key, TValue value);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey key) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//destructor
	~MultiMap();

    // for suplimentary requirements
    void filter(Condition cond);
};

