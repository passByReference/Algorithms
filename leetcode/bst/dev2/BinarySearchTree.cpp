#include "BinarySearchTree.h"
#include <algorithm>
using namespace std;
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    post_order_delete(root);
    root = nullptr;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
    root = pre_order_copy(source.root);
}

BinarySearchTree& BinarySearchTree::operator= (const BinarySearchTree &source)
{
    // check for self-assignment
    if (this == &source) return *this;
    // if root exists, delete it and replace it with source
    if (root) post_order_delete(root);
    root = pre_order_copy(source.root);
    return *this;
    
}

int BinarySearchTree::find_min()
{
    if (!root) return INT_MIN;
    else return find_min(root)->data;
}

int BinarySearchTree::find_max()
{
    if (!root) return INT_MAX;
    else return find_max(root)->data;
}

bool BinarySearchTree::contains(int value)
{
    if (!root) return false;
    else return contains(root, value);
}

void BinarySearchTree::insert(int value)
{
   return insert(root, nullptr, value); 
}
 
bool BinarySearchTree::remove(int value)
{
    return remove(root, nullptr, value);
}

Node* BinarySearchTree::find_min(Node *node)
{
    if (node == nullptr) return nullptr;
    else
    {
        if (node->left == nullptr)
        {
            Node* newNode = new Node;
            newNode->data = node->data;
            newNode->count = node->count;
            newNode->left = node->left;
            newNode->right = node->right;
            return newNode;
        }
        else return find_min(node->left);
    }
}
/* WRONG VERSION!!!!!
Node* BinarySearchTree::find_min(Node *node)
{
    if (node == nullptr) return nullptr;
    else
    {
        if (node->left) return find_min(node->left);
        else return node;
    }

}
*/

Node* BinarySearchTree::find_max(Node *node)
{
    if (node)
    {
        if (node->right) return find_max(node->right);
        else return node;
    }
    return nullptr;
}

bool BinarySearchTree::contains(Node *node, int value)
{
    if (node)
    {
        if (node->data == value) return true;
        else if (value < node->data) return contains(node->left, value);
        else if (value > node->data) return contains(node->right, value);
    }
    return false;
}

int BinarySearchTree::node_height(Node *node)
{
    if (node)
    {
        return std::max(1 + node_height(node->left), 1 + node_height(node->right));
    }
    return -1;
}

void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
    if (node)
    {
        if (node->data == value)
        {
            ++node->count;
        }
        else if (value < node->data)
        {
            insert(node->left, node, value);
        }
        else if (value > node->data)
        {
            insert(node->right, node, value);
        }
    }
    else
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->count = 1;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if (!parent)
        {
            root = newNode;
        }
        else
        {
            if (value < parent->data)
            {
                parent->left = newNode;
            }
            else
            {
                parent->right = newNode;
            }
        }

    }

}

bool BinarySearchTree::remove(Node *node, Node *parent, int value) {
	// TODO: Students write code here
	// (cannot be a lazy removal)
    cout << "In remove node = " << node->data << endl;
	if(node == nullptr) return false;
	else if(value < node->data){
		return remove(node->left, node, value);
	}
	else if(value > node->data){
		return remove(node->right, node, value);
	}
	else if(value == node->data){
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
            cout << "node = " << node->data << endl;
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
             *
             * if find_min() returns a pointer to the min node instead of a copy,
             * the min node will have node->left as its left child and node->right 
             * its right child. Therefore, when the recursive remove() is called
             * to remove the min node, it will go back to its upper level, which 
             * would probably cause unexpected behavior.
			 */
			cout << "new_node = " << new_node->data << endl;
            cout << "parent = " << parent->data << endl;
			if(parent == nullptr) root = new_node;
			else if(node->data < parent->data)
				parent->left = new_node;
			else if(node->data > parent->data)
				parent->right = new_node;
			new_node->left = node->left;
			new_node->right = node->right;
			delete node;
			cout << "new node left child = " << new_node->left->data << endl;
			cout << "new node right child = " << new_node->right->data << endl;
			return remove(new_node->right, new_node, new_node->data);
		}
		return true;
	}
}
/*
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
    if (node == nullptr) return false;
    else if (value < node->data) return remove(node->left, node, value);
    else if (value > node->data) return remove(node->right, node, value);
    else if (value == node->data)
    {
        if (node->count > 1)
        {
            --node->count;
            return true;
        }
        if (node->left == nullptr && node->right == nullptr) delete node;
        else if (node->left && node->right == nullptr)
        {
            if (parent == nullptr) root = node->left;
            else if (value < parent->data) parent->left = node->left;
            else parent->right = node->right;
            delete node;
        }
        else if (node->right && node->left == nullptr)
        {
            if (parent == nullptr) root = node->right;
            else if (value < parent->data) parent->left = node->right;
            else parent->left = node->right;
            delete node;
        }
        else if (node->left && node->right)
        {
            std::cout << "I'm here" << std::endl;
            Node *newNode = find_min(node->right);
            newNode->left = node->left;
            newNode->right = node->right;

            if (parent == nullptr) root = newNode;
            else if (value < parent->data) parent->left = newNode;
            else if (value > parent->data) parent->right = newNode;
            
            delete node;
            return remove(newNode->right, newNode, newNode->data);
        }
        return true;
    }
}
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
    if (!node) return false;
    else if (value < node->data)
    {
        return remove(node->left, node, value);
    }
    else if (value > node->data)
    {
        return remove(node->right, node, value);
    }
    else if (value == node->data)
    {
        if (node->count > 1)  --node->count;
        else if (!node->left && !node->right)
        {
            delete node;
            node = nullptr;
        }
        else if (node->left && node->right)
        {
            node->data = find_min(node)->data;
            return remove(node->left, node, node->data) ||
                   remove(node->right, node, node->data);
        }
        else
        {
            if (parent)
            {
                if (value > parent->data)
                {
                    if (node->left)
                    {
                        parent->right = node->left;
                    }
                    else
                    {
                        parent->right = node->right;
                    }
                }
                else
                {
                    if (node->left)
                    {
                        parent->left = node->left;
                    }
                    else
                    {
                        parent->left = node->left;
                    }
                }
            }
            else
            {
                if (node->left) root = node->left;
                else root = node->right;
            }
            delete node;
            node = nullptr;
        }
        return true;
    }
    return true;
}
*/

int BinarySearchTree::node_count()
{
    return node_count(root);
}

int BinarySearchTree::node_count(Node *node)
{
    if (node == nullptr) return 0;
    else return 1 + node_count(node->left) + node_count(node->right);
}

int BinarySearchTree::count_total()
{
    return count_total(root);
}

int BinarySearchTree::count_total(Node *node)
{
    if (node == nullptr) return 0;
    else return node->count * node->data + count_total(node->left) + count_total(node->right);
}

int BinarySearchTree::node_height()
{
    return node_height(root);
}

void BinarySearchTree::print_tree()
{
    printPretty(root, 1, 0, std::cout);
}
Node* BinarySearchTree::pre_order_copy(Node* node)
{
    if (!node) return nullptr;
    Node* newNode = new Node();
    newNode->data = node->data;
    newNode->count = node->count;
    newNode->left = pre_order_copy(node->left);
    newNode->right = pre_order_copy(node->right);
    return newNode;
}

void BinarySearchTree::post_order_delete(Node* node)
{
    if (!node) return;
    post_order_delete(node->left);
    post_order_delete(node->right);
    delete node;
}

void BinarySearchTree::levelorder()
{
    if (root == nullptr) return;
    queue<Node*> toVisit;
    toVisit.push(root);

    while(!toVisit.empty())
    {
        auto curr_node = toVisit.front();
        toVisit.pop();
        cout << curr_node->data << endl;

        if (curr_node->left) toVisit.push(curr_node->left);
        if (curr_node->right) toVisit.push(curr_node->right);
    }
}
