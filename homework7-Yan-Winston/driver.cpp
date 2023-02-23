#include "graph.cpp"
#include <fstream>

#define MPG 40
#define FILENAME "source_data.txt"

template <class LabelType>
Graph<LabelType>* createGraph(std::string filename) {
    
    std::ifstream in;
    Graph<LabelType>* graph = new Graph<LabelType>();
    
    in.open(filename, std::ios::in);

    int counter = 0;
    int tc = 0;
    int numCities = 0;

    std::string data;
    std::getline(in, data);
    while (in) {
        if (data[0] != '#') {
            switch (counter) {
                case 0:
                    assert(std::to_string(MPG) == data.substr(4, 2));
                    counter++;
                    break;
                case 1:
                    numCities = data[0] - '0';
                    counter++;
                    break;
                case 2:
                    if (tc < numCities) {
                        graph->addVertice(data);
                        tc++;
                        break;
                    } else {
                        counter++;
                    }
                case 3:
                    graph->add(data[0]-'0', data[2]-'0', std::stoi(data.substr(4)));
                    graph->add(data[2]-'0', data[0]-'0', std::stoi(data.substr(4)));
                    break;
            }
        }
        std::getline(in, data);
    }

    in.close();
    std::cout << std::endl << std::endl;

    return graph;
}




int main() {

    Graph<std::string>* graph = createGraph<std::string>("source_data.txt");

    /*
    //test data
    graph->addVertice("Reno");
    graph->addVertice("Seattle");
    graph->addVertice("Russia");
    graph->add(1, 2, 900);
    graph->add(3, 2, 2000);
    graph->add(1, 3, 2500); 
    */

    graph->bruteForceTraveler("Reno");

    return 0;
}