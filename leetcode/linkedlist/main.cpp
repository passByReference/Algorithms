#include "Doubly_linked_list.h"
#include<iostream>
typedef Doubly_linked_list ll;
using namespace std;

int main(){
	ll list;
	list.insert_at_head(1);
	list.insert_at_head(2);
	list.insert_at_head(3);
	list.insert_at_tail(10);
	list.insert_at_head(4);
	list.insert_at_index(11, 2);
	list.print_list();
	list.remove_from_head();
	list.print_list();
	list.remove_from_tail();
	list.print_list();
	cout << list.remove_from_index(4) << endl;
	list.print_list();
	list.replace_at_index(55, 1);
	list.print_list();
	cout << list.data_at(1) << endl;
	cout << list.data_at(100) << endl;
	cout << list.has_data(55) << endl;
	cout << list.has_data(100) << endl;
	list.remove(1);
	list.print_list();
	return 0;
}
