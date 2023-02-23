//Class Definition for the LINKED Queue Class
//Winston Yan, 10-10-2022
//CS 302, Homework 4 Group Project

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#define MAX_SIZE 128

#include "queue_interface.h"

template <class T> 
class ArrayQueue : public Queue<T>{
    private:
        int head_index;
        int length; //lengths of the contents of the circular array-based queue

        T contents[MAX_SIZE];
    public:
        ArrayQueue();

        int getLength() const;
        bool isEmpty() const; //checks is empty
        bool enqueue(const T&); //adds to back of queue
        bool dequeue(); //dequeues the first element
        T peekFront() const; //returns a copy of the front element
        
        ~ArrayQueue() { }

        ///void debug(); //debug, obviously
};

#endif