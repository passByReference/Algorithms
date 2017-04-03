/*
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
#include<iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int size(ListNode *l){
  int size = 0;
  while(l->next != NULL){
    ++size;
    l = l->next;
  }
  return size;
}
int min(int a, int b){
  if(a < b)
    return a;
  return b;
}

void isAddOne(int &digitVal, int &addOne){
  if(digitVal > 9){
    digitVal -= 10;
    addOne = 1;
  }
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
  ListNode *head = new ListNode(0);
  ListNode *iter = head;
  ListNode *iter1 = l1;
  ListNode *iter2 = l2;
  int digitVal = 0;
  int addOne = 0;
  
  while(iter1 != NULL && iter2 != NULL){
    digitVal = iter1->val + iter2->val + addOne;
    
    addOne = 0;
    isAddOne(digitVal, addOne);
    /*
    if(digitVal > 9){
      digitVal -= 10;
      addOne = 1;
    }
    */
    ListNode *newNode = new ListNode(digitVal);
    iter->next = newNode;
    iter = iter->next;
    iter1 = iter1->next;
    iter2 = iter2->next;
    cout << "in func " << endl;
  }
  
  if(iter1 != NULL){
    while(addOne == 1 && iter1 != NULL){
      digitVal = addOne + iter1->val;
      addOne = 0;
      isAddOne(digitVal, addOne);
      
      ListNode *newNode = new ListNode(digitVal);
      iter->next = newNode;
      iter = iter->next;
      iter1 = iter1->next;
    }
    if(addOne == 1){
      ListNode *newNode = new ListNode(1);
      iter->next = newNode;
      iter = iter->next;
    }
    iter->next = iter1;
    
  }
  else if(iter2 != NULL){
    while(addOne == 1 && iter2 != NULL){
      digitVal = addOne + iter2->val;
      addOne = 0;
      isAddOne(digitVal, addOne);
      ListNode *newNode = new ListNode(digitVal);
      iter->next = newNode;
      iter = iter->next;
      iter2 = iter2->next;
    }
    if(addOne == 1){
      ListNode *newNode = new ListNode(1);
      iter->next = newNode;
      iter = iter->next;
    }
    iter->next = iter2;
  }
  else{
    if(addOne == 1){
      ListNode *newNode = new ListNode(1);
      iter->next = newNode;
    }
  }
  
  
  return head->next;
  
  
}

void appendNode(ListNode* head, int n)
{
  ListNode* iter = head;
  ListNode* newNode = new ListNode(n);
  
  while(true)
  {
    cout << head->val << endl;
    if(iter->next == NULL)
    {
      iter->next = newNode;
      break;
    }
    else
      iter = iter->next;
  }
  

}
int main(){
  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(9);
  /* 
  appendNode(l1, 4);
  appendNode(l1, 3);

  appendNode(l2, 6);
  appendNode(l2, 4);
  */
  appendNode(l2, 9);
  cout << "in main() " << endl;
  ListNode *result;
  result = addTwoNumbers(l1, l2);
  ListNode *iter = result;
  while(iter != NULL){
    cout << iter->val << endl;
    iter = iter->next;
    
  }
  
  return 0;
  
  
}