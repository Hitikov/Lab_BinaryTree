#include "Tree.h"
#include <iostream>

int main() {
	int intBuff;

	Tree<double>* operTree = new Tree<double>(0);
	std::cout << "Enter count of values for binary tree: ";
	std::cin >> intBuff;

	operTree = operTree->balanced(intBuff);

	operTree->DrawT();

	operTree->print_vert();

	std::cout << "Direct view: ";
	operTree->view_direct();
	std::cout << std::endl;

	operTree = operTree->create_bst_from_balanced_tree();

	operTree->insert_left(14.66);
	
	operTree->insert_left(14.66);
	
	operTree->insert_left(14.66);

	operTree->print_vert();

	operTree->DrawT();

	return 0;
}
