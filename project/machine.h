#pragma once
#include "BTree.h"
#include "RoutingTable.h"

class Machine
{
public:	
	string name;
	string hash;
	int machineNum;

	BTree* data;
	RoutingTable* head;
	Machine* next;

	Machine();
	Machine(string&, string&, int);
	void PrintRoutingTable();
	void PrintBTree();
	void SearchinRoutingTable();
	void CreateRouting(int);
};

