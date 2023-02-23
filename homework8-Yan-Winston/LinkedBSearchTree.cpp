#include "LinkedBSearchTree.h"


template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::placeNode(LinkedBTreeNode<ItemType>* subTreePtr, LinkedBTreeNode<ItemType>* newNodePtr){
  if (subTreePtr == nullptr){
    return newNodePtr;
  }
  else if(subTreePtr->getItem() > newNodePtr->getItem()){
    LinkedBTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
    subTreePtr->setLeftChildPtr(tempPtr);
  }
  else if(subTreePtr->getItem() < newNodePtr->getItem()){
    LinkedBTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
    subTreePtr->setRightChildPtr(tempPtr);
  } 
  return subTreePtr;
}
template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeValue(LinkedBTreeNode<ItemType>* subTreePtr, const ItemType& target, bool& isSuccessful) {
    if (subTreePtr->getItem() == target) {
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;
        return subTreePtr;
    } else if (subTreePtr->getItem() < target) {
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful));
        return subTreePtr;
    } else {
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful));
        return subTreePtr;
    }
}
template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeNode(LinkedBTreeNode<ItemType>* nodePtr) {
    LinkedBTreeNode<ItemType>* childNode = nodePtr->getLeftChildPtr();
    if (nodePtr->isLeaf()) {
        delete nodePtr;
        return nullptr;

    } else if (((nodePtr->getLeftChildPtr() == nullptr) && (nodePtr->getRightChildPtr() != nullptr)) || ((nodePtr->getLeftChildPtr() != nullptr) && (nodePtr->getRightChildPtr() == nullptr))) {
        if (childNode == nullptr) {
            childNode = nodePtr->getRightChildPtr();
        }
        delete nodePtr;
        return childNode;

    } else {
        LinkedBTreeNode<ItemType>* prevNode = nodePtr;
        while (childNode != nullptr) {
            prevNode = childNode;
            childNode = childNode->getLeftChildPtr();
        }
        prevNode->setRightChildPtr(nodePtr->getRightChildPtr());
        nodePtr->setRightChildPtr(nullptr);
        nodePtr->setLeftChildPtr(nullptr);
        delete nodePtr;
        return prevNode;
    }
}
template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeLeftmostNode(LinkedBTreeNode<ItemType>* nodePtr, ItemType& inorderSuccessor) {
    
    LinkedBTreeNode<ItemType>* tempPtr;
    if (nodePtr->getLeftChild() == nullptr) {
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    } else {
        tempPtr = removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
        nodePtr->setLeftChildPtr(tempPtr);
        return nodePtr;
    }
}
template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::findNode(LinkedBTreeNode<ItemType>* treePtr, const ItemType& target) const {
    if (treePtr != nullptr) {
        if (treePtr->getItem() == target) {
            return treePtr;
        } else if (treePtr->getItem() > target) {
            return findNode(treePtr->getLeftChildPtr(), target);
        } else {
            return findNode(treePtr->getRightChildPtr(), target);
        }
    }
    return nullptr;
}





template<class ItemType>
LinkedBSearchTree<ItemType>::LinkedBSearchTree() {
    numNodes = 0;
    rootPtr = nullptr;
}



template<class ItemType>
bool LinkedBSearchTree<ItemType>::isEmpty() const {
    if (rootPtr == nullptr) {
        return true;
    }
    return false;
}


template<class ItemType>
int LinkedBSearchTree<ItemType>::getHeight(LinkedBTreeNode<ItemType>* nodePtr) const {
    int lheight = 0;
    int rheight = 0;

    if (nodePtr == nullptr) {
        return 0;
    } else {
        lheight = getHeight(nodePtr->getLeftChildPtr());
        rheight = getHeight(nodePtr->getRightChildPtr());
        if (lheight > rheight) {
            return lheight + 1;
        } else {
            return rheight + 1;
        }
    }
}
template<class ItemType>
int LinkedBSearchTree<ItemType>::getHeight() const {
    return getHeight(rootPtr);
}
template<class ItemType>
int LinkedBSearchTree<ItemType>::getNumberOfNodes() const {
    return numNodes;
}
template<class ItemType>
ItemType LinkedBSearchTree<ItemType>::getRootData() const {
    return rootPtr->getItem();
}





template<class ItemType>
bool LinkedBSearchTree<ItemType>::add(const ItemType& newEntry) {

    LinkedBTreeNode<ItemType>* newNodePtr = new LinkedBTreeNode<ItemType>();
    newNodePtr->setItem(newEntry);
    rootPtr = placeNode(rootPtr, newNodePtr);
    numNodes++;
    return true;

}

template<class ItemType>
bool LinkedBSearchTree<ItemType>::remove(const ItemType& anEntry) {
    bool worked = false;
    removeValue(rootPtr, anEntry, worked);
    numNodes--;
    return worked;


    /*
    LinkedBTreeNode<ItemType>* tempPtr = rootPtr;
    LinkedBTreeNode<ItemType>* prevPtr = rootPtr;
    LinkedBTreeNode<ItemType>* prevprevPtr = rootPtr;

    int i;
    bool found = false;

    while (tempPtr != nullptr) {
        prevprevPtr = prevPtr;
        prevPtr = tempPtr;
        if (anEntry > tempPtr->getItem()) {
            i = 1;
            tempPtr = tempPtr.getRightChildPtr();
        } else if (anEntry < tempPtr->getItem()) {
            i = -1;
            tempPtr = tempPtr.getLeftChildPtr();
        } else {
            found = true;
            break;
        }
    }

    if (found == true) {
        if (prevPtr->getLeftChildPtr() == nullptr) {
            if (prevPtr->getRightChildPtr() == nullptr) {
                delete prevPtr; //leaf
                numNodes--;
                return true;
            } else {
                if (i > 0) {
                    prevprevPtr->setRightChildPtr(prevPtr->getRightChildPtr());
                } else {
                    prevprevPtr->setLeftChildPtr(prevPtr->getRightChildPtr());
                }
                delete prevPtr; //1 right child
                numNodes--;
                return true;
            }
        } else {
            if (prevPtr->getRightChildPtr() == nullptr) {
                if (i > 0) {
                    prevprevPtr->setRightChildPtr(prevPtr->getLeftChildPtr());
                } else {
                    prevprevPtr->setLeftChildPtr(prevPtr->getLeftChildPtr());
                }
                delete prevPtr; //1 left child
                numNodes--;
                return true;
            } else {
                if (i > 0) {
                    prevprevPtr->setRightChildPtr(prevPtr->getLeftChildPtr());
                    prevprevPtr = prevPtr->getRightChild();
                    prevPtr = prevPtr->getLeftChild();

                    while (tempPtr != nullptr) {
                        prevPtr = tempPtr;
                        tempPtr = prevPtr->getRightChildPtr();
                    }
                    prevPtr->setRightChildPtr(prevprevPtr);                    
                } else {
                    prevprevPtr->setLeftChildPtr(prevPtr->getRightChildPtr());
                    prevprevPtr = prevPtr->getLeftChild();
                    prevPtr = prevPtr->getRightChild();

                    while (tempPtr != nullptr) {
                        prevPtr = tempPtr;
                        tempPtr = prevPtr->getLeftChildPtr();
                    }
                    prevPtr->setLeftChildPtr(prevprevPtr);
                }
                delete prevPtr; // 2 children
                numNodes--;
                return true;
            }
        }
    }

    return false;
    */
}

template<class ItemType>
void LinkedBSearchTree<ItemType>::clear() {
    delete rootPtr;
    rootPtr = nullptr;
    numNodes = 0;
}





template<class ItemType>
bool LinkedBSearchTree<ItemType>::contains(const ItemType& anEntry) const {
    if (findNode(rootPtr, anEntry) == nullptr) {
        return false;
    }
    return true;
}
template<class ItemType> 
ItemType LinkedBSearchTree<ItemType>::getEntry(const ItemType& anEntry) const {
    LinkedBTreeNode<ItemType>* found = findNode(rootPtr, anEntry);
    if (found == nullptr) {
        throw "Item Not Found";
    } else {
        return found->getItem();
    }
}





template<class ItemType>
void LinkedBSearchTree<ItemType>::preorderTraverseWrapper(void (*visit)(ItemType)) const {
    preorderTraverse(visit, rootPtr);
}
template<class ItemType>
void LinkedBSearchTree<ItemType>::preorderTraverse(void (*visit)(ItemType), LinkedBTreeNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        visit(treePtr->getItem());
        preorderTraverse(visit, treePtr->getLeftChildPtr());
        preorderTraverse(visit, treePtr->getRightChildPtr());
    }
}

template<class ItemType>
void LinkedBSearchTree<ItemType>::inorderTraverseWrapper(void (*visit)(ItemType)) const {
    LinkedBTreeNode<ItemType>* treePtr = rootPtr;
    if (treePtr != nullptr) {
        inorderTraverse(visit, treePtr->getLeftChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorderTraverse(visit, treePtr->getRightChildPtr());
    } 
}
template<class ItemType>
void LinkedBSearchTree<ItemType>::inorderTraverse(void (*visit)(ItemType), LinkedBTreeNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        inorderTraverse(visit, treePtr->getLeftChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorderTraverse(visit, treePtr->getRightChildPtr());
    } 
}

template<class ItemType>
void LinkedBSearchTree<ItemType>::postorderTraverseWrapper(void (*visit)(ItemType)) const {
    postorderTraverse(visit, rootPtr);
} 
template<class ItemType>
void LinkedBSearchTree<ItemType>::postorderTraverse(void (*visit)(ItemType), LinkedBTreeNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        postorderTraverse(visit, treePtr->getLeftChildPtr());
        postorderTraverse(visit, treePtr->getRightChildPtr());
        visit(treePtr->getItem());
    }
} 




