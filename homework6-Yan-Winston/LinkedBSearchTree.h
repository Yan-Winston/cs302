#ifndef LINKED_B_SEARCH_TREE
#define LINKED_B_SEARCH_TREE

#include "TreeInterface.h"
#include "LinkedBTreeNode.cpp"


template<class ItemType>
class LinkedBSearchTree : public TreeInterface<ItemType> {
    protected:
        int numNodes;
        LinkedBTreeNode<ItemType>* rootPtr;

        LinkedBTreeNode<ItemType>* placeNode(LinkedBTreeNode<ItemType>* subTreePtr, LinkedBTreeNode<ItemType>* newNodePtr);
        LinkedBTreeNode<ItemType>* removeValue(LinkedBTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
        LinkedBTreeNode<ItemType>* removeNode(LinkedBTreeNode<ItemType>* nodePtr);
        LinkedBTreeNode<ItemType>* removeLeftmostNode(LinkedBTreeNode<ItemType>* nodePtr, ItemType& inorderSuccessor);
        LinkedBTreeNode<ItemType>* findNode(LinkedBTreeNode<ItemType>* treePtr, const ItemType& target) const;
    
    public:
        LinkedBSearchTree();
        ~LinkedBSearchTree() { delete rootPtr; rootPtr = nullptr; }
        
        
        bool isEmpty() const;
        
        int getHeight(LinkedBTreeNode<ItemType>* nodePtr) const;
        int getHeight() const;
        int getNumberOfNodes() const;
        ItemType getRootData() const;
        
        bool add(const ItemType& newData);
        bool remove(const ItemType& data);
        void clear();
        
        bool contains(const ItemType& anEntry) const;
        ItemType getEntry(const ItemType& anEntry) const;
        
        void preorderTraverseWrapper(void (*visit)(ItemType)) const;
        void preorderTraverse(void (*visit)(ItemType), LinkedBTreeNode<ItemType>* treePtr) const;
        void inorderTraverseWrapper(void (*visit)(ItemType)) const;
        void inorderTraverse(void (*visit)(ItemType), LinkedBTreeNode<ItemType>* treePtr) const;
        void postorderTraverseWrapper(void (*visit)(ItemType)) const;
        void postorderTraverse(void (*visit)(ItemType), LinkedBTreeNode<ItemType>* treePtr) const;
};
#endif