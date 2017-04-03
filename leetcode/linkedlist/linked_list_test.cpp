#include<iostream>
#include "Singly_linked_list.h"

using namespace std;
int main(){
    ListNode* list = nullptr;
    list = prepend(list, 5);
    list = prepend(list, 4);
    list = prepend(list, 3);
    list = prepend(list, 2);
    list = prepend(list, 1);
    print_list(list);
    cout << "-------------------" << endl;
    //print_list(removeElements(list, 1));
    //ListNode* list2 = nullptr;
    //list2 = reverseBetween(list, 2, 3);
    //print_list(deleteDuplicates(list));
    //reorderList(list);
    list = reverseList(list);
    print_list(list);
    return 0;
}
