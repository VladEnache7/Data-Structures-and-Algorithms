#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
    this->sizeMap = 0;

    this->linkedList.head = nullptr;
    this->linkedList.tail = nullptr;
}
// Theta(1)


void MultiMap::add(TKey key, TValue value) {
    auto *newNode = new SLLNode;
    newNode->data = make_pair(key, value);
    newNode->next = nullptr;

    if (isEmpty()) {
        linkedList.head = newNode;
        linkedList.tail = newNode;
    } else {
        linkedList.tail->next = newNode;
        linkedList.tail = newNode;
    }
    sizeMap++;
}
// Theta(1)


bool MultiMap::remove(TKey key, TValue value) {
    TElem elemToBeRemoved = make_pair(key, value);
    SLLNode* currentNode = linkedList.head;
    SLLNode* previousNode = nullptr;
    while (currentNode != nullptr && currentNode->data != elemToBeRemoved){
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    // if the Element does not exist, return false
    if (currentNode == nullptr)
        return false;
    else if (previousNode == nullptr) {// then the Elem is on the first position
        linkedList.head = linkedList.head->next;
        sizeMap--;
        return true;
    }
    else{
        previousNode->next = currentNode->next;
        sizeMap--;
        return true;
    }
}
// BestCase: the Elem is the head => Theta(1) WorstCase: The Elem is the tail => Theta(sizeMap) => O(sizeMap)


vector<TValue> MultiMap::search(TKey key) const {
    vector<TValue> values{};
    SLLNode* currentNode = linkedList.head;
    while (currentNode != nullptr){
        if (currentNode->data.first == key)
            values.push_back(currentNode->data.second);
        currentNode = currentNode->next;
    }
    return values;
}


int MultiMap::size() const {
    return this->sizeMap;
}


bool MultiMap::isEmpty() const {
    return (this->sizeMap == 0);
}

MultiMapIterator MultiMap::iterator() const {
    return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
    SLLNode* currentNode = linkedList.head;
    while (currentNode != nullptr){
        SLLNode* nodeToBeDeleted = currentNode;
        currentNode = currentNode->next;
        delete nodeToBeDeleted;
    }
}

void MultiMap::filter(Condition cond) {
    SLLNode* currentNode = linkedList.head;
    SLLNode* previousNode = nullptr;
    while (currentNode != nullptr){
        if (!cond(currentNode->data.first)){
            if (previousNode == nullptr){
                linkedList.head = currentNode->next;
                SLLNode* nodeToBeDeleted = currentNode;
                currentNode = currentNode->next;
                delete nodeToBeDeleted;
                sizeMap--;
            }
            else{
                previousNode->next = currentNode->next;
                SLLNode* nodeToBeDeleted = currentNode;
                currentNode = currentNode->next;
                delete nodeToBeDeleted;
                sizeMap--;
            }
        }
        else{
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }

}

