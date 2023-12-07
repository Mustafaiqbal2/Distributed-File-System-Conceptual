#pragma once
#include "BTree.h"

class Machine;

class RoutingTable
{
public:
	Machine* data;
	RoutingTable* next;
	RoutingTable* prev;

	RoutingTable(Machine*);
};

class Machine
{
public:	
	string name;
	string hash;

	BTree* data;
	RoutingTable* head;
	Machine* next;

	Machine(string&, string&);
	void PrintRoutingTable();
	void PrintBTree();
	void SearchinRoutingTable();
	void CreateRouting(int);
	void deleteTable();

};


