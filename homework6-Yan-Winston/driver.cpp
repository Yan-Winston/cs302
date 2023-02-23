#include "LinkedBSearchTree.cpp"
#include <chrono>
#include <ctime>

#define SIZE 200



template <class ItemType>
LinkedBSearchTree<ItemType>* generateRandomTree(int length) {
    LinkedBSearchTree<ItemType>* tree = new LinkedBSearchTree<ItemType>();

    int array[SIZE];
    int temp = 0;

    srand((unsigned) time(0)*time(0)*time(0));
    temp = (rand() % length);
    
    for (int i = 0; i < SIZE; i++) {
        array[i] = i;
    }


    for (int i = 0; i < length; i++) {
        srand((unsigned) time(0)*time(0)*time(0)*SIZE+i*i*i);
        temp = (rand() % SIZE);
        while (tree->contains(array[temp])) {
            srand((unsigned) time(0)*time(0)*time(0)*SIZE+i*i*i);
            temp = (rand() % SIZE);
        }
        tree->add(array[temp]);
        if ((int) i*100/length % 10 == 0) {
            std::cout << (float) i/length*100 << "%" << std::endl;
        }
    }

    std::cout << std::endl;

    return tree;
}

void visit(int thing) {
    std::cout << thing << ", ";
}


int main() {
    LinkedBSearchTree<int>* tree = generateRandomTree<int>(100);


    std::cout << "Inorder traversal: " << std::endl;
    tree->inorderTraverseWrapper(visit);
    std::cout << std::endl << "Preorder traversal: " << std::endl;
    tree->preorderTraverseWrapper(visit);
    std::cout << std::endl << "Postorder traversal: " << std::endl;
    tree->postorderTraverseWrapper(visit);
    std::cout << std::endl << std::endl << "Height: " << tree->getHeight() << std::endl;
    std::cout << "Number of Nodes: " << tree->getNumberOfNodes() << std::endl;

    return 0;
}