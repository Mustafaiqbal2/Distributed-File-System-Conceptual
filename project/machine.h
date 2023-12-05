#pragma once
#include "BTree.h"
#include "RoutingTable.h"

class Machine
{
public:	
	BTree* data;
	RoutingTable* head;
	Machine* next;

	Machine();
	void PrintRoutingTable();
	void PrintBTree();
	void SearchinRoutingTable();
	void CreateRouting(int);
};

