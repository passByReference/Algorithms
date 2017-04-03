#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};
ListNode *prepend(int data, ListNode *head){
	ListNode *new_node = new ListNode;
	new_node->val = data;
	new_node->next = head;
	head = new_node;
	return head;
}
/*
ListNode *swapPairs(ListNode *head){
	ListNode *current = head;
	ListNode *new_head;
	new_head = current->next;
	cout << head->val;
	current->next->next = current;
	current->next = current->next->next;
	while(current->next != NULL){
		current = current->next;
		current->next = current->next->next;
		current->next->next = current;
	}
	return new_head;
}*/

ListNode *swapPairs1(ListNode *head){
	ListNode *prev = new ListNode;
	prev->val = 0;
	prev->next = head;
	ListNode *iter = head;
	ListNode *new_head = head->next;
	while(iter != NULL && iter->next != NULL){
		ListNode *current = iter;
		ListNode *n = current->next;
		current->next = n->next;
		n->next = current;
		prev = current;
		iter = iter->next->next;
	}
	return new_head;
}
ListNode *swapPairs(ListNode *head){
	ListNode *prev = new ListNode;// prev is a fake node before head

	prev->val = 0;
	prev->next = head;
	ListNode *iter = prev; // iter is one node before the current node 
	ListNode *new_head = head->next;
	while(iter && iter->next && iter->next->next){
		ListNode *current = iter->next;
		ListNode *n = iter->next->next;// n is next node
		iter->next = n;
		current->next = n->next;
		n->next = current;
		iter = iter->next->next;// iter becomes current
	}
	return new_head;
}
void print_list(ListNode *head){
	ListNode *current = head;
	while(current != NULL){
		cout << current->val << endl;
		current = current->next;
	}
}
int main(){
	ListNode *head = new ListNode;
	head = NULL;
	head = prepend(4,head);
	head = prepend(3,head);
	head = prepend(2,head);
	head = prepend(1, head);
	head = swapPairs(head);
	print_list(head);
	
	return 0;
}
