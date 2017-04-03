#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};
ListNode *prepend(int data, ListNode *head){
	ListNode *new_node = new ListNode(data);
	new_node->next = head;
	head = new_node;
	return head;
}

void print_list(ListNode *head){
	ListNode *current = head;
	while(current != NULL){
		cout << current->val << endl;
		current = current->next;
	}
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
	ListNode *iter1 = l1;
	ListNode *iter2 = l2;
	ListNode *result = new ListNode(0);
	ListNode *iter = result;
	while(iter1 && iter2){
		ListNode *new_node;
		if(iter1->val < iter2->val){
			new_node = new ListNode(iter1->val);
			iter1 = iter1->next;
		}
		else{
			new_node = new ListNode(iter2->val);
			iter2 = iter2->next;
		}
		iter->next = new_node;
		iter = new_node;
	}
	while(iter1){
		ListNode *new_node = new ListNode(iter1->val);
		iter->next = new_node;
		iter = new_node;
		iter1 = iter1->next;
	}
	while(iter2){
		ListNode *new_node = new ListNode(iter2->val);
		iter->next = new_node;
		iter = new_node;
		iter2 = iter2->next;
	}
	return result->next;
}
int main(){
	ListNode *head = new ListNode(4);
	head = prepend(3,head);
	head = prepend(2,head);
	head = prepend(1, head);
	ListNode *head2 = new ListNode(98);
	head2 = prepend(97,head2);
	head2 = prepend(9,head2);
	head2 = prepend(0, head2);
	ListNode *l = mergeTwoLists(NULL, head2);
	
	print_list(l);
	
	return 0;
}
