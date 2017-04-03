#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include<iostream>

struct ListNode{
	int data;
	ListNode *next;
	ListNode *prev;
};

class Doubly_linked_list{
	public:
		Doubly_linked_list();// constructor
		~Doubly_linked_list();// destructor
		// copy constructor
		//Doubly_linked_list(const Doubly_linked_list& source);
		// operator= overload
		//Doubly_linked_list operator =(const Doubly_linked_list& source);
		void print_list(); // prints the list
		bool is_empty() {return head == NULL;}
		int list_size();// returns the size of the list
		void make_empty();// empties the list; head should be NULL

		// inserts a node at the head
		void insert_at_head(int val);
		// inserts a node at the tail
		void insert_at_tail(int val);
		// inserts a node at an index
		void insert_at_index(int val, int index);

		// replaces the val at index
		void replace_at_index(int val, int index);
		// returns the data at index
		int data_at(int index);
		// returns true if val is in the list
		// false otherwise
		bool has_data(int val);
		// removes the data from the list
		// returns true if the data is removed
		// returns false if the data is not in the list
		bool remove(int val);
		// removes the node from the head
		// and returns the data
		int remove_from_head();
		// removes the node from the tail
		// and returns the data
		int remove_from_tail();
		// removes the node from index
		// and returns the data
		int remove_from_index(int index);
	private:
		ListNode *head;

};
#endif
