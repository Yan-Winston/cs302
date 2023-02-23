#ifndef PERSON_H
#define PERSON_H

#include "transportee.h"

class Person : public Transportee {
    protected:
        std::string name;
        int height;

    public:
        Person();
        Person(int Id, std::string Name, int Weight);
        Person(const Person& copy);

        std::string get_name();
        int get_height();

        int get_id();
        std::string get_type();

        void print_info(int);
};

#endif