#include<iostream>
#include<string>
#include"hashTable.h"

using namespace std;


hashTable::hashTable(int capacity) {


	maxSize = capacity;
	length = 0;
	list = new node2[maxSize];

}

void hashTable::insert(string item)
{
	int total = 0;
	for (int i = 0; i < item.length();i++) {
		total += (int)item[i];
	}
	total = total % 4999;
	node2 *forward = new node2;
	forward->link2 = list[total].link2;
	if (list[total].link2 == NULL) {
		node *temp = new node;
		temp->word = item;
		temp->count = 1;
		temp->link = NULL;

		list[total].link2 = temp;
		
		
	}
	else {
		while (forward->link2->link != NULL) {
			if (forward->link2->word == item) {
				forward->link2->count++;
				break;
			}
			forward->link2 = forward->link2->link;
		}
		if (forward->link2->word == item) {
		
			forward->link2->count++;
		
		}
		else if (forward->link2->link == NULL) {
			node *temp = new node;
			temp->word = item;
			temp->count = 1;
			temp->link = NULL;
			forward->link2->link = temp;
			
		}
	}
	
}


void hashTable::printMax() {
	node *temp = new node;
	temp->count = 0;
	temp->link = NULL;
	node *max = new node;
	max->count = 0;
	max->link = NULL;
	for (int i = 0;i < 5000;i++) {
		temp = list[i].link2;
		if (temp != NULL) {
			while (temp->link != NULL) {
				if (temp->count > max->count) {
					max = temp;
				}
				temp = temp->link;
			}
			if (temp->count > max->count) {
				max = temp;
			}
		}
		else {
		
		}
	}
	cout << max->word << " count : " << max->count << endl;
	max->count = 0;
	
}




