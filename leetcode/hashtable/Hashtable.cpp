#include<iostream>
#include<vector>
#include "Hashtable.h"
using namespace std;

// constructor
Hashtable::Hashtable(size_t size){
		  table = new (nothrow) TableNode*[size]();
		  if(table == nullptr) cerr << "Error: memory could not be allocated" << endl;
		  tableSize = size;
		  for(unsigned i = 0; i < tableSize; ++i){
			  TableNode* newTableNode = new TableNode;
			  newTableNode->str = "";
			  newTableNode->next = nullptr; 
			  table[i] = newTableNode;
		  }
		  cout << "Hash Table with size " << tableSize << " created." << endl;
	  }

/* Insert the given string at the given index
 */
void Hashtable::insert(string s, int index){
       	if(table[index]->str == ""){
		table[index]->str = s;
		table[index]->next = nullptr;
		cout << table[index]->str << endl;
	}
	else{
		insertAfter(table[index], s);
	}

 }
/* It takes an index and returns a vector of all
 * all the strings stored at that index *
 */
vector<string> Hashtable::getStringList(int index){
	TableNode *iter = new TableNode;
	iter = table[index];
        vector<string> stringList;
	while(iter != nullptr){
		stringList.push_back(iter->str);
		iter = iter->next;
	}
	return stringList;
}
/* This function prints all strings stored at the 
 * given index
 */
void Hashtable::printList(int index){
	vector<string> stringList = getStringList(index);
	for(vector<string>::iterator it = stringList.begin(); it != stringList.end(); ++it)
		cout << *it << endl;

}
/* Prints the entire hash table
 */
void Hashtable::printTable(){
	for(int i = 0; i < tableSize; ++i){
		cout << "Index: " << i << " Strings:" << endl;
		printList(i);
	}	
	cout << endl;
}

/* This function removes everything stored
 * at the given index
 */
void Hashtable::removeAt(int index){
	if(table[index] == nullptr)
			  return;
		  else{
			  deleteList(table[index]);
		  }
	  }

/* This function takes a string and searches entire
 * table for it and delete it if the string is found
 */
void Hashtable::removeStr(string s){
		  int i = indexOf(s);
		  if(i == -1){
			  cout << s << " is not in the table" << endl;
			  return;
		  }
		  else{
			 TableNode* iter = table[i];
			 while(iter != NULL){
				 if(first(iter) == s){
					 deleteFirst(iter);
					 break;
				 }
				 iter = iter->next;
			 }
			 cout << s << " is deleted" << endl;


	  	      }
	  }


/* returns the index of a given string
 */
int Hashtable::indexOf(string s){
		  for(unsigned i = 0; i < tableSize; ++i){
			  if(in(table[i], s))
				  return i;
		  }
		  return -1; //-1 means not found
	  }

/* returns table
 */
TableNode** Hashtable::getTable(){
	return table;
}

// returns table size
int Hashtable::getTableSize(){ return tableSize; }

/*destructor
 */
Hashtable::~Hashtable(){
		  delete []table;
	  }
