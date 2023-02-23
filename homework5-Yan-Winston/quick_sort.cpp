#include "quick_sort.h"


template <class T>
QuickSort<T>::QuickSort() {
    int swaps = 0;
    int comparisons = 0;
}

template <class T>
int QuickSort<T>::get_swaps() {
    return swaps;
}

template <class T>
int QuickSort<T>::get_comparisons() {
    return comparisons;
}

template <class T>
void QuickSort<T>::reset() {
    swaps = 0;
    comparisons = 0;
}

template <class T>
void QuickSort<T>::sort_list(int list[], int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        sort_list(list, low, pi-1);
        sort_list(list, pi+1, high);
    }
}

template <class T>
int QuickSort<T>::partition(int list[], int low, int high) {
    int pivot = list[high];
    int i = low-1;

    T temp;

    for (int j=low; j<high; j++) {
        comparisons++;
        if (list[j] <= pivot) {
            swaps++;

            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
            i++;
        }
    }


    temp = list[i+1];
    list[i+1] = list[high];
    list[high] = temp;

    return i+1;
}