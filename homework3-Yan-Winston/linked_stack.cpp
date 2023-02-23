#include "linked_stack.h"

template<class ItemType>
Linked_Stack<ItemType>::Linked_Stack() {
    headPtr = nullptr;
    itemCount = 0;
}

template<class ItemType>
bool Linked_Stack<ItemType>::isEmpty() {
    if (itemCount == 0) {
        return true;
    }
    return false;
}

template<class ItemType>
bool Linked_Stack<ItemType>::push(const ItemType item) {
    try {
        Node<ItemType>* temp = new Node<ItemType>(item);
        temp->setNext(headPtr);
        headPtr = temp;
        itemCount++;
        return true;
    } catch (...) {
        return false;
    }
}
template<class ItemType>
bool Linked_Stack<ItemType>::pop() {
    if (itemCount > 0) {
        Node<ItemType>* temp;
        temp = headPtr;
        headPtr = headPtr->getNext();
        itemCount--;
        free(temp);
        return true;
    } else {
        return false;
    }
}
template<class ItemType>
bool Linked_Stack<ItemType>::clear() {
    while (headPtr != nullptr) {
        pop();
    }
    return true;
}

template<class ItemType>
ItemType Linked_Stack<ItemType>::peek() {
    return headPtr->getItem();
}

template<class ItemType>
int Linked_Stack<ItemType>::getLength() {
    return itemCount;
}