#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "sort_interface.h"


template <class T>
class SelectionSort : public Sort<T> {
    protected:
        int swaps;
        int comparisons;
    public:
        SelectionSort();
        ~SelectionSort() { }

        int get_swaps();
        int get_comparisons();
        void reset();

        void sort_list(int list[], int length);
};

#endif

