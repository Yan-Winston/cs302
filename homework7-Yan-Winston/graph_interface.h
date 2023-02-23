#ifndef GRAPH_INTERFACE
#define GRAPH_INTERFACE

#define ARRAY_SIZE 16

template <class LabelType>
class graph_interface {
    public:
        virtual int getNumVertices() const = 0;
        virtual int getNumEdges() const = 0; 
        virtual bool add(LabelType start, LabelType end, int edgeWeight) = 0;
        virtual bool remove(LabelType start, LabelType end) = 0;
        virtual int getEdgeWeight(LabelType start, LabelType end) const = 0; 
};

#endif