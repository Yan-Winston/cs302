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
LinkedList<T>* SelectionSort<T>::sort_list(LinkedList<T>* list) {
    
    T temp[2];

    for (int edge=0; edge < list->getLength(); edge++) {
        temp[0] = list->getEntry(edge);
        for (int check=edge+1; check < list->getLength(); check++) {
            if (temp[0] > list->getEntry(check)) {
                temp[0] = list->getEntry(check);
                temp[1] = check;
            }
        }

        list->insert(edge, temp[0]);
        list->insert(temp[1]+1, list->getEntry(edge+1));
        list->remove(edge+1);
        list->remove(temp[1]+1);
    }
    

    return list;
}