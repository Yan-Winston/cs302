//INTERFACE Definition for the Queue ADT. 
//Nathaniel Potter, 10-10-2022
//Homework 4 (with Winston Y.), CS 302

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>
#include <string>

template <class T> class Queue{
    public:
        virtual bool isEmpty() const = 0; //checks is empty
        virtual bool enqueue(const T&) = 0; //adds to back of queue
        virtual bool dequeue() = 0; //dequeues the front element
        virtual T peekFront() const = 0; //returns a copy of the front element
        virtual ~Queue(){ } //deconstruct
};

#endif

