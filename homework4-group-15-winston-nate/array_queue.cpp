//Function Definitions for the Linked Queue Class
//Winston Yan, 10-10-2022
//CS 302, Homework 4

#include "array_queue.h"


template <class T>
ArrayQueue<T>::ArrayQueue() {
    head_index = 0;
    length = -1;
}

template <class T>
int ArrayQueue<T>::getLength() const { //returns the length of the queue 
    return length;
}

template <class T>
bool ArrayQueue<T>::isEmpty() const { //checks is empty 
    if (length == -1) {
        return true;
    }
    return false;
}

template <class T>
bool ArrayQueue<T>::enqueue(const T& entry) { //adds to back of queue
    int temp = head_index + length + 1;

    length++;

    if (temp >= MAX_SIZE) {
        temp -= MAX_SIZE;
    }
    //std::cout << head_index << std::endl;
    contents[temp] = entry;
    return true;
}

template <class T>
bool ArrayQueue<T>::dequeue() { //dequeues the first element
    if (length >= 0) {
        length -= 1;
        head_index += 1;
        return true;
    }
    return false;
}

template <class T>
T ArrayQueue<T>::peekFront() const { //returns a copy of the front element
    return contents[head_index];
}

/*
template <class T>
void ArrayQueue<T>::debug() {
    for (int i=head_index; i<head_index+length; i++) {
        int temp = i;
        if (temp >= MAX_SIZE) {
            temp -= MAX_SIZE;
        }
        std::cout << contents[i+1].arrival << ' ' << contents[i+1].depart << std::endl;
    }
}
*/