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
LinkedList<T>* BubbleSort<T>::sort_list(LinkedList<T>* list) {
    
    T temp;
    int os;
    int len = list->getLength();

    for (int i=0; i < len-2; i++) {
        for (int j=0; j <= len-3; j++) { //can enhance by ending second loop at len-i-3 vs len-2
            comparisons++;
            if (list->getEntry(j) > list->getEntry(j+1)) {
                swaps++;
                temp = list->getEntry(j);
                list->insert(j, list->getEntry(j+1));
                list->remove(j+1);
                list->insert(j+1, temp);
                list->remove(j+2);
            }
        }
        if (os == swaps) { //sorted
            break;
        } else {
            os = swaps;
        }
    }
    return list;
}