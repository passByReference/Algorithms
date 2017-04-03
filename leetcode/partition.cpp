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

ListNode *partition(ListNode *head, int x){
	ListNode *current = head;

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
