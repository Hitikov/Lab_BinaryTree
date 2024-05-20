#include "Tree.h"
#include <iostream>

int main() {
	int intBuff;
	int command = 1;

	Tree<double>* operTree = new Tree<double>();

	Tree<double>* bufferTree = operTree;

	do
	{
		std::cout << std::endl;

		std::cout << "Current possition value: " << bufferTree->get_data() << std::endl;
		std::cout << "Current parrent: " << bufferTree->get_parent() << std::endl;
		std::cout << "Current left subtree: " << bufferTree->get_left() << std::endl;
		std::cout << "Current right subtree: " << bufferTree->get_right() << std::endl;

		std::cout << std::endl;

		std::cout << "1. Change current value" << std::endl;
		std::cout << "2. Swap to parrent" << std::endl;
		std::cout << "3. Swap to left subtree" << std::endl;
		std::cout << "4. Swap to right subtree" << std::endl;
		std::cout << "5. Return to root" << std::endl;
		std::cout << "6. Insert left subtree" << std::endl;
		std::cout << "7. Insert right subtree" << std::endl;
		std::cout << "8. View tree" << std::endl;
		std::cout << "9. Change to balanced tree" << std::endl;
		std::cout << "10. Change to search tree" << std::endl;
		std::cout << "11. Find element with lowest value" << std::endl;
		std::cout << "12. Visual interpretation" << std::endl;
		std::cout << "0. Stop program execution" << std::endl;

		std::cout << "Choose command to execute: ";
		std::cin >> command;
		switch (command)
		{
		case 1:
			std::cout << "Enter count of values for binary tree: ";
			std::cin >> intBuff;
			bufferTree->set_data(intBuff);
			break;
		case 2:
			if (bufferTree->get_parent() != nullptr) bufferTree = bufferTree->get_parent();
			break;
		case 3:
			if (bufferTree->get_left() != nullptr) bufferTree = bufferTree->get_left();
			break;
		case 4:
			if (bufferTree->get_right() != nullptr) bufferTree = bufferTree->get_right();
			break;
		case 5:
			bufferTree = operTree;
			break;
		case 6:
			std::cout << "Enter value to insert as left subtree: ";
			std::cin >> intBuff;
			bufferTree->insert_left(intBuff);
			break;
		case 7:
			std::cout << "Enter value to insert as right subtree: ";
			std::cin >> intBuff;
			bufferTree->insert_right(intBuff);
			break;
		case 8:
			std::cout << "Direct view: ";
			operTree->view_direct();
			std::cout << std::endl;
			std::cout << "Symetric view: ";
			operTree->view_symmetric();
			std::cout << std::endl;
			std::cout << "Reverse view: ";
			operTree->view_reverse();
			std::cout << std::endl;
			break;
		case 9:
			operTree = operTree->create_balanced_tree();
			bufferTree = operTree;
			break;
		case 10:
			operTree = operTree->create_search_tree();
			bufferTree = operTree;
			break;
		case 11:
			std::cout << "Adress of element: " << operTree->find_min() << std::endl << "Element value: " << operTree->find_min()->get_data() << std::endl;
			break;
		case 12:
			operTree->print_vert();
			operTree->DrawT();
			break;
		default:
			break;
		}
	} while (command != 0);

	return 0;
}
