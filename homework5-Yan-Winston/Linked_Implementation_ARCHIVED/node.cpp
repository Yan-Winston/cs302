#include "node.h"



template<class ItemType>
Node<ItemType>::Node() {
    next = nullptr;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) {
    contents = anItem;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) {
    contents = anItem;
    next = nextNodePtr;
}



template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    contents = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    next = nextNodePtr;
}



template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return contents;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
}