//Main Driver Code for Homework Assignment 4
//Nathaniel Potter and Winston Yan
//CS 302, Homework 4

#include "array_queue.cpp"

struct Customer{ 
    int arrival;
    int depart;
    int delay;
    Customer(){} //default
    Customer(int a, int d, int de){ //parameter
        arrival = a;
        depart = d;
        delay = de;
    }
}; 

template <class T> void fileToQueue(std::string fileName, ArrayQueue<T>& q){
    std::ifstream inFile(fileName);
    int arriv, dep;
    int temp = 0;
    while(!inFile.eof()){
        inFile >> arriv;
        inFile >> dep;
        if (temp >= arriv) {
            temp -= arriv;
        } else {
            temp = 0;
        }
        q.enqueue(Customer(arriv, dep+arriv+temp, dep));
        temp = arriv+dep+temp;
    }
}

bool testQueue() {
    ArrayQueue<int> q;
    
    int vals[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    for (int i = 0; i < 11; i++){
        q.enqueue(vals[i]);
    }

    std::cout << "What is first? " << q.peekFront() << std::endl;
    std::cout << "isEmpty? " << q.isEmpty() << std::endl;
    
    return true;
}


int main(){
    std::cout << "Enter file name of arrival and departure times: ";
    std::string line;
    getline(std::cin, line);

    int time = 0;
    float people = 0;
    int max_wait_time = 0;
    int wait_times = 0;

    ArrayQueue<Customer> arrivals;
    ArrayQueue<Customer> departures;
    Customer c;

    fileToQueue(line, arrivals);
    fileToQueue(line, departures);
    
    while (!departures.isEmpty()){
        c = arrivals.peekFront();
        
        if (time == c.arrival){
            std::cout << "Processing Arrival at time: " << time << '\n';
            arrivals.dequeue();
            people++;
        }

        c = departures.peekFront();

        if (time == (c.depart)) {
            std::cout << "Processing Departure at time: " << time << '\n';

            wait_times += time-c.arrival-c.delay;

            if (time - c.arrival > max_wait_time) {
                max_wait_time = time-c.arrival;
            }

            departures.dequeue();
        }

        time++;
    }
    

    std::cout << std::endl << "Average Wait Time: " << wait_times/people << std::endl;

    std::cout << std::endl << std::endl << "Extra Credit:" << std::endl;
    std::cout << " Part B:" << std::endl;
    std::cout << "    Total Steps in Simulation: " << time-1 << std::endl;
    std::cout << "    People Serviced: " << people << std::endl;
    std::cout << "    Average Time Spent at the Bank: " << (time-1)/people << std::endl;
    std::cout << "    Max Wait Time: " << max_wait_time << std::endl;

    std::cout << std::endl;

    return 0;
}