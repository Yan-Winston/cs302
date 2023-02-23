#include "bubble_sort.h"


template <class T>
BubbleSort<T>::BubbleSort() {
    int swaps = 0;
    int comparisons = 0;
}

template <class T>
int BubbleSort<T>::get_swaps() {
    return swaps;
}

template <class T>
int BubbleSort<T>::get_comparisons() {
    return comparisons;
}

template <class T>
void BubbleSort<T>::reset() {
    swaps = 0;
    comparisons = 0;
}

template <class T>
void BubbleSort<T>::sort_list(int list[], int len) {
    
    T temp;
    int os;

    for (int i=0; i < len-2; i++) {
        for (int j=0; j <= len-3; j++) { //can enhance by ending second loop at len-i-3 vs len-2
            comparisons++;
            if (list[j] > list[j+1]) {
                swaps++;
                temp = list[j];

                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
        if (os == swaps) { //sorted
            break;
        } else {
            os = swaps;
        }
    }
}