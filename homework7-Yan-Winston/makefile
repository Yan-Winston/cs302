TravelingSalesman: driver.o graph.o
	g++ -o TravelingSalesman driver.o graph.o -std=c++11

driver.o: driver.cpp graph.cpp graph.h graph_interface.h
	g++ -c driver.cpp 

graph.o: graph.cpp graph.h graph_interface.h
	g++ -c graph.cpp

clear: 
	rm *.o