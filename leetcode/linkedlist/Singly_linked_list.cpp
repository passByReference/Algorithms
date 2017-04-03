#include<iostream>
#include<unordered_map>
#include "Singly_linked_list.h"
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr){}
};
ListNode* prepend(ListNode* head, int v){
    ListNode* newNode = new ListNode();
    newNode->val = v;
    newNode->next = head;
    return newNode;
}

bool isEmpty(ListNode* head){
    return head == nullptr;
}

void print_list(ListNode* head){
    ListNode* current = head;
    if(!head){
        cout << " List is empty." << endl;
        return;
    }
    while(current){
        cout << current->val << endl;
        current = current->next;
    }
}

ListNode* removeElements(ListNode* head, int v){
    if(!head) return head;
    while(head->val == v){ // delete the first node only
        ListNode* h = head;
        head = head->next;
        delete h;
        if(!head) return head;
    }
    if(head){
        ListNode* current = head->next;
        ListNode* prev = head;
        while(current){
            if(current->val == v){
                prev->next = current->next;
                delete current;
                //ListNode* current = prev->next;//current is not deleted
                //the stuff current points to is deleted
                current = prev->next;
            }
            else{
                current = current->next;
                prev = prev->next;
            }
        }
    }
    return head;
}
ListNode* insert_at_head(ListNode* head, ListNode* newNode){
    newNode->next = head;
    return newNode;
}
int getFirst(ListNode* head){
    if(!head) return 0;
    return head->val;
}
/* slower version
ListNode* reverseList(ListNode* head){
    ListNode* reversedList = nullptr;
    ListNode* current = head;
    while(current){
        reversedList = prepend(reversedList, getFirst(current));
        current = current->next;
    }
    return reversedList;
}
*/

ListNode* reverseList(ListNode* head) {
    if (!head) return head;
    ListNode* current = head->next;
    ListNode* prev = head;
    if (!current) return head;
    prev->next = nullptr;
    while (current->next) {
        cout << current->val << endl;
        ListNode* temp = current->next;
        if (!temp) break;
        current->next = prev;
        prev = current;
        current = temp;
    }
    current->next = prev;
    return current;
}

ListNode* reverseBetween(ListNode* head, int m, int n){
    if(!head || (m == n)) return head;
    ListNode* current = head;
    ListNode* original_head = head;
    ListNode* result = original_head;
    int iter = 1;
    while(iter != m && current){
        cout << "here1" << endl;
        result = current;
        current = current->next;
        ++iter;
    }
    ListNode* newHead = current;//new head is the head of selected list
    ListNode* newHeadCurr = newHead;
    while(iter != n && newHeadCurr){
        newHeadCurr = newHeadCurr->next;
        ++iter;
    }
    ListNode* tail;
    if(newHeadCurr){
        tail = newHeadCurr->next;
        newHeadCurr->next = nullptr;
    }
    else tail = newHeadCurr;
    newHead = reverseList(newHead);
    ListNode* result_iter = newHead;
    while(result_iter->next){
        result_iter = result_iter->next;
    }
    result_iter->next = tail;
    if(m == 1) return newHead;
    else{
        result->next = newHead;
        return original_head;
    }
}

ListNode* deleteDuplicates(ListNode* head){
   if(!head) return head;
   unordered_map<int, int> count_map;
   ListNode* current = head;
   while(current){
       ++count_map[current->val];
       current = current->next;
   }
   while(count_map[head->val] > 1){
       ListNode* h = head;
       head = head->next;
       delete h;
       if (!head) return head;
   }
   current = head->next;
   ListNode* prev = head;
   while(current){
       if(count_map[current->val] > 1){
           prev->next = current->next;
           delete current;
           current = prev->next;
       }
       else{
           prev = current;
           current = current->next;
       }
   }
   return head;
}

size_t length(ListNode* head){
    ListNode* current = head;
    size_t counter = 0;
    while(current){
        current = current->next;
        ++counter;
    }
    return counter;
}
ListNode* swapNodes(ListNode* head, int m, int n){
    size_t size = length(head);
    cout << m << " " << n << endl;
    if(m < 0 || n < 0 || m > size || n > size ){
        cout << "index out of bound" << endl;
        return nullptr;
    }
    if(m == n) return head;
    int left = 1, right = 1;
    ListNode* leftNode = head;
    ListNode* preLeftNode = nullptr;
    while(left < m){
        preLeftNode = leftNode;
        leftNode = leftNode->next;
        ++left;
    }
    ListNode* rightNode = head;
    ListNode* preRightNode = nullptr;
    while(right < n){
        preRightNode = rightNode;
        rightNode = rightNode->next;
        ++right;
    }
    ListNode* temp;
    if(rightNode)
        temp = rightNode->next; //holds rightNode next for leftNode->next
    else temp = nullptr;
    preLeftNode->next = rightNode;
    rightNode->next = leftNode->next;
    preRightNode->next = leftNode;
    leftNode->next = temp;
    return head;
}
void reorderList(ListNode* head){
    size_t size = length(head);
    for (int i = 2, j = size; i <= j; ++i, --j){
        head = swapNodes(head, i, j);
    }
}

ListNode* sortList(ListNode* head) {
    if (!head) return head;
    unsigned len = length(head);
    unsigned mid = len / 2;
    ListNode* current = head;
    ListNode* left = new ListNode(current->val);
    ListNode* leftIter = left;
    unsigned cnt = 1;
    cout << current->next->val << endl;
    while (cnt < mid && current->next) {
        cout << "Im here" << endl;
        current = current->next;
        ListNode* newNode = new ListNode(current->val);
        leftIter->next = newNode;
        leftIter = leftIter->next;
        ++cnt;
    }
    current = current->next;
    ListNode* right = nullptr;
    if (current) {
        right = new ListNode(current->val);
    }
    ListNode* rightIter = right;
    while (cnt < len && current->next && rightIter) {
        current = current->next;
        ListNode* newNode = new ListNode(current->val);
        rightIter->next = newNode;
        rightIter = rightIter->next;
        ++cnt;
    }
    leftIter = sortList(left);
    rightIter = sortList(right);
    unsigned i = 0, j = 0;
    current = head;
    while (current && i < length(leftIter) && j < length(rightIter)) {
        if (leftIter->val < rightIter->val) {
            current->val = leftIter->val;
            leftIter = leftIter->next;
        }
        else {
            current->val = rightIter->val;
            rightIter = rightIter->next;
        }
        current = current->next;
    }
    while (i < length(leftIter) && current) {
        current->val = leftIter->val;
        leftIter = leftIter->next;
        current = current->next;
    }
    
    while (j < length(rightIter) && current) {
        current->val = rightIter->val;
        rightIter = rightIter->next;
        current = current->next;
    }
    return head;
}
