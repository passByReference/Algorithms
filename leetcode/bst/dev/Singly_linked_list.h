#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
struct ListNode;


ListNode* prepend(ListNode* head, int v);

void print_list(ListNode* head);

bool isEmpty(ListNode* head);

ListNode* removeElements(ListNode* head, int v);
ListNode* insert_at_head(ListNode* head, ListNode* newNode);
int getFirst(ListNode* head);
ListNode* reverseList(ListNode* head);
ListNode* getListBetween(ListNode* head, int m, int n);
ListNode* reverseBetween(ListNode* head, int m, int n);
ListNode* deleteDuplicates(ListNode* head);
size_t length(ListNode* head);
ListNode* swapNodes(int m, int n);
void reorderList(ListNode* head);
#endif
