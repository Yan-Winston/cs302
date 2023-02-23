#ifndef CARGO_H
#define CARGO_H

#include "transportee.h"

class Cargo : public Transportee {
    protected:
        int weight;

    public:
        Cargo();
        Cargo(int Id, int Weight);
        Cargo(const Cargo& copy);

        int get_weight();
        int get_id();
        std::string get_type();

        void print_info(int);
};


#endif