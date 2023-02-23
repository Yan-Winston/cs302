#ifndef SORT_INTERFACE_H
#define SORT_INTERFACE_H

#include <iostream>
#include <fstream>
#include "linked_list.h"

template <class T> 
class Sort {
    public:
        virtual int get_swaps()=0;
        virtual int get_comparisons()=0;
};

#endif

