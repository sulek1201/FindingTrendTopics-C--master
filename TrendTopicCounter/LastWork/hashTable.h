#include<iostream>
#include<string>

using namespace std;

struct node {

	int count;
	string word;
	node *link=NULL;

};

struct node2 {
	node *link2=NULL;
};

class hashTable {

public:

	hashTable(int = 5000);

	int maxSize; //capacity
	int length; //# of items in the list
	node2 *list;
	void insert(string);
	void printMax();

};


