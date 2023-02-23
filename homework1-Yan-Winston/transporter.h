#ifndef TRANSPORTER_H
#define TRANSPORTER_H

#include <iostream>

#define MAX_CAPACITY 256

template <class T>
class Transporter {
    protected: 
        int id;
        std::string type;
        int num_of_stuff;
        std::string location;

        T stuff[MAX_CAPACITY];


    public:
        virtual int add_stuff(T thing)=0; // adds thing T to the transporter's array and returns the number of things in the stuff
        virtual int remove_stuff(int index)=0; //returns int num of how many things are still there after deletion
        virtual int empty_stuff()=0; //resets the stuff and also the num_of_stuff
        virtual void move(std::string destination)=0;

        virtual int get_id()=0;
        virtual std::string get_type()=0;
        virtual int get_num_of_stuff()=0;
        virtual std::string get_location()=0;

        virtual int select_transportee()=0;
        virtual void t_info()=0;
};

#endif