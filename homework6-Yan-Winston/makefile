trees: driver.o LinkedBSearchTree.o LinkedBTreeNode.o
	g++ -o trees driver.o LinkedBSearchTree.o LinkedBTreeNode.o -std=c++11

driver.o: driver.cpp LinkedBSearchTree.cpp LinkedBSearchTree.h LinkedBTreeNode.h TreeInterface.h
	g++ -c driver.cpp 

LinkedBSearchTree.o: LinkedBSearchTree.cpp LinkedBSearchTree.h LinkedBTreeNode.cpp LinkedBTreeNode.h TreeInterface.h
	g++ -c LinkedBSearchTree.cpp

LinkedBTreeNode.o: LinkedBTreeNode.cpp LinkedBTreeNode.h
	g++ -c LinkedBTreeNode.cpp

clear: 
	rm *.o