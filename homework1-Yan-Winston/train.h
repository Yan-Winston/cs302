#ifndef TRAIN_H
#define TRAIN_H

#include "transporter.h"
#include "cargo.h"

class Train: public Transporter<Cargo> {
    protected:
        int totalWeight;

    public:
        Train();
        Train(int Id, std::string Location);
        Train(const Train& copy);

        int get_weight(); //recalculates the total weight of the bus's cargo
        
        int select_transportee();
        int add_stuff(Cargo thing);
        int remove_stuff(int index);
        int empty_stuff();
        void t_info();
        int get_id();
        void move(std::string destination);

        std::string get_type();
        int get_num_of_stuff();
        std::string get_location();

};

#endif