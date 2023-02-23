#ifndef ENTRY_H 
#define ENTRY_H



template <class KT, class VT>
class Entry { 
    private: 
        KT key;
        VT value;
    
    public:
        Entry();
        Entry(const KT& newKey, const VT& newValue);
        VT getValue() const;
        KT getKey() const;
        void setValue(const VT& newValue);
        void setKey(const KT& searchKey);
        bool operator==(const Entry<KT, VT>& rhs) const;
        bool operator!=(const Entry<KT, VT>& rhs) const;
        bool operator>(const Entry<KT, VT>& rhs) const; 
        bool operator<(const Entry<KT, VT>& rhs) const;
        ~Entry() { }
};


#endif