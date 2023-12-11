#pragma once
#include "Data.h"
class BTreeNode
{
public:
	Data* keys;
	
	//Data* data;

	BTreeNode** Childptr;
	int numkeys;
	bool isleaf;

	BTreeNode(bool isLeaf);
	string search(string key);
	void search2(string key, string& ans);

	void split(int index, BTreeNode* splitee);
	void insert2(string key, string filepath);
	void traverse();
	void rectrav(DataList& head);
	DataList CreateList();
	void findsamekey(string key, Data*& dat);


	void Delete(string k);
	void borrowFromNext(int idx);
	void borrowFromPrev(int idx);
	void merge(int idx);
};
class BTree
{
public:
	BTreeNode* root;
	//int m;					// order
	//int t;					// ceil(m/2)->degree

	BTree(int m);
	string search(string key);
	string search2(string key);
	DataList CreateList();
	void insert(string key, string filepath, string content);
	void DeleteNode(string key);
	Data* findsamekey(string key);
	void traverse() 
	{
		if (root != NULL)
			root->traverse();
	}
};




