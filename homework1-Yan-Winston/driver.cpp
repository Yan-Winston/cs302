#include "cargo.h"
#include "person.h"
#include "train.h"
#include "bus.h"



int menu() {
    int choice = 0;

    std::cout << "Enter a choice to begin" << std::endl;
    std::cout << "    1. Create a new transporter" << std::endl;
    std::cout << "    2. Create and load a person or cargo to a transporter" << std::endl;
    std::cout << "    3. Unload a person or cargo from a transporter" << std::endl;
    std::cout << "    4. Empty a transporter of whatever it's carrying" << std::endl;
    std::cout << "    5. Find the number of people on a bus" << std::endl;
    std::cout << "    6. Find the weight of the cargo on a train" << std::endl;
    std::cout << "    7. Move a bus or train somewhere else" << std::endl;
    std::cout << "    8. Display the details of a transporter" << std::endl;
    std::cout << "    0. Exit" << std::endl << std::endl << ">> ";
    std::cin >> choice;

    std::cout << std::endl << std::endl;
    return choice;
}

Bus makeBus(int id) {

    std::string templocation;
    std::string tempfare;

    std::cout << "Enter where you want the bus to start: ";
    std::cin >> templocation;
    std::cout << std::endl << "Enter the fare of the bus you want to create: ";
    std::cin >> tempfare;
    std::cout << std::endl;

    Bus tempBus(id, templocation, std::stoi(tempfare));
    return tempBus;
}
Train makeTrain(int id) {

    std::string templocation;
    int tempfare;

    std::cout << "Enter where you want the train to start: ";
    std::cin >> templocation;
    std::cout << std::endl;

    Train tempBus(id, templocation);
    return tempBus;
}

Person makePerson(int id) {

    std::string name;
    std::string height;

    std::cout << "Enter the new person's name: ";
    std::cin >> name;
    std::cout << std::endl << "Enter the new person's height: ";
    std::cin >> height;
    
    Person tempPerson(id, name, std::stoi(height));
    return tempPerson;
}
Cargo makeCargo(int id) {

    std::string weight;

    std::cout << "Enter the new cargo's weight: ";
    std::cin >> weight;
    
    Cargo tempCargo(id, std::stoi(weight));
    return tempCargo;
}

int select_from_b(Bus array[], int size) {
    std::cout << "Select a " << array[0].get_type() <<": " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i+1 << ")    " << array[i].get_type() << " #"<< array[i].get_id() << std::endl;
    }
    int choice = 0;
    std::cin >> choice;
    return choice;
}

int select_from_t(Train array[], int size) {
    std::cout << "Select a " << array[0].get_type() <<": " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i+1 << ")    " << array[i].get_type() << " #"<< array[i].get_id() << std::endl;
    }
    int choice = 0;
    std::cin >> choice;
    return choice;
}




int main() {

    bool run = true;
    Bus buses[MAX_CAPACITY];
    Train trains[MAX_CAPACITY];
    int busCount = 0;
    int trainCount = 0;

    std::string tempString;
    int tempChoice = 0;
    int tempChoice_2 = 0;
    
    while (run) {
        switch (menu()) {
            case 1: {//new transporter
                std::cout << "Would you like to make a new" << std::endl;
                std::cout << "    1. Bus" << std::endl;
                std::cout << "    2. Train" << std::endl;
                std::cout << ">> ";
                std::cin >> tempString;
                std::cout << std::endl;

                tempChoice = std::stoi(tempString);

                if (tempChoice == 1) {
                    buses[busCount] = makeBus(busCount+1);
                    busCount++;
                } else {
                    trains[trainCount] = makeTrain(trainCount+1);
                    trainCount++;
                }
                break;
            }
            case 2: {//new transportee
                std::cout << "Would you like to load" << std::endl;
                std::cout << "    1. A person to a bus" << std::endl;
                std::cout << "    2. Cargo to a train" << std::endl;
                std::cout << ">> ";
                std::cin >> tempString;
                std::cout << std::endl;

                tempChoice = std::stoi(tempString);

                if (tempChoice == 1) {
                    if (busCount != 0) {
                        tempChoice = select_from_b(buses, busCount);
                        buses[tempChoice-1].add_stuff(makePerson(buses[tempChoice-1].get_num_of_stuff()+1));
                    } else {
                        std::cout << "No buses exist to load people on." << std::endl;
                    }
                } else {
                    if (trainCount != 0) {
                        tempChoice = select_from_t(trains, trainCount);
                        trains[tempChoice-1].add_stuff(makeCargo(trains[tempChoice-1].get_num_of_stuff()+1));
                    } else {
                        std::cout << "No trains exist to load people on." << std::endl;
                    }
                }   
                break;
            }
            case 3: {//remove transportee
                std::cout << "Would you like to remove" << std::endl;
                std::cout << "    1. A person from a bus" << std::endl;
                std::cout << "    2. Cargo from a train" << std::endl;
                std::cout << ">> ";
                std::cin >> tempString;
                std::cout << std::endl;

                tempChoice = std::stoi(tempString);

                if (tempChoice == 1) {
                    tempChoice = select_from_b(buses, busCount);
                    if (buses[tempChoice-1].get_num_of_stuff() != 0) {
                        buses[tempChoice-1].remove_stuff(buses[tempChoice-1].select_transportee());
                    } else {
                        std::cout << "No passengers are on the bus." << std::endl;
                    }
                } else {
                    tempChoice = select_from_t(trains, trainCount);
                    if (trains[tempChoice-1].get_num_of_stuff() != 0) {
                        trains[tempChoice-1].remove_stuff(trains[tempChoice-1].select_transportee());
                    } else {
                        std::cout << "No passengers are on the train." << std::endl;
                    }
                }

                break;
            }
            case 4: {//Empty transport
                std::cout << "Would you like to empty" << std::endl;
                std::cout << "    1. A bus" << std::endl;
                std::cout << "    2. A train" << std::endl;
                std::cout << ">> ";
                std::cin >> tempString;


                tempChoice = std::stoi(tempString);

                if (tempChoice == 1) {
                    tempChoice = select_from_b(buses, busCount);
                    buses[tempChoice-1].empty_stuff();
                } else {
                    tempChoice = select_from_t(trains, trainCount);
                    trains[tempChoice-1].empty_stuff();
                }

                break;
            }
            case 5: {//Find #people
                tempChoice = select_from_b(buses, busCount);
                std::cout << "Bus #" << tempChoice << " makes $" << buses[tempChoice].get_revenue() << "from passenger fares." << std::endl;
                break;
            }
            case 6: {//Find weight
                tempChoice = select_from_t(trains, trainCount);
                std::cout << "Train #" << tempChoice << " has " << buses[tempChoice].get_revenue() << "lbs of cargo." << std::endl;
                break;
            }
            case 7: {//Move
                std::cout << "Would you like to move" << std::endl;
                std::cout << "    1. A bus" << std::endl;
                std::cout << "    2. A train" << std::endl;
                std::cout << ">> ";
                std::cin >> tempString;
                std::cout << std::endl;

                tempChoice = std::stoi(tempString);

                std::string destination;

                if (tempChoice == 1) {
                    tempChoice = select_from_b(buses, busCount);
                    std::cout << "Bus #" << tempChoice << " is currently at " << buses[tempChoice-1].get_location() << std::endl;
                    std::cout << "Where do you want Bus #"<< tempChoice << " to move?" << std::endl << ">> ";
                    std::cin >> destination;
                    buses[tempChoice-1].move(destination);
                    std::cout << std::endl << "Bus #" << tempChoice << " has arrived at " << destination << std::endl;
                } else {
                    tempChoice = select_from_t(trains, trainCount);
                    std::cout << "Train #" << tempChoice << " is currently at " << buses[tempChoice-1].get_location() << std::endl;
                    std::cout << "Where do you want Train #"<< tempChoice << " to move?" << std::endl << ">> ";
                    std::cin >> destination;
                    buses[tempChoice-1].move(destination);
                    std::cout << std::endl << "Train #" << tempChoice << " has arrived at " << destination << std::endl;
                }
                break;
            }
            case 8: {//Display transporter
                std::cout << "Would you like to display a " << std::endl;
                std::cout << "    1. Bus's passengers" << std::endl;
                std::cout << "    2. Train's cargo" << std::endl;
                std::cout << ">> ";
                std::cin >> tempString;
                std::cout << std::endl;
                
                tempChoice = std::stoi(tempString);
            
                if (tempChoice == 1) {
                    buses[select_from_b(buses, busCount)].t_info();
                } else {
                    trains[select_from_t(trains, trainCount)].t_info();
                }
                break;
            }
            case 0: { //Exit
                run = false;
                std::cout << "Program Ended" << std::endl << std::endl << std::endl;
                break;
            }
        
            default: {
                std::cout << "Input not understood; try again." << std::endl << std::endl;
            }
        }
        std::cout << std::endl << std::endl;
    }
}