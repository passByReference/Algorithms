#include<iostream>
#include<vector>
#include "BinarySearchTree.h"

using namespace std;

Node* flip(Node* head){
	Node* current = head;
	if(!current) return current;
	if(current->left && current->right){
		int temp = 0;
		temp = current->left->data;
		current->left->data = current->right->data;
		current->right->data = temp;
	}
	current->left = flip(current->right);
	current->right = flip(current->left);
	return current;

}

int main(){
	BinarySearchTree bst;
	vector<int> values = {4, 2, 3, 1, 6, 5, 7, 8, 9};
	for(auto v : values){
		bst.insert(v);
	}
	bst.print_tree();
	Node* head = flip(bst.get_root()->right);
	BinarySearchTree bst2 (head);
	bst2.print_tree();
	return 0;
}
