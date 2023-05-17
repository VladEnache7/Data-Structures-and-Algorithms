#pragma once
#include <utility>
//DO NOT INCLUDE MAPITERATOR


//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111)
class MapIterator;
 // implement a map using a hash table with open addressing and quadratic probing

#define LoadFactor 0.7

class Map {
	//DO NOT CHANGE THIS PART
	friend class MapIterator;

	private:
    struct pair {
        TKey key = NULL_TVALUE;
        TValue value = NULL_TVALUE;
        bool occupied = false;
    };

    pair* elems;
    int capacity;
    int nrElems;

    // HashFunction using the multiplication method
    // and quadratic probing
    int hash(TKey key, int iteration = 0) const;

    void resize();


	public:

	// implicit constructor
	Map();

	// adds a pair (key,newValue) to the map
	//if the key already exists in the map, then the newValue associated to the key is replaced by the new newValue and the old newValue is returned
	//if the key does not exist, a new pair is added and the newValue null is returned
	TValue add(TKey key, TValue newValue);

	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
	TValue search(TKey key) const;

	//removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
	TValue remove(TKey key);

	//returns the number of pairs (key,value) from the map
	int size() const;

	//checks whether the map is empty or not
	bool isEmpty() const;

	//returns an iterator for the map
	MapIterator iterator() const;

	// destructor
	~Map();

};



