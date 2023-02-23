#include "graph.h"


template <class LabelType>
int Graph<LabelType>::in(int x, int y[], int size) {
    for (int i = 0; i < size; i++) {
        if (y[i] == x) {
            return true;
        }
    }
    return false;
}



template <class LabelType>
Graph<LabelType>::Graph() {
    int numVertices = 0;
    int edges[ARRAY_SIZE][ARRAY_SIZE];
    for (int i=0; i < ARRAY_SIZE; i++) {
        for (int j=0; j < ARRAY_SIZE; j++) {
            edges[i][j] = -1;
        }
    }
}



template <class LabelType>
int Graph<LabelType>::getNumVertices() const {
    return numVertices;
}

template <class LabelType>
int Graph<LabelType>::getNumEdges() const {
    int temp = 0;

    for (int i=0; i < numVertices; i++) {
        for (int j=0; j < numVertices; j++) {
            if (edges[i][j] != -1) {
                temp++;
            }
        }
    }
    
    return temp;
}



template <class LabelType>
bool Graph<LabelType>::add(LabelType start, LabelType end, int edgeWeight) {
    int index_1 = -1;
    int index_2 = -1;
    
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] == start) {
            index_1 = i;
            break;
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] == end) {
            index_2 = i;
            break;
        }
    }

    edges[index_1][index_2] = edgeWeight;
    edges[index_2][index_1] = edgeWeight;
    return true;
}

template <class LabelType>
bool Graph<LabelType>::add(int start, int end, int edgeWeight) {
    edges[start-1][end-1] = edgeWeight;
    edges[end-1][start-1] = edgeWeight;
    
    return true;
}

template <class LabelType>
bool Graph<LabelType>::remove(LabelType start, LabelType end) {
    int index_1 = -1;
    int index_2 = -1;

    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] == start) {
            index_1 = i;
            break;
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] == end) {
            index_2 = i;
            break;
        }
    }

    edges[index_1][index_2] = -1;
    return true;
}

template <class LabelType>
bool Graph<LabelType>::remove(int start, int end) {
    edges[start][end] = -1;
    edges[end][start] = -1;
    return true;
}


template <class LabelType>
bool Graph<LabelType>::addVertice(LabelType vertice) {
    vertices[numVertices] = vertice;
    numVertices++;
    return true;
}

template <class LabelType>
bool Graph<LabelType>::removeVertice(LabelType vertice) {
    int temp = -1;

    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] == vertice) {
            vertices[i] = nullptr;
            temp = i;
            break;
        }
    }

    for (int i = 0; i < numVertices; i++) {
        edges[temp][i] = -1;
        edges[i][temp] = -1;
    }

    return true;
}



template <class LabelType>
int Graph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const {
    int t1 = -1;
    int t2 = -1;

    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] == start) {
            t1 = i;
        } else if (vertices[i] == end) {
            t2 = i;
        }
    }
    
    return edges[t1][t2];
}



template <class LabelType>
void Graph<LabelType>::bruteForceTraveler(LabelType start) {

    int beginning = 0;
    int scores[numVertices];

    for (int i = 0; i < numVertices; i++) { //default the array to -1
        scores[i] = -1;
    }


    for (int i = 0; i < numVertices; i++) { //index the start
        if (vertices[i] == start) {
            beginning = i;
            break;
        }
    }

    int visited[numVertices];
    visited[0] = beginning;

    for (int i = 0; i < numVertices; i++) { //check paths of all nodes adjacent to the start
        if (edges[beginning][i] != -1 && i != beginning) {
            visited[1] = i;
            scores[i] = findBestPath(beginning, i, visited, 2);
            
        }
    }

    int lowest = INT_MAX;

    for (int i = 1; i < numVertices; i++) {
        if (scores[i] < lowest && scores[i] != -1) {
            lowest = scores[i];
        }
    }

    std::cout << "Lowest Gas Usage: " << lowest/40 << std::endl;

}

template <class LabelType>
int Graph<LabelType>::findBestPath(int previous, int current, int visited[], int numVisited) {

    int temp[numVertices];
    int toCheck[numVertices];
    int scores[numVertices];

    int connections = 0;
    int lowest;
    


    if (numVertices - numVisited != 0) {
        for (int i = 0; i < numVertices; i++) { //get connections to current vertex
            if (edges[current][i] != -1) {
                if (!in(i, visited, numVisited)) {
                    connections++;
                    toCheck[connections-1] = i;
                }
            }
        }

        for (int i = 0; i < numVertices; i++) { //default the scores array
            scores[i] = -1;
        }
    }
    

    if (connections != 0) { //if there are still possible connections
        for (int i = 0; i < numVertices; i++) {
            if (i < numVisited) {
                temp[i] = visited[i];
            } else {
                temp[i] = -1;
            }
        }

        for (int i = 0; i < connections; i++) { // for each connection
            //temp[numVisited] = toCheck[i];
            
            visited[numVisited] = toCheck[i];

            scores[i] = findBestPath(current, toCheck[i], visited, numVisited+1); //get score of all paths from starting vertex
            // ERROR IS HERE^^^^^ 
        }

        lowest = scores[0];

        for (int i = 0; i < connections; i++) { //for each connection
            if (scores[i] < lowest && scores[i] != -1) { //if it has a score that is less than 'lowest'
                lowest = scores[i]; //it becomes 'lowest'
            }
        }


        return lowest; //send back the best score

    } else {
        
        //print visited and total weight
        std::cout << "Path: ";
        for (int i = 0; i < numVisited; i++) {
            std::cout << vertices[visited[i]] << " -> ";
        }
        std::cout << vertices[visited[0]];


        int score = 0;

        for (int i = 1; i < numVisited; i++) {
            score += edges[visited[i]][visited[i-1]];
        }
        
        score += edges[current][visited[0]];

        std::cout << "   -   Gas used: " << score/40 << std::endl;

        return score; //return weight of the return to vertex 1 from current and previous to current 
        
    }
}