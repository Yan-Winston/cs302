#include "selection_sort.h"


template <class T>
SelectionSort<T>::SelectionSort() {
    int swaps = 0;
    int comparisons = 0;
}

template <class T>
int SelectionSort<T>::get_swaps() {
    return swaps;
}

template <class T>
int SelectionSort<T>::get_comparisons() {
    return comparisons;
}

template <class T>
void SelectionSort<T>::reset() {
    swaps = 0;
    comparisons = 0;
}


template <class T>
void SelectionSort<T>::sort_list(int list[], int length) {
    
    int min;
    int temp;

    for (int edge=0; edge < length-1; edge++) {
        min = edge;
        for (int check=edge+1; check < length; check++) {
            comparisons++;
            if (list[min] > list[check]) {
                min = check;
            }
        }

        if (edge != min) {
            swaps++;
            temp = list[edge];
            list[edge] = list[min];
            list[min] = temp;
        }
    }
}