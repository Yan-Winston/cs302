#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort_interface.h"


template <class T>
class BubbleSort : public Sort<T> {
    protected:
        int swaps;
        int comparisons;
    public:
        BubbleSort();
        ~BubbleSort() { }

        int get_swaps();
        int get_comparisons();
        void reset();

        void sort_list(int list[], int length);
};

#endif

