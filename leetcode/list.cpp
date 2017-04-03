#include<iostream>

using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int lengthL(ListNode *head);
ListNode *removeNthFromEnd(ListNode *head, int n){
	int len = lengthL(head);
	int counter = 0;
	ListNode *iter = head;
	while(counter < len - n){
		 iter = iter->next;
		 ++counter;
	}
	cout << iter->val << endl;
	cout << "im here" << endl;
	ListNode *toDelete = iter->next;
	iter->next = iter->next->next;
	toDelete->next = NULL;
	delete toDelete;
	return head;
}

int lengthL(ListNode *head){
	int len = 0;
	ListNode *iter = head;
	while(iter != NULL){
		++len;
		iter = iter->next;
	}
	return len;
}

void printList(ListNode *head){
	ListNode *iter = head;
	while(iter != NULL){
		cout << iter->val << endl;
		iter = iter->next;
	}
}
int main(){
	ListNode *newNode = new ListNode(0);
	ListNode *newNode2 = new ListNode(1);
	ListNode *newNode3 = new ListNode(3);
	newNode2->next = newNode3;
	newNode->next = newNode2;
	ListNode *result = removeNthFromEnd(newNode, 2);
	printList(result);
	return 0;
}
