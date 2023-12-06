#pragma once
#include "Data.h"
class BTreeNode
{
public:
	int* keys;
	int T;
	//Data* data;

	BTreeNode** Childptr;
	int numkeys;
	bool isleaf;

	BTreeNode(int T, bool isLeaf/*, Data* d*/);
	BTreeNode* search(int key);

	void split(int index, BTreeNode* splitee);
	void insert2(int key);
	void traverse();
};
class BTree
{
public:
	BTreeNode* root;
	int m;					// order
	int t;					// ceil(m/2)->degree

	BTree(int m);
	BTreeNode* search(int key);
	void insert(int key);

	void traverse() {
		if (root != NULL)
			root->traverse();
	}
};




