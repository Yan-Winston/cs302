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

#include "bubble_sort.cpp"
#include "selection_sort.cpp"
#include "quick_sort.cpp"

void reset_list(int list[], std::string filename, int length) {
    std::ifstream in;
    std::string entry;
    
    in.open(filename, std::ios::in);
    
    for (int i = 0; i<length; i++) {
        getline(in, entry);
        list[i] = std::stoi(entry);
    }
    in.close();
}

void generate_random_list(int list[], int size) {
    int temp;

    srand((unsigned) time(0));
    int swaps = (rand() % size);

    int a=2;
    int b=7;

    for (int i = 0; i < swaps; i++) {
        srand((unsigned) time(0)*a);
        a = rand() % size;
        srand((unsigned) time(0)*b);
        b = rand() % size;

        temp = list[a];
        list[a] = list[b];
        list[b] = temp;
    }
}

void save_input(int list[], std::string name, int len) {
    std::cout << "    Currently saving " << name << std::endl;
    std::ofstream out;
    out.open(name, std::ios::trunc | std::ios::out);
    for (int i=0; i<len; i++) {
        out << list[i] << std::endl;
        if (i%(len/10) == 0) {
            std::cout << "        " << 100.0*i/len << "%" << std::endl;
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

    int s_1k[1000];
    int s_10k[10000];
    int s_100k[100000];
    int us_1k[1000];
    int us_10k[10000];
    int us_100k[100000];


    BubbleSort<int> bubble_sort;
    SelectionSort<int> selection_sort;
    QuickSort<int> quick_sort;


    //generate lists
    std::cout << "Generating lists..." << std::endl;
    for (int i=0; i<100000; i++) {
        s_100k[i] = i;
        us_100k[i] = i;
        if (i < 10000) {
            s_10k[i] = i;
            us_10k[i] = i;
            if (i < 1000) {
                s_1k[i] = i;
                us_1k[i] = i;
            }
        }

        if (i%5000 == 0) {
            std::cout << "    " << (float) i/1000 << "%" << std::endl;
        }
    }

    std::cout << std::endl;

    std::cout << "Randomizing lists..." << std::endl;
    generate_random_list(us_1k, 1000);
    generate_random_list(us_10k, 10000);
    generate_random_list(us_100k, 100000);

    std::cout << "Done." << std::endl;

    //saving inputs
    std::cout << "Saving lists..." << std::endl;
    save_input(s_1k, "in_s_1k.txt", 1000);
    save_input(s_10k, "in_s_10k.txt", 10000);
    save_input(s_100k, "in_s_100k.txt", 100000);
    save_input(us_1k, "in_us_1k.txt", 1000);
    save_input(us_10k, "in_us_10k.txt", 10000);
    save_input(us_100k, "in_us_100k.txt", 100000);

    std::ofstream out;
    float timing[10];
    int comparisons[10];
    int swaps[10];



    //bubble sort 1k
    out.open("bubble_1k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(us_1k, 1000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(us_1k, "in_us_1k.txt", 1000);
        std::cout << "Run " << i+1 << " for Unsorted Bubble 1k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(s_1k, 1000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(s_1k, "in_s_1k.txt", 1000);
        std::cout << "Run " << i+1 << " for Sorted Bubble 1k completed" << std::endl;
    }
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();

    std::cout << std::endl << std::endl;

    //bubble sort 10k
    out.open("bubble_10k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(us_10k, 10000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(us_10k, "in_us_10k.txt", 10000);
        std::cout << "Run " << i+1 << " for Unsorted Bubble 10k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(s_10k, 10000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(s_10k, "in_s_10k.txt", 10000);
        std::cout << "Run " << i+1 << " for Sorted Bubble 10k completed" << std::endl;
    }
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();

    std::cout << std::endl << std::endl;

    //bubble sort 100k
    out.open("bubble_100k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(us_100k,100000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(us_100k, "in_us_100k.txt", 100000);
        std::cout << "Run " << i+1 << " for Unsorted Bubble 100k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        bubble_sort.sort_list(s_100k, 100000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = bubble_sort.get_comparisons();
        swaps[i] = bubble_sort.get_swaps();

        out << "," << delta.count() << "," << bubble_sort.get_comparisons() << "," << bubble_sort.get_swaps() << std::endl;
        bubble_sort.reset();
        
        reset_list(s_100k, "in_s_100k.txt", 100000);
        std::cout << "Run " << i+1 << " for Sorted Bubble 100k completed" << std::endl;
    }
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();

    std::cout << std::endl << std::endl;

    //selection sort 1k
    out.open("selection_1k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(us_1k, 1000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(us_1k, "in_us_1k.txt", 1000);
        std::cout << "Run " << i+1 << " for Unsorted Select 1k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(s_1k, 1000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(s_1k, "in_s_1k.txt", 1000);
        std::cout << "Run " << i+1 << " for Sorted Select 1k completed" << std::endl;
    }
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();

    std::cout << std::endl << std::endl;

    //selection sort 10k
    out.open("selection_10k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(us_10k, 10000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(us_10k, "in_us_10k.txt", 10000);
        std::cout << "Run " << i+1 << " for Unsorted Select 10k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(s_10k, 10000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(s_10k, "in_s_10k.txt", 10000);
        std::cout << "Run " << i+1 << " for Sorted Select 10k completed" << std::endl;
    }
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();

    std::cout << std::endl << std::endl;

    //selection sort 100k
    out.open("selection_100k.csv", std::ios::out | std::ios::trunc);
    out << "Unsorted,Run Time,Comparisons,Swaps"<< std::endl;
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(us_100k, 100000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(us_100k, "in_us_100k.txt", 100000);
        std::cout << "Run " << i+1 << " for Unsorted Select 100k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;

    out << std::endl << "Sorted";
    for (int i = 0; i < 10; i++) {

        auto begin = std::chrono::system_clock::now();
        selection_sort.sort_list(s_100k, 100000);
        auto end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> delta = end-begin;
        timing[i] = delta.count();
        comparisons[i] = selection_sort.get_comparisons();
        swaps[i] = selection_sort.get_swaps();

        out << "," << delta.count() << "," << selection_sort.get_comparisons() << "," << selection_sort.get_swaps() << std::endl;
        selection_sort.reset();
        
        reset_list(s_100k, "in_s_100k.txt", 100000);
        std::cout << "Run " << i+1 << " for Sorted Select 100k completed" << std::endl;
    }
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();

    std::cout << std::endl << std::endl;

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
        
        reset_list(us_1k, "in_us_1k.txt", 1000);
        std::cout << "Run " << i+1 << " for Unsorted Quick 1k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(12);
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
        
        reset_list(s_1k, "in_s_1k.txt", 1000);
        std::cout << "Run " << i+1 << " for Sorted Quick 1k completed" << std::endl;
    }
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();

    std::cout << std::endl << std::endl;

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
        
        reset_list(us_10k, "in_us_10k.txt", 10000);
        std::cout << "Run " << i+1 << " for Unsorted Quick 10k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(12);
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
        
        reset_list(s_10k, "in_s_10k.txt", 10000);
        std::cout << "Run " << i+1 << " for Sorted Quick 10k completed" << std::endl;
    }
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();

    std::cout << std::endl << std::endl;

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
        
        reset_list(us_100k, "in_us_100k.txt", 100000);
        std::cout << "Run " << i+1 << " for Unsorted Quick 100k completed" << std::endl;
    }
    std::cout << std::endl;
    out << std::setprecision(12);
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
        
        reset_list(s_100k, "in_s_100k.txt", 100000);
        std::cout << "Run " << i+1 << " for Sorted Quick 100k completed" << std::endl;
    }
    out << std::setprecision(12);
    out << "Average," << arr_average(timing) << "," << arr_average(comparisons) << "," << arr_average(swaps) << std::endl;
    out.close();


    return 0;
}