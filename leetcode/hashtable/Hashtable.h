#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include<string>
#include<vector>
#include "TableNode.h"

class Hashtable{
	public:
		Hashtable(size_t size);
		void insert(std::string s, int index);
		int indexOf(std::string s);
		void removeStr(std::string s);
		std::vector<std::string> getStringList(int index);
		void printList(int index);
		void printTable();
		void removeAt(int index);
		std::string getVal(int index);
		int getTableSize();
		TableNode** getTable();
		~Hashtable();
	private:
	        TableNode** table;
		size_t tableSize;
};
#endif
