#include<iostream>
#include "Doubly_linked_list.h"

using namespace std;

Doubly_linked_list::Doubly_linked_list(){
	head = NULL;
}

Doubly_linked_list::~Doubly_linked_list(){

}

void Doubly_linked_list::print_list(){
	if(is_empty())
		cout << "List is empty" << endl;
	else{
		ListNode *current = head;
		while(current != NULL){
			cout << current->data << " ,";
			current = current->next;
		}
		cout << endl;
	}
}

int Doubly_linked_list::list_size(){
	int size = 0;
	ListNode *current = head;
	while(current != NULL){
		++size;
		current = current->next;
	}
	return size;
}

void Doubly_linked_list::make_empty(){
	ListNode *current = head;
	while(current != NULL){
		head = head->next;
		delete current;// deletes the object current points to not the pointer
		current = head;
	}
	head = NULL;
}

void Doubly_linked_list::insert_at_head(int val){
	ListNode *new_node = new ListNode;
	new_node->data = val;
	new_node->next = head;
	new_node->prev = NULL;
	if (head != NULL) head->prev = new_node;// this is important
	// head->prev = new_node; // head is null. head->prev would seg fault
	head = new_node;	
}

void Doubly_linked_list::insert_at_tail(int val){
	if(head == NULL) {
		insert_at_head(val);
		return;
	}
	ListNode *new_node = new ListNode;
	new_node->data = val;
	new_node->next = NULL;
	ListNode *current = head;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = new_node;
	new_node->prev = current;
}

void Doubly_linked_list::insert_at_index(int val, int index){
	if(index == 1) insert_at_head(val);
	else{
		ListNode *current = head;
		int k = 1;
		while(current != NULL && k < index){
			current = current->next;
			++k;
		}
		if(current == NULL){
			cout << index << " is not in the list!" << endl;
			return;
		}
		ListNode *new_node = new ListNode;
		new_node->data = val;
		new_node->next = current;
		new_node->prev = current->prev;
		current->prev->next = new_node;
		current->prev = new_node;
	}
}

void Doubly_linked_list::replace_at_index(int val, int index){
	if(index == 1) head->data = val;
	else{
		ListNode *current = head;
		int k = 1;
		while(current != NULL && k <index){
			current = current->next;
			++k;
		}
		if(current == NULL){
			cout << index << " is not in the list!" << endl;
			return;
		}
		current->data = val;
	}
}

int Doubly_linked_list::data_at(int index){
	if(head == NULL) return -1;
	else{
		ListNode *current = head;
		int k = 1;
		while(current != NULL && k <index){
			current = current->next;
			++k;
		}
		if(current == NULL){
			cout << "index " << index << " has no data! " << endl;
			return -1;
		}
		return current->data;
	}
}

bool Doubly_linked_list::has_data(int val){
	ListNode *current = head;
	while(current != NULL){
		if(current->data == val)
			return true;
		current = current->next;
	}
	return false;
}

bool Doubly_linked_list::remove(int val){
	ListNode *current = head;
	if(current->data == val){
		head = head->next;
		delete current;
		return true;
	}
	while(current != NULL){
		if(current->data == val){
			current->prev->next = current->next;
			if(current->next != NULL)
				current->next->prev = current->prev;
			delete current;
			return true;
		}
		current = current->next;
	}
	return false;
}

int Doubly_linked_list::remove_from_head(){
	if(head == NULL) return -1;
	else{
		ListNode *current = head;
		int val = head->data;
		head->next->prev = NULL;
		head = head->next;
		delete current;
		return val;
	}
}

int Doubly_linked_list::remove_from_tail(){
	if(head == NULL) return -1;
	else{
		ListNode *current = head;
		while(current->next != NULL){
			current = current->next;
		}
		int val = current->data;
		current->prev->next = NULL;
		delete current;
		return val;
	}

}

int Doubly_linked_list::remove_from_index(int index){
	if(head == NULL) return -1;
	else{
		ListNode *current = head;
		int k = 1;
		while(current != NULL && k <index){
			current = current->next;
			++k;
		}
		if(current == NULL){
			cout << index << " is not in the list " << endl;
			return -1;
		}
		int val = current->data;
		current->prev->next = current->next;
		if(current->next != NULL)
			current->next->prev = current->prev;
		delete current;
		return val;

	}
}
