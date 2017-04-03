#ifndef _TABLENODE_H_
#define _TABLENODE_H_
#include<string>

struct TableNode{
	std::string str;
	TableNode* next;
};

bool isEmpty(TableNode *table);
TableNode* prepend(TableNode* table, std::string val);
std::string first(TableNode* table);
TableNode* rest(TableNode* table);
TableNode* deleteFirst(TableNode* table);
void deleteList(TableNode* table);
bool in(TableNode* table, std::string s);
void insertAfter(TableNode* table, std::string s);
#endif
