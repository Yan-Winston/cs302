#include "LinkedBTreeNode.h"


template<class ItemType>
LinkedBTreeNode<ItemType>::LinkedBTreeNode() {
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}
template<class ItemType>
LinkedBTreeNode<ItemType>::LinkedBTreeNode(const ItemType& newData, LinkedBTreeNode<ItemType>* left, LinkedBTreeNode<ItemType>* right) {
    item = newData;
    leftChildPtr = left;
    rightChildPtr = right;
}



template<class ItemType>
void LinkedBTreeNode<ItemType>::setItem(const ItemType& newData) {
    item = newData;
}
template<class ItemType>
ItemType LinkedBTreeNode<ItemType>::getItem() const {
    return item;
}



template<class ItemType>
bool LinkedBTreeNode<ItemType>::isLeaf() const {
    if (leftChildPtr == nullptr && rightChildPtr == nullptr) {
        return true;
    }
    return false;
}



template<class ItemType>
void LinkedBTreeNode<ItemType>::setLeftChildPtr(LinkedBTreeNode<ItemType>* nextNodePtr) {
    leftChildPtr = nextNodePtr;
}
template<class ItemType>
void LinkedBTreeNode<ItemType>::setRightChildPtr(LinkedBTreeNode<ItemType>* nextNodePtr) {
    rightChildPtr = nextNodePtr;
}



template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBTreeNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}
template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBTreeNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}