#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);

/*
typedef struct myVector{
    int* values;
    int size;
    int capacity;

    // Constructor
    myVector(){
        values = new int[1];
        size = 0;
        capacity = 1;
    }

    // Destructor
    ~myVector(){
        delete[] values;
    }

    void add(int value){
        if(size == capacity){
            int* newArray = new int[capacity * 2];
            for(int i = 0; i < size; i++){
                newArray[i] = values[i];
            }
            delete[] values;
            values = newArray;
            capacity *= 2;
        }
        values[size] = value;
        size++;
    }

    void remove(int value){
        int index = -1;
        for(int i = 0; i < size; i++){
            if(values[i] == value){
                index = i;
                break;
            }
        }
        if(index == -1){
            return;
        }
        for(int i = index; i < size - 1; i++){
            values[i] = values[i + 1];
        }
        size--;
    }

    bool contains(int value){
        for(int i = 0; i < size; i++){
            if(values[i] == value){
                return true;
            }
        }
        return false;
    }
} myVector;
*/

typedef struct TreeNode{
    TKey key;
    std::vector<TValue> values;
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
}TreeNode;

class SortedMultiMap {
	friend class SMMIterator;
    private:
		TreeNode* root;
        Relation relation;
        int nrPairs;

    public:

    // constructor
    SortedMultiMap(Relation relation_);

	//adds a new key value pair to the sorted multi map
    void add(TKey key, TValue value);

	//returns the values belonging to a given key
    vector<TValue> search(TKey key) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();

    void deleteAllNodes(TreeNode* node);

    // extra feature
    // replaces the value oldVal from the pair (key, oldVal) with the value newVal
    // if the pair (key, oldVal) does not exist, does nothing
    void replace(TKey key, TValue oldValue, TValue newValue);
};
