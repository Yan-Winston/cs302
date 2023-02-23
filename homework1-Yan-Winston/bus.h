#ifndef BUS_H
#define BUS_H

#include "transporter.h"
#include "person.h"

class Bus: public Transporter<Person> {
    protected:
        int fare;
        
    public:
        Bus();
        Bus(int Id, std::string Location, int Fare);
        Bus(const Bus& copy);

        int add_stuff(Person thing);

        void set_fare(int);

        int get_fare();
        int get_revenue();

        int select_transportee();
        int remove_stuff(int index);
        int empty_stuff();
        void t_info();
        int get_id();

        std::string get_type();
        int get_num_of_stuff();
        std::string get_location();

        void move(std::string destination);
};

#endif