#include"BinaryTree.h"
#include<string>

BinaryTree::BinaryTree() {
	root = NULL;
}

treeNode* BinaryTree::getRoot() {
	return root;
}


int BinaryTree::nodeCount(treeNode *p) {
	if (p != NULL)
	{
		return 1 + nodeCount(p->rlink) + nodeCount(p->llink);
	}
	else
	{
		return 0;
	}
}


bool BinaryTree::isEmpty() {
	return root == NULL;
}


void BinaryTree::insert(string item) {
	treeNode *inode = new treeNode;
	inode->info = item;
	inode->llink = NULL;
	inode->rlink = NULL;

	if (isEmpty())
	{
		root = inode;
	}
	else
	{
		treeNode *current = root;
		treeNode* trailcurr = current;

		while (current != NULL)
		{
			trailcurr = current;

			if (current->info > item)
			{
				current = current->llink;
			}
			else
			{
				current = current->rlink;
			}
		}

		if (trailcurr->info > item)
		{
			trailcurr->llink = inode;
		}

		else if (trailcurr->info < item)
		{
			trailcurr->rlink = inode;
		}
	}
}



bool BinaryTree::search(string item) {

	
	treeNode *node;
	node = root;

	while (node != NULL && node->info != item)
	{

		if (item < node->info) {
			node = node->llink;
		}
		else if (item > node->info){
			node = node->rlink;
		}

	}
	if (node == NULL) {
		return false;
	}

	if (node->info == item) {
		return true;
	}
	return false;

}
