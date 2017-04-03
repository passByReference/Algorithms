#include "RedBlackTree.h"
#include <stack>
using namespace std;

/* left_rotate
 * 1. set y
 * 2. turn y's left subtree into x's right subtree
 * 3. link x's parent to y
 * 4. put x on y's left
 * input node is x
 *
 * In Intro to Algo, steps are
 * 1) set y 2) turn y's left subtree into x's right subtree
 * 3) link x's parent to y 4) put x on y's left
 *
 * The following procedure is slightly different
 */

RedBlackTree::RedBlackTree() {
    root = nullptr;
}

RedBlackTree::~RedBlackTree() {
    post_order_delete(root);
    root = nullptr;
}

RedBlackTree::RedBlackTree(const RedBlackTree &source) {
    root = pre_order_copy(source.root, nullptr);
}

RedBlackTree& RedBlackTree::operator= (const RedBlackTree &source) {
    if (this == &source) return *this; // this is the address of current class instance
    if (root) post_order_delete(root);
    root = pre_order_copy(source.root, nullptr);
    return *this;

}
void RedBlackTree::left_rotate(Node *node_x) {
    Node* node_y = node_x->right;
    if (node_y) {
        node_x->right = node_y->left;
        if (node_y->left) node_y->left->parent = node_x;

        node_y->parent = node_x->parent;
        if (node_x->parent == nullptr) root = node_y;
        else if (node_x == node_x->parent->left) node_x->parent->left = node_y;
        else node_x->parent->right = node_y;
        node_y->left = node_x;
        node_x->parent = node_y;
    }
}

void RedBlackTree::right_rotate(Node *node_y) {
    Node* node_x = node_y->left;
    node_y->left = node_x->right;
    if (node_x->right) node_x->right->parent = node_y;
    node_x->parent = node_y->parent;
    if (node_y->parent == nullptr) root = node_x;
    else if (node_y == node_y->parent->left) node_y->parent->left = node_x;
    else node_y->parent->right = node_x;
    node_x->right = node_y;
    node_y->parent = node_x;

}

int RedBlackTree::find_min() {
    if (!root) return INT_MIN;
    return find_min(root)->data;
}

Node* RedBlackTree::find_min(Node* node) {
    if (node == NULL) return root;
    while (node->left) {
        node = node->left;
    }
    Node *newNode = new Node(node->data, node->color,
                             node->left, node->right,
                             node->parent);
    return newNode;
}

int RedBlackTree::find_max() {
    if (!root) return INT_MAX;
    return find_max(root)->data;
}

Node* RedBlackTree::find_max(Node* node) {
    if (node == NULL) return root;
    while (node->right)
    {
        node = node->right;
    }
    Node *newNode = new Node(node->data, node->color,
                             node->left, node->right,
                             node->parent);
    return newNode;
}

bool RedBlackTree::contains(int value) {
    return contains(root, value);
}

bool RedBlackTree::contains(Node* node, int value) {
    if (node == NULL) return false;
    while (node) {
        if (node->data == value) return true;
        else if (value < node->data) node = node->left;
        else if (value > node->data) node = node->right;
    }
    return false;
}

int RedBlackTree::tree_height() {
    return node_height(root);
}

int RedBlackTree::node_height(Node *node) {
    if (node == NULL) return -1;
    else {
        int left_height = node_height(node->left);
        int right_height = node_height(node->right);
        return left_height > right_height? 1 + left_height : 1 + right_height;
    }
}

void RedBlackTree::print_tree() {
    printPretty(root, 1, 0, std::cout);
}


void RedBlackTree::insert(int value) {
    cout << "insert()" << endl;
    Node* newNode = new Node(value);
    Node* node = root;
    Node* parent_node = root;
    while (node) {
        parent_node = node;
        if (value < node->data) node = node->left;
        else node = node->right;
    }

    newNode->parent = parent_node;
    if (parent_node == NULL) root = newNode;
    else if (newNode->data < parent_node->data) parent_node->left = newNode;
    else parent_node->right = newNode;
    RB_insert_fixup(newNode);
    
}

void RedBlackTree::RB_insert_fixup(Node* node){
    cout << "RB_insert_fixup" << endl;
    if (node == NULL) return;
    cout << "node->data: " << node->data << endl;
    if (node->parent){
        cout << "node->parent->data: " << node->parent->data << endl;
        cout << "node->parent->color: " << node->parent->color << endl;
    }
    while (node->parent && node->parent->color == 0) {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            // case 1
            if (uncle && uncle->color == 0) {
                cout << "case a 1" << endl;
                node->parent->color = 1;
                uncle->color = 1;
                node->parent->parent->color = 0;
                node = node->parent->parent;
                continue;
            }
            // case 2
            if (node == node->parent->right) {
                cout << "case a 2" << endl;
                node = node->parent;
                left_rotate(node);
            }
            // case 3
            cout << "case a 3" << endl;
            node->parent->color = 1;
            node->parent->parent->color = 0;
            right_rotate(node->parent->parent);
        }
        else if (node->parent && node->parent == node->parent->parent->right) {
            Node* uncle = node->parent->parent->left;
            // case 1
            if (uncle && uncle->color == 0) {
                cout << "case b 1" << endl;
                node->parent->color = 1;
                uncle->color = 1;
                node->parent->parent->color = 0;
                node = node->parent->parent;
                continue;
            }
            // case 2
            if (node == node->parent->left) {
                cout << "case b 2" << endl;
                node = node->parent;
                right_rotate(node);
            }
            //case 3
            cout << "case b 3" << endl;
            node->parent->color = 1;
            node->parent->parent->color = 0;
            left_rotate(node->parent->parent);
        }
    }
    root->color = 1;
}

Node* RedBlackTree::pre_order_copy(Node *node, Node *parent_node) {
   if (node == nullptr) return node;
   Node* newNode = new Node(node->data);
   newNode->color = node->color;
   newNode->parent = parent_node;
   newNode->left = pre_order_copy(node->left, newNode);
   newNode->right = pre_order_copy(node->right, newNode);
   return newNode;
}

int RedBlackTree::node_count() {
    auto curr_node = root;
    if (curr_node == nullptr) return 0;
    stack<Node* > toVisit;
    toVisit.push(curr_node);
    int counter = 0;
    while (!toVisit.empty()) {
        ++counter;
        curr_node = toVisit.top();
        toVisit.pop();
        if (curr_node->left) toVisit.push(curr_node->left);
        if (curr_node->right) toVisit.push(curr_node->right);
    }
    return counter;
}

int RedBlackTree::node_count(Node *node) {
    if (node == nullptr) return 0;
    return node_count(node->left) + node_count(node->right) + 1;
}

void RedBlackTree::post_order_delete(Node *node) {
    if (node == nullptr) return;
    post_order_delete(node->left);
    post_order_delete(node->right);
    delete node;
}
