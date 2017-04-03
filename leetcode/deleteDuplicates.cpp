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

ListNode *deleteDuplicates(ListNode *head){
	if(head == NULL) return head;
	ListNode *current = head;
	while(current->next){
		if(current->val == current->next->val){
			current->next = current->next->next;

		}
		else{
			current = current->next;
		}
			
	}
	return head;
}

int main(){
	ListNode *head = new ListNode(4);
	head = prepend(4,head);
	head = prepend(4,head);
	//head = prepend(2,head);
	//head = prepend(1, head);
	ListNode *head2 = new ListNode(9);
	head2 = prepend(9,head2);
	head2 = prepend(9,head2);
	head2 = prepend(0, head2);
        head = deleteDuplicates(head);
	print_list(head);
	
	return 0;
}
