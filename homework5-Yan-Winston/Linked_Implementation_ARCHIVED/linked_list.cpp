#include "linked_list.h"
#include <exception>



template<class ItemType>
LinkedList<ItemType>::LinkedList() {
    headPtr = nullptr;
    itemCount = 0;
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& copy) {
    headPtr = copy.headPtr;
    itemCount = copy.itemCount;
}



template<class ItemType>
bool LinkedList<ItemType>::isEmpty() {
    if (itemCount == 0) {
        return true;
    } else {
        return false;
    }
}

template<class ItemType>
int LinkedList<ItemType>::getLength() {
    return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 0) && (position <= itemCount);
    if (ableToRemove) { 
        Node<ItemType>* curPtr = nullptr;
        if (position == 0) { 
            curPtr = headPtr; 
            headPtr = headPtr->getNext(); 
        } else { 
            Node<ItemType>* prevPtr = getNodeAt(position-1); 
            curPtr= prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext()); 
        } 
        curPtr->getNext();
        delete curPtr;
        curPtr = nullptr;
        itemCount--;
    } 
    return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear() {
    headPtr = nullptr;
    itemCount = 0;
}



template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    Node<ItemType>* nodePtr = getNodeAt(position);
    return nodePtr->getItem();
}

template<class ItemType> 
Node<ItemType>* LinkedList<ItemType>:: getNodeAt(int position) const {
    
    Node<ItemType>* curPtr = headPtr;
    for (int skip=0; skip < position; skip++) { 
        curPtr = curPtr->getNext();
    }
    return curPtr;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType newEntry) {

    bool ableToInsert = (newPosition >= 0) && (newPosition <= itemCount);
    
    if (ableToInsert) { 
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

        if (newPosition == 0) { 
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr; 
   
        } else {
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        } 
        itemCount++; 
    }
    return ableToInsert;
}