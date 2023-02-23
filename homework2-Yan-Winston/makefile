tasks: driver.o
	g++ -o tasks driver.o -std=c++11

driver.o: driver.cpp linked_list.cpp node.cpp
	g++ -c driver.cpp 

clear: 
	rm *.o