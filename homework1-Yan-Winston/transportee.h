#ifndef TRANSPORTEE_H
#define TRANSPORTEE_H

#include <iostream>

class Transportee {
    protected: 
        int id;
        std::string type;
        
    public:
        virtual int get_id()=0;
        virtual std::string get_type()=0;

        virtual void print_info(int)=0;
};

#endif