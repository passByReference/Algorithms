#include<iostream>
#include "TableNode.h"

using namespace std;
bool isEmpty(TableNode* table){
	return table == nullptr;
}

TableNode* prepend(TableNode* table, string val){
	TableNode* newNode = new TableNode;
	newNode->str = val;
	newNode->next = table;
	return newNode;
}
string first(TableNode* table){
	return table->str;
}

TableNode* rest(TableNode* table){
	return table->next;
}

TableNode* deleteFirst(TableNode* table){
	TableNode* newList = rest(table);
	table->next = nullptr;
	delete table;
	return newList;
}
void insertAfter(TableNode* table, string s){
	table->next = prepend(rest(table), s);
}

void deleteList(TableNode* table){
	if(table == nullptr){
		delete table;
		return;
	}
	else{
		deleteList(deleteFirst(table));
	}
}
bool in(TableNode* table, string s){
	TableNode* iter = table;
	while(iter != nullptr){
		if(first(iter) == s) return true;
		iter = iter->next;
       }
	return false;
}
