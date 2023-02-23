#ifndef LIST_INTERFACE
#define LIST_INTERFACE



template<class ItemType> 
class ListInterface {
    public: 
        virtual bool isEmpty() = 0;
        virtual int getLength() = 0;
        virtual void clear() = 0;
        virtual bool insert(int newPosition, const ItemType newEntry) = 0;
        virtual bool remove(int position) = 0; 
        
        virtual ~ListInterface() { }
};


#endif