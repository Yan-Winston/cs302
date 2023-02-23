#ifndef GRAPH
#define GRAPH

#include "graph_interface.h"
#include "iostream"


template <class LabelType>
class Graph : public graph_interface<LabelType>{
    protected:
        int edges[ARRAY_SIZE][ARRAY_SIZE];
        LabelType vertices[ARRAY_SIZE];

        int numVertices;

    public:
        Graph();

        int in(int x, int y[], int size);

        int getNumVertices() const;
        int getNumEdges() const; 
        
        bool add(LabelType start, LabelType end, int edgeWeight);
        bool add(int start, int end, int edgeWeight); // indexed version
        bool remove(LabelType start, LabelType end);
        bool remove(int start, int end); // indexed version

        bool addVertice(LabelType vertice);
        bool removeVertice(LabelType vertice);
        
        int getEdgeWeight(LabelType start, LabelType end) const;
        
        void bruteForceTraveler(LabelType start); 
        int findBestPath(int previous, int current, int visited[], int numVisited);
};

#endif