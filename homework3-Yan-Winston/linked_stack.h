#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include "stack_interface.h"

template<class ItemType>
class Linked_Stack: public Stack_Interface<ItemType> { 
    private: 
        Node<ItemType>* headPtr;  
        int itemCount;

    public: 
        Linked_Stack();
        ~Linked_Stack() { } 

        bool isEmpty();
        bool push(const ItemType item);
        bool pop();
        bool clear();
        
        ItemType peek();

        int getLength();
}; 

#endif