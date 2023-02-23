#ifndef LINKED_BTREE_NODE 
#define LINKED_BTREE_NODE

#include <iostream>

template<class ItemType> 
class LinkedBTreeNode { 
    private: 
        ItemType item;
        LinkedBTreeNode<ItemType>* leftChildPtr;  
        LinkedBTreeNode<ItemType>* rightChildPtr; 
    public:
        LinkedBTreeNode();
        LinkedBTreeNode(const ItemType& newData, LinkedBTreeNode<ItemType>* left, LinkedBTreeNode<ItemType>* right);
        ~LinkedBTreeNode() {
            delete leftChildPtr;
            delete rightChildPtr;
        }
        
        void setItem(const ItemType& newData);
        ItemType getItem() const;
        
        bool isLeaf() const;
        
        LinkedBTreeNode<ItemType>* getLeftChildPtr() const;
        LinkedBTreeNode<ItemType>* getRightChildPtr() const;
        
        void setLeftChildPtr(LinkedBTreeNode<ItemType>* newLeftChildPtr);
        void setRightChildPtr(LinkedBTreeNode<ItemType>* newRightChildPtr);
};

#endif











