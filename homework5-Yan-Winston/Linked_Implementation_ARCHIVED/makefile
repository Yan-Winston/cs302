sort: driver.o bubble_sort.o selection_sort.o quick_sort.o linked_list.o node.o
	g++ -o sort driver.o bubble_sort.o selection_sort.o quick_sort.o linked_list.o node.o -std=c++11

test.o: driver.cpp linked_list.cpp bubble_sort.cpp node.cpp
	g++ -c driver.cpp 

bubble_sort.o: bubble_sort.cpp node.cpp linked_list.cpp
	g++ -c bubble_sort.cpp

selection_sort.o: selection_sort.cpp node.cpp linked_list.cpp
	g++ -c selection_sort.cpp

quick_sort.o: quick_sort.cpp node.cpp linked_list.cpp
	g++ -c quick_sort.cpp

linked_list.o: linked_list.cpp node.cpp
	g++ -c linked_list.cpp

node.o: node.cpp 
	g++ -c node.cpp
	
clear: 
	rm *.o