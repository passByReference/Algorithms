/*
 * main.cpp
 *
 */

#include <iostream>
#include <vector>
#include "BinarySearchTree.h"
#include "Singly_linked_list.h"

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
};

void print_tree_details(BinarySearchTree &bst) {
	bst.print_tree();
	cout << "\n";
	cout << "min: " << bst.find_min() << "\n";
	cout << "max: " << bst.find_max() << "\n";
	cout << "nodes: " << bst.node_count() << "\n";
	cout << "count total: " << bst.count_total() << "\n";
	cout << "tree height: " << bst.node_height() << "\n";
	cout << "\n";
}
int sumNumbers (Node* root) {
    if (!root) return 0;
    int sum = 0;
    vector<Node*> v;
    v.push_back(root);
    while (v.size() > 0) {
        Node* node = v.back();
        v.pop_back();
        if (node->left) {
            node->left->data += 10 * node->data;
            v.push_back(node->left);
        }
        if (node->right) {
            node->right->data += 10 * node->data;
            v.push_back(node->right);
        }
        if (!node->left && !node->right) {
            sum += node->data;
        }
    }
    return sum;
}
Node* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    ListNode* mid = head;
    int length = 0;
    while (mid) {
        ++length;
        mid = mid->next;
    }
    int iter = 0;
    mid = head;
    while (iter < length / 2) {
         mid = mid->next;
         ++iter;
    }

    Node* root = new Node;
    root->data = mid->val;
    root->count = 1;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);
    return root;
}
int main() {
	int dataues[14] = {4,2,11,15,9,1,-6,5,3,15,2,5,13,14};
        vector<int> v = {2,1,3};
	BinarySearchTree bst;
        for (auto i : v) bst.insert(i);
        /*
	for (int i=0;i<14;i++) {
		cout << "Inserting " << dataues[i] << " into the tree.\n";
		bst.insert(dataues[i]);
	}
        */
	cout << "Original tree " <<
			"(asterisks denote a count of more than 1):\n";
	print_tree_details(bst);

        bst.preorder(bst.getRoot());
        cout << sumNumbers(bst.getRoot()) << endl;
        ListNode* l = nullptr;
        l = prepend(l, 0);
        print_list(l);
        /*
	// make a copy with copy constructor
	BinarySearchTree bst_copy_constructor = bst;
	//bst_copy_constructor.print_tree();

	// make a copy with assignment overload
	BinarySearchTree bst_copy_1;
	bst_copy_1 = bst;

	cout << "Removing 9 from original tree:\n";
	bst.remove(9); // remove a node with no children
	print_tree_details(bst);

	bst = bst_copy_1;

	cout << "Removing 1 from original tree:\n";
	bst.remove(1); // remove a node with one child
	print_tree_details(bst);

	bst = bst_copy_1;

	cout << "Removing 11 from original tree:\n";
	bst.remove(11); // remove a node with one child
	print_tree_details(bst);

	bst = bst_copy_1;

	cout << "Removing 5 from original tree " <<
			"(should still have one 5):\n";
	bst.remove(5); // remove a node with one child
	print_tree_details(bst);

	// check if the tree contains dataues
	bst = bst_copy_1;
	for (int i=-10;i<20;i++) {
		cout << "Tree " << (bst.contains(i) ?
				"contains " :
				"does not contain ")
				<< "the dataue " << i << "\n";
	}

	cout << "\nFinished!\n";
        */
	return 0;
}
