#ifndef LINKED_LIST_H
#define LINKED_LIST_H



#include "node.cpp"
#include "list_interface.h"


template<class ItemType>
class LinkedList: public ListInterface<ItemType> { 
    private: 
        Node<ItemType>* headPtr;  
        int itemCount; 
        Node<ItemType>* getNodeAt(int position) const;

    public: 
        LinkedList();
        LinkedList(const LinkedList<ItemType>& aList);
        ~LinkedList() { }
        
        bool isEmpty(); 
        int getLength(); 
        void clear(); 
        bool insert(int newPosition, const ItemType newEntry); 
        bool remove(int position);

        ItemType getEntry(int position) const; 
}; 

#endif