#include "BinarySearchTree.h"
#include <algorithm>

BinarySearchTree::BinarySearchTree()
{}

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
   insert(root, nullptr, value); 
}
 
Node* BinarySearchTree::find_min(Node *node)
{
    if (node)
    {
        if (node->left) find_min(node->left);
        else return node;
    }
    else return nullptr;

}

Node* BinarySearchTree::find_max(Node *node)
{
    if (node)
    {
        if (node->right) find_max(node->right);
        else return node;
    }
    else return nullptr;
}

bool BinarySearchTree::contains(Node *node, int value)
{
    if (node)
    {
        if (node->data == value) return true;
        else if (value < node->data) return contains(node->left, value);
        else if (value > node->data) return contains(node->right, value);
    }
    else return false;
}

int BinarySearchTree::node_height(Node *node)
{
    if (node)
    {
        return max(1 + node_height(node->left), 1 + node_height(node->right));
    }
    return 0;
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


