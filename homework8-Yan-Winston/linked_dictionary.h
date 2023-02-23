#ifndef LINKED_DICTIONARY
#define LINKED_DICTIONARY

#include "dictionary_interface.h"
#include "entry.cpp"
#include "LinkedBSearchTree.cpp"

template<class KT, class VT>
class LinkedDictionary : public DictionaryInterface<KT, VT>{
    protected:
        LinkedBSearchTree< Entry<KT, VT> >* tree;

    public:
        LinkedDictionary();

        bool isEmpty() const; 
        int getNumberOfEntries() const;
        bool add(const KT& newKey, const VT& newValue);
        bool remove(const KT& targetKey);
        void clear();
        bool contains(const KT& targetKey) const;
        VT getValue(const KT& targetKey) const;
        Entry<KT, VT> getEntry(const KT& targetKey) const;

        void printDictionary(void (*visit)(Entry<KT, VT>)) const;
        

        ~LinkedDictionary() { tree->clear(); delete tree; }
};


#endif