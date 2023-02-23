#include "cargo.h"

Cargo::Cargo() {
weight = -1;
}
Cargo::Cargo(int Id, int Weight) {
    id = Id;
    weight = Weight;
    type = "cargo";

}
Cargo::Cargo(const Cargo& copy) {
    id = copy.id;
    weight = copy.weight;
    type = copy.type;
}

int Cargo::get_weight() {
    return weight;
}

void Cargo::print_info(int i) {
    std::cout << "    " << i << ") - " << get_weight() << " lbs" << std::endl;
}

int Cargo::get_id() {
    return id;
}
std::string Cargo::get_type() {
    return type;
}