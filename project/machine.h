#pragma once
#include "BTree.h"

using namespace std;

class Machine;

class RoutingTable
{
public:
	Machine* data;
	RoutingTable* next;
	RoutingTable* prev;

	RoutingTable();
	RoutingTable(Machine*);
};

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


