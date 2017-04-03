#include<iostream>
#include<unordered_map>
#include<functional>

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

bool hasCycle(ListNode *head){
	unordered_map<int, int> dict;
	hash<ListNode*> node_hash;
	ListNode *current = head;
	while(current){
		dict[node_hash(current)] = 1;
		if(dict[node_hash(current->next)] == 1)
			return true;
		current = current->next;
	}
	return false;
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
