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

ListNode *insertionSortList(ListNode *head){
	ListNode *i = head->next;
	while(i){
		ListNode *beg = head;
		ListNode *j = i;
		while(beg->next != j && beg->val > beg->next->val){
			int temp = beg->next->val;
			beg->next->val = beg->val;
			beg->val = temp;
			beg = beg->next;
		}
		i = i->next;
	}
	return head;
}
int main(){
	ListNode *head = new ListNode(4);
	head = prepend(3,head);
	head = prepend(2,head);
	head = prepend(1, head);
	ListNode *head2 = new ListNode(8);
	head2 = prepend(97,head2);
	head2 = prepend(9,head2);
	head2 = prepend(20, head2);
	head2 = prepend(10, head2);
	head2 = prepend(24, head2);
	head2 = prepend(45, head2);
	ListNode *l = insertionSortList(head2);
	
	print_list(l);
	
	return 0;
}
