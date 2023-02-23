#include "person.h"

Person::Person() {
    id = -1;
    name = "badly inplemented person";
    height = -1;
    type = "broken person";
}
Person::Person(int Id, std::string Name, int Height) {
    id = Id;
    name = Name;
    height = Height;
    type = "person";
}
Person::Person(const Person& copy) {
    name = copy.name;
    id = copy.id;
    type = copy.type;
    height = copy.height;
}

std::string Person::get_name() {
    return name;
}
int Person::get_height() {
    return height;
}

void Person::print_info(int i) {
    std::cout << "    " << i << ") " << name << " - " << height << "cm" << std::endl;
}

int Person::get_id() {
    return id;
}
std::string Person::get_type() {
    return type;
}