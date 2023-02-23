#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sort_interface.h"


template <class T>
class QuickSort : public Sort<T> {
    protected:
        int swaps;
        int comparisons;
    public:
        QuickSort();
        ~QuickSort() { }

        int get_swaps();
        int get_comparisons();
        void reset();

        void sort_list(int list[], int low, int high);
        int partition(int list[], int low, int high);
};

#endif

