#include "bus.h"


Bus::Bus() {
    id = -1;
    location = "nowhere";
    fare = -1;
    type = "broken bus";
}
Bus::Bus(int Id, std::string Location, int Fare) {
    id = Id;
    location = Location;
    fare = Fare;
    type = "bus";
}
Bus::Bus(const Bus& copy) {
    id = copy.id;
    location = copy.location;
    fare = copy.fare;
    type = copy.type;
}

void Bus::move(std::string destination) {
    location = destination;
}


int Bus::add_stuff(Person p) {
    int temp_index = 0;
    Person temp_person;
    Person temp_person2;
    if (num_of_stuff != 0) {
        for (int i = 0; i < num_of_stuff; i++) {
            if (p.get_height() < i) {
                temp_person = stuff[i];
                stuff[i] = p;
                temp_index = i;
                break;
            }
        }
        for (int i = temp_index+1; i < num_of_stuff+1; i++) {
            temp_person2 = stuff[i];
            stuff[i] = temp_person;
            temp_person2 = temp_person;
        }
    } else {
        stuff[0] = p;
    }
    
    num_of_stuff++;
    return num_of_stuff;
}

void Bus::set_fare(int nf) {
    fare = nf;
}

int Bus::get_fare() {
    return fare;
}

int Bus::get_revenue() {
    return num_of_stuff*fare;
}

int Bus::select_transportee() {
    std::string choice;
    std::cout << "Please select a passenger: " << std::endl;
    for (int i = 0; i < num_of_stuff; i++) {
        std::cout << i+1 << ") " << stuff[i].get_name() << std::endl;
    }
    std::cin >> choice;
    return std::stoi(choice)-1;
}

int Bus::remove_stuff(int index) {
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

int Bus::empty_stuff() {
    num_of_stuff = 0;
    return num_of_stuff;
}

void Bus::t_info() {
    std::cout << "This Bus is at " << location;
    if (num_of_stuff > 0) {
        std::cout << " and these are its passengers: " << std::endl;
        for (int i=0; i < num_of_stuff; i++) {
            stuff[i].print_info(i);
        }
    } else {
        std::cout << " and it has no passengers" << std::endl;
    }
}

int Bus::get_id() {
    return id;
}

std::string Bus::get_type() {
    return type;
}
int Bus::get_num_of_stuff() {
    return num_of_stuff;
}
std::string Bus::get_location() {
    return location;
}