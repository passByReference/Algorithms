/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;
BinarySearchTree::BinarySearchTree() {
	// TODO: Students write code here
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
	// walk tree in post-order traversal and delete
	post_order_delete(root);
}

void BinarySearchTree::post_order_delete(Node *node) {
	// TODO: students write code here
	// (hint: use a post-order traversal to remove all nodes)
	if (node == nullptr) return;
	else{
		post_order_delete(node->left);
		post_order_delete(node->right);
		delete node;
	}
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source) {
	// use pre-order traversal to copy the tree
	root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree& BinarySearchTree::operator=
		(const BinarySearchTree &source) {
	// TODO: Students write code here
	// check for self-assignment
	if(this == &source) return *this;
	// delete current tree if it exists
	if(root){
		post_order_delete(root);
	}
	// use pre-order traversal to copy the tree
	root = pre_order_copy(source.root);
	// don't forget to "return *this"
	return *this;
}

Node * BinarySearchTree::pre_order_copy(Node *node) {
	// TODO: Students write code here
	// (hint: use a pre-order traversal to copy details from the
	// node to a new_node)
	if (node == nullptr) return nullptr;
	Node *new_node = new Node();
	
	new_node->data = node->data;
	new_node->count = node->count;
	new_node->left = pre_order_copy(node->left);
	new_node->right = pre_order_copy(node->right);
	
	return new_node;

}

int BinarySearchTree::find_min() {
	if (root == nullptr) return INT_MIN;
	return find_min(root)->data;
}

Node *BinarySearchTree::find_min(Node *node) {
	// TODO: Students write code here
	if(node->left == nullptr) {
		Node *new_node = new Node;
		new_node->data = node->data;
		new_node->count = node->count;
		new_node->left = node->left;
		new_node->right = node->right;
		return new_node;
	}
	else return find_min(node->left);
}

int BinarySearchTree::find_max() {
	// TODO: Students write code here
	if(root == nullptr) return INT_MAX;
	return find_max(root)->data;
}

Node *BinarySearchTree::find_max(Node *node) {
	// TODO: Students write code here
	if(node->right == nullptr){
		Node *new_node = new Node;
		new_node->data = node->data;
		new_node->count = node->count;
		new_node->left = node->left;
		new_node->right = node->right;
		return new_node;
	}
	else return find_max(node->right);
}

bool BinarySearchTree::contains(int value) {
	// TODO: Students write code here
	return contains(root, value);
}

bool BinarySearchTree::contains(Node *node, int value) {
	// TODO: Students write code here
	if (node == nullptr) return false;
	else if(node->data == value) return true;
	else if (value < node->data) return contains(node->left, value);
	else return contains(node->right, value);
}

void BinarySearchTree::insert(int value) {
	insert(root,nullptr,value);
}

void BinarySearchTree::insert(Node *node,Node *parent, int value) {
	// TODO: Students write code here
	if(node == nullptr){
		Node *new_node = new Node;
		new_node->data = value;
		new_node->count = 1;
		new_node->left = nullptr;
		new_node->right = nullptr;

		if(parent == nullptr) root = new_node; // wrong to do "node = new_node"
		else if(value < parent->data)
			parent->left = new_node;
		else if(value > parent->data)
			parent->right = new_node;
	}
	else if(value == node->data){
		++node->count;
	}
	else if(value < node->data){
		insert(node->left, node, value);
	}
	else if(value > node->data){
		insert(node->right, node, value);
	}
	
}

bool BinarySearchTree::remove(int value) {
	return remove(root,nullptr,value);
}
void print(Node *node, Node *parent, string msg){
	cout << msg << endl;
	if (parent) cout << "parent = " << parent->data << endl;
	else cout << "parent is NULL" << endl;
	cout << "node = " << node->data << endl;
	cout << endl;
}
bool BinarySearchTree::remove(Node *node, Node *parent, int value) {
	// TODO: Students write code here
	// (cannot be a lazy removal)
	print(node, parent, "Into remove--------");
	if(node == nullptr) return false;
	else if(value < node->data){
		return remove(node->left, node, value);
	}
	else if(value > node->data){
		return remove(node->right, node, value);
	}
	else if(value == node->data){
		print(node, parent, "Into value = node->data------");
		if (node->count > 1){
			--node->count;
			return true;
		}	
		if(node->left == nullptr && node->right == nullptr)
			delete node;
		else if(node->right && node->left == nullptr){
			if(parent == nullptr) root = node->right;
			else if(node->data < parent->data)
				parent->left = node->right;
			else parent->right = node->right;
			delete node;
		}
		else if(node->left && node->right == nullptr){
			if(parent == nullptr) root = node->left;
			else if(node->data < parent->data) 
				parent->left = node->left;
			else parent->right = node->left;
			delete node;
		}
		//two children. delete node
		else if(node->right && node->left){
			cout << "left child*: " << node->left->data << endl;
		        cout << "right child*: " << node->right->data << endl;

			Node *new_node = find_min(node->right);
			/*
			 * find_min() needs to return a new node which is a copy
			 * of the min, thus we can replace the current node
			 * with the min node. Or when we try to delete the
			 * min node later on, we may mistake the replaced
			 * current node with the min node, since they are 
			 * the same.
			 */
			cout << "new_node = " << new_node->data << endl;
			if(parent == nullptr) root = new_node;
			else if(node->data < parent->data)
				parent->left = new_node;
			else if(node->data > parent->data)
				parent->right = new_node;
			new_node->left = node->left;
			new_node->right = node->right;
			delete node;
			cout << "left child = " << new_node->left->data << endl;
			cout << "right child = " << new_node->right->data << endl;
			return remove(new_node->right, new_node, new_node->data);
		}
		return true;
	}
}

int BinarySearchTree::node_height() {
	return node_height(root);
}

int BinarySearchTree::node_height(Node *node) {
	// TODO: Students write code here
	static int height = -1;
	if(node == nullptr) return height;
	else{
		int left_height = node_height(node->left);
		int right_height = node_height(node->right);
		if(left_height > right_height)
			return 1 + left_height;
		return 1 + right_height;
	}
}

// returns the total number of nodes
int BinarySearchTree::node_count() {
	return node_count(root);
}

int BinarySearchTree::node_count(Node *node) {
	// TODO: Students write code here
	if(node == nullptr) return 0;
	else{
		return 1 + node_count(node->left) + node_count(node->right);
	}
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() {
	return count_total(root);
}

int BinarySearchTree::count_total(Node *node) {
	// TODO: Students write code here:
	if(node == nullptr) return 0;
	else{
		return node->count * node->data + count_total(node->left) + count_total(node->right);
	}
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() {
	printPretty(root, 1, 0, std::cout);
}

Node *BinarySearchTree::find_parent(Node *node,Node *child) {
	if (node == nullptr) return nullptr;

	// if either the left or right is equal to the child,
	// we have found the parent
	if (node->left==child || node->right == child) {
		return node;
	}

	// Use the binary search tree invariant to walk the tree
	if (child->data > node->data) {
		return find_parent(node->right,child);
	}
	else {
		return find_parent(node->left,child);
	}
}	

void BinarySearchTree::inorder (Node* head) {
    if (!head) return;
    inorder(head->left);
    cout << head->data << endl;
    inorder(head->right);
} 

void BinarySearchTree::preorder (Node* head) {
    if (!head) return;
    cout << head->data << endl;
    preorder(head->left);
    preorder(head->right);
}

void BinarySearchTree::postorder (Node* head) {
    if (!head) return;
    postorder(head->left);
    postorder(head->right);
    cout << head->data << endl;
}

