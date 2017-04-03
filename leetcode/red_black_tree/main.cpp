/*
 * main.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: chrisgregg
 */

#include <iostream>
#include "RedBlackTree.h"

using namespace std;

void print_tree_details(RedBlackTree &rbt) {
	rbt.print_tree();
	cout << "\n";
	cout << "min: " << rbt.find_min() << "\n";
	cout << "max: " << rbt.find_max() << "\n";
	cout << "nodes: " << rbt.node_count() << "\n";
	cout << "tree height: " << rbt.tree_height() << "\n";
	cout << "\n";
}

int main() {
	int values[14] = {4,2,11,15,9,1,-6,5,3,16,8,7,13,14};
	RedBlackTree rbt;
	for (int i = 0;i < 14; i++) {
		cout << "Inserting " << values[i] << " into the tree.\n";
		rbt.insert(values[i]);
        print_tree_details(rbt);
	}
	cout << "Original tree " <<
			"(asterisks denote a count of more than 1):\n";
	print_tree_details(rbt);

	// make a copy with copy constructor
	RedBlackTree rbt_copy_constructor = rbt;
	//rbt_copy_constructor.print_tree();

	// make a copy with assignment overload
	RedBlackTree rbt_copy_1;
	rbt_copy_1 = rbt;

	cout << "Removing 9 from original tree:\n";
	//rbt.remove(9); // remove a node with no children
	print_tree_details(rbt);

	rbt = rbt_copy_1;

	cout << "Removing 1 from original tree:\n";
//	rbt.remove(1); // remove a node with one child
	print_tree_details(rbt);

	rbt = rbt_copy_1;

	cout << "Removing 11 from original tree:\n";
//	rbt.remove(11); // remove a node with one child
	print_tree_details(rbt);

	rbt = rbt_copy_1;

	cout << "Removing 5 from original tree " <<
			"(should still have one 5):\n";
//	rbt.remove(5); // remove a node with one child
	print_tree_details(rbt);

	// check if the tree contains values
	rbt = rbt_copy_1;
	for (int i=-10;i<20;i++) {
		cout << "Tree " << (rbt.contains(i) ?
				"contains " :
				"does not contain ")
				<< "the value " << i << "\n";
	}

	cout << "\nFinished!\n";
	return 0;
}
