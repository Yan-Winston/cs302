contacts: driver.o LinkedBSearchTree.o LinkedBTreeNode.o linked_dictionary.o entry.o
	g++ -o contacts driver.o LinkedBSearchTree.o LinkedBTreeNode.o linked_dictionary.o entry.o -std=c++11

driver.o: driver.cpp linked_dictionary.cpp linked_dictionary.h LinkedBSearchTree.cpp LinkedBSearchTree.h LinkedBTreeNode.cpp LinkedBTreeNode.h entry.cpp entry.h TreeInterface.h dictionary_interface.h
	g++ -c driver.cpp 

linked_dictionary.o: linked_dictionary.cpp linked_dictionary.h LinkedBSearchTree.cpp LinkedBSearchTree.h LinkedBTreeNode.cpp LinkedBTreeNode.h entry.cpp entry.h TreeInterface.h dictionary_interface.h
	g++ -c linked_dictionary.cpp

entry.o: entry.cpp entry.h
	g++ -c entry.cpp

LinkedBSearchTree.o: LinkedBSearchTree.cpp LinkedBSearchTree.h LinkedBTreeNode.cpp LinkedBTreeNode.h TreeInterface.h
	g++ -c LinkedBSearchTree.cpp

LinkedBTreeNode.o: LinkedBTreeNode.cpp LinkedBTreeNode.h
	g++ -c LinkedBTreeNode.cpp

clear: 
	rm *.o