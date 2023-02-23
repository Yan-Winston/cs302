#include "train.h"



Train::Train() {
    id = -1;
    location = "neverland";
    type = "derailed train";
}
Train::Train(int Id, std::string Location) {
    id = Id;
    location = Location;
    type = "train";
}
Train::Train(const Train& copy) {
    id = copy.id;
    location = copy.location;
    type = copy.type;
}

void Train::move(std::string destination) {
    location = destination;
}


int Train::get_weight() {
    totalWeight = 0;
    for (int i = 0; i < num_of_stuff; i++) {
        totalWeight += stuff[i].get_weight();
    }
    return totalWeight;
}

int Train::select_transportee() {
    std::string choice;
    std::cout << "Please select a piece of cargo: " << std::endl;
    for (int i = 0; i < num_of_stuff; i++) {
        std::cout << i+1 << ") " << stuff[i].get_weight() << "lbs " << std::endl;
    }
    std::cin >> choice;
    return std::stoi(choice)-1;
}

int Train::add_stuff(Cargo thing) {
    stuff[num_of_stuff] = thing;
    num_of_stuff++;
    return num_of_stuff;
}

int Train::remove_stuff(int index) {
    if (index == -1 || index == num_of_stuff-1) {
        num_of_stuff--;
        return num_of_stuff;
    } else if (index > -1 && index < num_of_stuff) {
        for (int i=index; i < num_of_stuff-2; i++) {
            stuff[i] = stuff[i+1];
        }
        num_of_stuff--;
        return num_of_stuff;
    } else {
        return -1;
    }
} 

int Train::empty_stuff() {
    num_of_stuff = 0;
    return num_of_stuff;
}

void Train::t_info() {
    std::cout << "This Train is at " << location;
    if (num_of_stuff > 0) {
        std::cout << " and these are its cargos: " << std::endl;
        for (int i=0; i < num_of_stuff; i++) {
            stuff[i].print_info(i);
        }
    } else {
        std::cout << " and it has no cargos" << std::endl;
    }
}

int Train::get_id() {
    return id;
}

std::string Train::get_type() {
    return type;
}
int Train::get_num_of_stuff() {
    return num_of_stuff;
}
std::string Train::get_location() {
    return location;
}
