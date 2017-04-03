/*
 * RedBlackTree.h
 * 
 * Created on: Dec 6, 2016
 *
 */
#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

#include <iostream>

// Red Black Tree Node
// data is the value

struct Node {
    int data;
    int color; // 1 black, 0 red
    Node *left;
    Node *right;
    Node *parent;
    Node (int iData, int iColor, Node* iLeft, Node* iRight, Node* iParent) {
        data = iData;
        color = iColor;
        left = iLeft;
        right = iRight;
        parent = iParent;
    }
    Node (int iData) :data(iData), color(0), left(NULL), right(NULL), parent(NULL)
    {}
};

// defined in pretty_print.cpp

void printPretty(Node *root, int level, int indentSpace, std::ostream& out);
/*
 * Red-black properties:
 * 1. Every node is red or black
 * 2. The root is black
 * 3. Every leaf (NIL) is black
 * 4. If a node is red, then both its children are black
 * 5. For each node, all simple paths from the node to descendant leaves contain the
 *    same numbe of black nodes.
 *
 */

class RedBlackTree {
 public:
   // constructor
   RedBlackTree();

   // destructor
   ~RedBlackTree();

   // copy constructor
   RedBlackTree(const RedBlackTree &source);

   // assignment overload
   RedBlackTree &operator= (const RedBlackTree &source);

   int find_min();

   int find_max();

   bool contains(int value);
  
   void insert(int value);

  // bool remove(int value);

   int tree_height();

   int node_count();

   void print_tree();

   Node *getRoot() {return root;}


 private:
   Node *root;
   Node *find_min(Node *node);
   Node *find_max(Node *node);
   bool contains(Node *node, int value);
   void RB_insert_fixup(Node *node);
   int node_height(Node *node);
   void left_rotate(Node *node);
   void right_rotate(Node *node);
   int node_count(Node* node);
   Node *pre_order_copy(Node *node, Node *parent_node);
   void post_order_delete(Node *node);
};

#endif /* REDBLACKTREE_H_ */
