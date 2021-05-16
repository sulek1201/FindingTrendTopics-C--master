#include<iostream>
#include<string>
using namespace std;

struct treeNode {
	string info;
	treeNode *llink;
	treeNode* rlink;
};

class BinaryTree {
	treeNode *root;
public:
	BinaryTree();
	treeNode* getRoot();
	int nodeCount(treeNode* p);
	void insert(string);
	bool search(string);
	bool isEmpty();

};

