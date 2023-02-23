sort: driver.o bubble_sort.o selection_sort.o quick_sort.o
	g++ -o sort driver.o bubble_sort.o selection_sort.o quick_sort.o -std=c++11

driver.o: driver.cpp  bubble_sort.cpp selection_sort.cpp quick_sort.cpp
	g++ -c driver.cpp 

bubble_sort.o: bubble_sort.cpp
	g++ -c bubble_sort.cpp

selection_sort.o: selection_sort.cpp
	g++ -c selection_sort.cpp

quick_sort.o: quick_sort.cpp
	g++ -c quick_sort.cpp

clear: 
	rm *.o