#include "linked_list.cpp"
#include "node.cpp"



int get_choice() {
    int option;

    std::cout << "Please Select an Option: " << std::endl;
    std::cout << "    1) Add new Task" << std::endl;
    std::cout << "    2) Complete Task" << std::endl;
    std::cout << "    3) Display List" << std::endl;
    std::cout << "    4) Complete List" << std::endl;
    std::cout << "    0) Quit" << std::endl;
    std::cout << ">>";
    
    std::cin >> option;
    std::cout << std::endl << std::endl;
    return option;
}





int main() {

    bool run = true;
    int choice = 0;
    std::string tempPos; 
    std::string tempTask;

    LinkedList<std::string> tasks;

    while (run == true) {
        choice = get_choice();
        switch (choice) {
            case 1:
                std::cout << "In what position would you like to insert this task?" << std::endl;
                std::cin >> tempPos;
                std::cout << std::endl;

                std::cout << "What is your task? " << std::endl;
                std::cin >> tempTask;
                std::cout << std::endl;

                if (tasks.insert(std::stoi(tempPos), tempTask)) {
                    std::cout << "Task successfully added." << std::endl;
                } else {
                    std::cout << "Task not added; please try again." << std::endl;
                }

                break;

            case 2:
                std::cout << "What is the position of the task you would like to remove?" << std::endl;
                std::cin >> tempPos;
                std::cout << std::endl;

                if (tasks.remove(std::stoi(tempPos))) {
                    std::cout << "Task successfully removed." << std::endl;
                } else {
                    std::cout << "Task not removed; please try again." << std::endl;
                }
                break;

            case 3:
                for (int i = 1; i < tasks.getLength(); i++) {
                    std::cout << i << ") " << tasks.getEntry(i) << std::endl;;
                }
                std::cout << std::endl << std::endl;
                break;

            case 4:
                tasks.clear();
                std::cout << "Tasks have been cleared." << std::endl;
                break;

            default:
                std::cout << "Quitting." << std::endl;
                run = false;
        }
    }

    return 0;
}


