#ifndef NODE_H
#define NODE_H

#include <iostream>


template<class ItemType>
class Node {
        private:
            ItemType contents;
            Node<ItemType>* next;
        public:
            Node();
            Node(const ItemType& anItem);
            Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
            ~Node() { }
            
            void setItem(const ItemType& anItem);
            void setNext(Node<ItemType>* nextNodePtr);
            
            ItemType getItem() const;
            Node<ItemType>* getNext() const;
};

#endif