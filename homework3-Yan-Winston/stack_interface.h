#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template<class ItemType>
class Stack_Interface {
    public:
        virtual bool isEmpty() = 0;
        virtual bool push(const ItemType item) = 0;
        virtual bool pop() = 0;
        virtual bool clear() = 0;

        virtual ItemType peek() = 0;
        
        virtual ~Stack_Interface() { }
};

#endif