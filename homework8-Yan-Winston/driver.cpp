#include "linked_dictionary.cpp"


template <class KT, class VT>
void print(Entry<KT, VT> thing) {
    std::cout << thing.getKey() << " : " << thing.getValue() << std::endl;
}



int menu() {
    std::string raw = "";

    std::cout << "Pick an Option:" << std::endl << "    1) Add a contact" << std::endl << "    2) Remove a contact" << std::endl << "    3) Change a contact" << std::endl << "    4) Search for a contact" << std::endl << "    5) Print all the contacts" << std::endl << "    0) Quit" << std::endl;
    std::cin >> raw;

    return stoi(raw);
}

int main() {
    LinkedDictionary<std::string, std::string>* contacts = new LinkedDictionary<std::string, std::string>();
    bool run = true;

    //Entry<std::string, std::string>* contact = new Entry<std::string, std::string>("joe", "911");
    //Entry<std::string, std::string>* bontact = new Entry<std::string, std::string>("joe", "111");

    std::string key;
    std::string value;

    //std::cout << (*contact == *bontact);
    ///*
    while (run == true) {
        switch (menu()) {
            case 1: // add
                std::cout << "What is their name? ";
                std::cin >> key;
                std::cout << std::endl << "What is their phone number? ";
                std::cin >> value;

                contacts->add(key, value);
                break;
            case 2: // remove
                std::cout << "What is their name? ";
                std::cin >> key;
                contacts->remove(key);
                break;
            case 3: // modify
                std::cout << "What is their name? ";
                std::cin >> key;
                std::cout << std::endl << "What is their new phone number? ";
                std::cin >> value;
                contacts->getEntry(key).setValue(value);
                break;
            case 4: // search
                std::cout << "What is their name? ";
                std::cin >> key;
                std::cout << contacts->getValue(key);
                break;
            case 5: // display
                contacts->printDictionary(print);
                break;
            default:
                run = false;
                break;
        }
        std::cout << std::endl;
    }
    //*/
    
    return 0;
}