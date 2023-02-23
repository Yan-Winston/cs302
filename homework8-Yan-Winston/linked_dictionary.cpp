#include "linked_dictionary.h"



template <class KT, class VT>
LinkedDictionary<KT, VT>::LinkedDictionary() {
    tree = new LinkedBSearchTree< Entry<KT, VT> >();
}


template <class KT, class VT>
bool LinkedDictionary<KT, VT>::isEmpty() const {
   return tree->isEmpty();
}

template <class KT, class VT>
int LinkedDictionary<KT, VT>::getNumberOfEntries() const {
    return tree->getNumberOfNodes();
}

template <class KT, class VT>
bool LinkedDictionary<KT, VT>::add(const KT& newKey, const VT& newValue) {
    tree->add(Entry<KT, VT>(newKey, newValue));
    return true;
}

template <class KT, class VT>
bool LinkedDictionary<KT, VT>::remove(const KT& targetKey) {
    Entry<KT, VT> temp = Entry<KT, VT>();
    temp.setKey(targetKey);
    return tree->remove(temp);
}

template <class KT, class VT>
void LinkedDictionary<KT, VT>::clear() {
    tree->clear();
}

template <class KT, class VT>
bool LinkedDictionary<KT, VT>::contains(const KT& targetKey) const {
    Entry<KT, VT> temp = Entry<KT, VT>();
    temp.setKey(targetKey);
    return tree->contains(temp);
}

template <class KT, class VT>
VT LinkedDictionary<KT, VT>::getValue(const KT& targetKey) const {
    Entry<KT, VT> temp = Entry<KT, VT>();
    temp.setKey(targetKey);
    return tree->getEntry(temp).getValue();
}

template <class KT, class VT>
Entry<KT, VT> LinkedDictionary<KT, VT>::getEntry(const KT& targetKey) const {
    Entry<KT, VT> temp = Entry<KT, VT>();
    temp.setKey(targetKey);
    return tree->getEntry(temp);
}



template<class KT, class VT>
void LinkedDictionary<KT, VT>::printDictionary(void (*visit)(Entry<KT, VT>)) const {
    tree->inorderTraverseWrapper(visit);
}