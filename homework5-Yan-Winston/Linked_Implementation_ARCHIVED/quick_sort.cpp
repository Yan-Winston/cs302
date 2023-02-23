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
void QuickSort<T>::sort_list(LinkedList<T>* list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        sort_list(list, low, pi-1);
        sort_list(list, pi+1, high);
    }
}

template <class T>
int QuickSort<T>::partition(LinkedList<T>* list, int low, int high) {
    int pivot = list->getEntry(high);
    T temp;

    int i = low;
    for (int j=low; j<high; j++) {
        comparisons++;
        if (list->getEntry(j) < pivot) {
            swaps++;

            temp = list->getEntry(i);

            list->insert(i, list->getEntry(j));
            list->remove(i+1);
            
            list->insert(j, temp);
            list->remove(j+1);
            
            i++;
        }
    }

    temp = list->getEntry(i);
    
    list->insert(i, list->getEntry(high));
    list->remove(i+1);

    list->insert(high, temp);
    list->remove(high+1);

    return i;
}