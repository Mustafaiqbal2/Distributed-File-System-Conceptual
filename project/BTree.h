#pragma once
#include "Data.h"
class BTreeNode
{
public:
	string* keys;
	int T;
	//Data* data;

	BTreeNode** Childptr;
	int numkeys;
	bool isleaf;

	BTreeNode(int T, bool isLeaf/*, Data* d*/);
	BTreeNode* search(string key);

	void split(int index, BTreeNode* splitee);
	void insert2(string key);
	void traverse();
};
class BTree
{
public:
	BTreeNode* root;
	int m;					// order
	int t;					// ceil(m/2)->degree

	BTree(int m);
	BTreeNode* search(string key);
	void insert(string key);

	void traverse() {
		if (root != NULL)
			root->traverse();
	}
};




