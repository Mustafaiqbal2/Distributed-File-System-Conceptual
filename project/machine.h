#pragma once
#include "BTree.h"
#include "RoutingTable.h"

class Machine
{
public:	
	string id;
	string hash;
	int machineNum;

	BTree* data;
	RoutingTable* head;
	Machine* next;

	Machine();
	void PrintRoutingTable();
	void PrintBTree();
	void SearchinRoutingTable();
	void CreateRouting(int);
};

