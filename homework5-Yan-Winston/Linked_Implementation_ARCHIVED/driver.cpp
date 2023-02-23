//  By: Winston Yan
//  On: Oct 24th, 2022
// For: CS 302

/*
Sorts Chosen:
    Bubble Sort
    Selection Sort
    Quick Sort
*/

#include <chrono>
#include <ctime>

#include "linked_list.cpp"

#include "bubble_sort.cpp"
#include "selection_sort.cpp"
#include "quick_sort.cpp"

void reset_list(LinkedList<int>* list, std::string filename) {
    std::ifstream in;
    std::string entry;
    int length = list->getLength();
    
    list->clear();
    in.open(filename, std::ios::in);
    
    for (int i = 0; i<length; i++) {
        getline(in, entry);
        list->insert(i, std::stoi(entry));
    }
    in.close();
}

void generate_random_list(LinkedList<int>* list) {
    
    int size = list->getLength();

    srand((unsigned) time(0));
    int swaps = (rand() % size);

    int a=2;
    int b=7;

    for (int i = 0; i < swaps; i++) {
        srand((unsigned) time(0)*a);
        a = rand() % size;
        srand((unsigned) time(0)*b);
        b = rand() % size;

        list->insert(a, list->getEntry(b));
        list->insert(b+1, list->getEntry(a+1));
        list->remove(a+1);
        list->remove(b+1);
    }
}

void save_input(LinkedList<int>* list, std::string name) {
    std::cout << "    Currently saving " << name << std::endl;
    std::ofstream out;
    out.open(name, std::ios::trunc | std::ios::out);
    for (int i=0; i<list->getLength(); i++) {
        out << list->getEntry(i) << std::endl;
        if (i%(list->getLength()/10) == 0) {
            std::cout << "        " << (float) i/(list->getLength()/100) << "%" << std::endl;
        }
    }
    out.close(); 
};

float arr_average(float arr[]) {
    float temp=0;
    for (int i = 0; i < 10; i++) {
        temp += arr[i];
    }
    temp = temp/10.0;
    return temp;
}

float arr_average(int arr[]) {
    float temp=0;
    for (int i = 0; i < 10; i++) {
        temp += (float) arr[i];
    }
    temp = temp/10.0;
    return temp;
}




int main() {

    LinkedList<int>* s_1k = new LinkedList<int>();
    LinkedList<int>* s_10k = new LinkedList<int>();
    LinkedList<int>* s_100k = new LinkedList<int>();
    LinkedList<int>* us_1k = new LinkedList<int>();
    LinkedList<int>* us_10k = new LinkedList<int>();
    LinkedList<int>* us_100k = new LinkedList<int>();


    BubbleSort<int> bubble_sort;
    SelectionSort<int> selection_sort;
    QuickSort<int> quick_sort;


    //generate lists
    std::cout << "Generating lists..." << std::endl;
    for (int i=0; i<100000; i++) {
        s_100k->insert(i, i);
        us_100k->insert(i, i);
        if (i < 10000) {
            s_10k->insert(i, i);
            us_10k->insert(i, i);
            if (i < 1000) {
                s_1k->insert(i, i);
                us_1k->insert(i, i);
            }
        }

        if (i%5000 == 0) {
            std::cout << "    " << (float) i/1000 << "%" << std::endl;
        }
    }

    std::cout << std::endl;

    std::cout << "Randomizing lists..." << std::endl;
    generate_random_list(us_1k);
    generate_random_list(us_10k);
    generate_random_list(us_100k);

    std::cout << "Done." << std::endl;

    //saving inputs
    std::cout << "Saving lists..." << std::endl;
    save_input(s_1k, "in_s_1k.txt");
    save_input(s_10k, "in_s_10k.txt");
    save_input(s_100k, "in_s_100k.txt");
    save_input(us_1k, "in_us_1k.txt");
    save_input(us_10k, "in_us_10k.txt");
    save_input(us_100k, "in_us_100k.txt");

    std::ofstream out;
    float timing[10];
    int comparisons[10];
    int swaps[10];



    //bubble sort 1k
    out.open("bubble_1k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(us_1k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(us_1k, "in_us_1k.txt");
        std::cout << "Run " << i+1 << " for Unsorted Bubble 1k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(s_1k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(s_1k, "in_s_1k.txt");
        std::cout << "Run " << i+1 << " for Sorted Bubble 1k completed" << std::endl;
    }
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();


    //bubble sort 10k
    out.open("bubble_10k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(us_10k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(us_10k, "in_us_10k.txt");
        std::cout << "Run " << i+1 << " for Unsorted Bubble 10k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(s_10k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(s_10k, "in_s_10k.txt");
        std::cout << "Run " << i+1 << " for Sorted Bubble 10k completed" << std::endl;
    }
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();


    //bubble sort 100k
    out.open("bubble_100k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(us_100k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(us_100k, "in_us_100k.txt");
        std::cout << "Run " << i+1 << " for Unsorted Bubble 100k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(s_100k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(s_100k, "in_s_100k.txt");
        std::cout << "Run " << i+1 << " for Sorted Bubble 100k completed" << std::endl;
    }
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();





    //selection sort 1k
    out.open("selection_1k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(us_1k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(us_1k, "in_us_1k.txt");
        std::cout << "Run " << i+1 << " for Unsorted Select 1k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(s_1k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(s_1k, "in_s_1k.txt");
        std::cout << "Run " << i+1 << " for Sorted Select 1k completed" << std::endl;
    }
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();


    //selection sort 10k
    out.open("selection_10k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(us_10k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(us_10k, "in_us_10k.txt");
        std::cout << "Run " << i+1 << " for Unsorted Select 10k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(s_10k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(s_10k, "in_s_10k.txt");
        std::cout << "Run " << i+1 << " for Sorted Select 10k completed" << std::endl;
    }
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();


    //selection sort 100k
    out.open("selection_100k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(us_100k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(us_100k, "in_us_100k.txt");
        std::cout << "Run " << i+1 << " for Unsorted Select 100k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(s_100k);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(s_100k, "in_s_100k.txt");
        std::cout << "Run " << i+1 << " for Sorted Select 100k completed" << std::endl;
    }
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();





    //quick sort 1k
    out.open("quick_1k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        quick_sort.sort_list(us_1k, 0, 999);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = quick_sort.get_comparisons();
        swaps[i] = quick_sort.get_swaps();

        out << "," << delta.count() << "," << quick_sort.get_comparisons() << "," << quick_sort.get_swaps() << std::endl;
        quick_sort.reset();
        
        reset_list(us_1k, "in_us_1k.txt");
        std::cout << "Run " << i+1 << " for Unsorted Quick 1k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        quick_sort.sort_list(s_1k, 0, 999);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = quick_sort.get_comparisons();
        swaps[i] = quick_sort.get_swaps();

        out << "," << delta.count() << "," << quick_sort.get_comparisons() << "," << quick_sort.get_swaps() << std::endl;
        quick_sort.reset();
        
        reset_list(s_1k, "in_s_1k.txt");
        std::cout << "Run " << i+1 << " for Sorted Quick 1k completed" << std::endl;
    }
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();


    //quick sort 10k
    out.open("quick_10k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        quick_sort.sort_list(us_10k, 0, 9999);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = quick_sort.get_comparisons();
        swaps[i] = quick_sort.get_swaps();

        out << "," << delta.count() << "," << quick_sort.get_comparisons() << "," << quick_sort.get_swaps() << std::endl;
        quick_sort.reset();
        
        reset_list(us_10k, "in_us_10k.txt");
        std::cout << "Run " << i+1 << " for Unsorted Quick 10k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        quick_sort.sort_list(s_10k, 0, 9999);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = quick_sort.get_comparisons();
        swaps[i] = quick_sort.get_swaps();

        out << "," << delta.count() << "," << quick_sort.get_comparisons() << "," << quick_sort.get_swaps() << std::endl;
        quick_sort.reset();
        
        reset_list(s_10k, "in_s_10k.txt");
        std::cout << "Run " << i+1 << " for Sorted Quick 10k completed" << std::endl;
    }
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();


    //quick sort 100k
    out.open("quick_100k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        quick_sort.sort_list(us_100k, 0, 99999);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = quick_sort.get_comparisons();
        swaps[i] = quick_sort.get_swaps();

        out << "," << delta.count() << "," << quick_sort.get_comparisons() << "," << quick_sort.get_swaps() << std::endl;
        quick_sort.reset();
        
        reset_list(us_100k, "in_us_100k.txt");
        std::cout << "Run " << i+1 << " for Unsorted Quick 100k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        quick_sort.sort_list(s_100k, 0, 99999);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = quick_sort.get_comparisons();
        swaps[i] = quick_sort.get_swaps();

        out << "," << delta.count() << "," << quick_sort.get_comparisons() << "," << quick_sort.get_swaps() << std::endl;
        quick_sort.reset();
        
        reset_list(s_100k, "in_s_100k.txt");
        std::cout << "Run " << i+1 << " for Sorted Quick 100k completed" << std::endl;
    }
    out << std::setprecision(8);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();




    return 0;
}