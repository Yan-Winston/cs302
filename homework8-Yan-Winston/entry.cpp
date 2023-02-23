#include "entry.h"
#include "iostream"


template <class KT, class VT>
Entry<KT, VT>::Entry() {
    KT key;
    VT value;
}

template <class KT, class VT>
Entry<KT, VT>::Entry(const KT& newKey, const VT& newValue) {
    key = newKey;
    value = newValue;
}


template <class KT, class VT>
VT Entry<KT, VT>::getValue() const {
    return value;
}


template <class KT, class VT>
KT Entry<KT, VT>::getKey() const {
    return key;
}


template <class KT, class VT>
void Entry<KT, VT>::setValue(const VT& newValue) {
    value = newValue;
}


template <class KT, class VT>
void Entry<KT, VT>::setKey(const KT& searchKey) {
    key = searchKey;
}


template <class KT, class VT>
bool Entry<KT, VT>::operator==(const Entry<KT, VT>& rhs) const {
    if (key == rhs.getKey()) {
        return true;
    }
    return false;
}

template <class KT, class VT>
bool Entry<KT, VT>::operator!=(const Entry<KT, VT>& rhs) const {
    if (key != rhs.getKey()) {
        return true;
    }
    return false;
}

template <class KT, class VT>
bool Entry<KT, VT>::operator>(const Entry<KT, VT>& rhs) const {
    if (key > rhs.getKey()) {
        return true;
    }
    return false;
}

template <class KT, class VT>
bool Entry<KT, VT>::operator<(const Entry<KT, VT>& rhs) const {
    if (key < rhs.getKey()) {
        return true;
    }
    return false;
}