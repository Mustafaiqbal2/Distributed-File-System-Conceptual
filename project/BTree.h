#pragma once
#include "Data.h"
class BTreeNode
{
public:
	int* keys;
	int T;
	Data* data;

	BTreeNode** Childptr;
	int numkeys; 
	bool isleaf; 

	void search();
};
class BTree
{
public:
	BTreeNode* root;
	int degree;

	BTree(int degree);
	void PrintTree();
	void insert(string);
	void deletenode(string);

};

