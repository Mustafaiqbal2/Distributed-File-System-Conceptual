#pragma once
#include "machine.h"
#include "support.h"



Machine::Machine(string& name, string& hash)
{

	this->name = name;
	this->hash = hash;
	head = 0;
	next = 0;
}

void Machine::PrintRoutingTable()
{

}
void Machine::PrintBTree()
{

}
void Machine::SearchinRoutingTable()
{

}
void Machine::CreateRouting(int size)
{
	Machine* temp = next;
	deleteTable();
	for (int x = 0; x < size; x++)
	{
		long double calculate = pow(2, x - 1);
		string s1 = addHash(hash, calculate);

		//////////MOD NEEDS TO BE DONE BEST LOGIC CAN BE TO USE AND FUNCTIONALITY USING TRANSLATE FUNCTIONS  x % 2^n == x & (2^n - 1) as max identifier space is in power of 2

		RoutingTable* r1 = new RoutingTable(temp);
		if (head == 0)
			head = r1;
		else
		{
			RoutingTable* t1 = head;
			while (t1->next != 0)
			{
				t1 = t1->next;
			}
			t1->next = r1;
			r1->prev = t1;
		}
	}
}
void Machine::deleteTable()
{
	if (head == 0)
		return;
	else
	{
		RoutingTable* t1 = head;
		RoutingTable* t2 = head;
		while (t1->next != 0)
		{
			t1 = t1->next;
		}
		while (t1->prev != 0)
		{
			t2 = t1;
			t1 = t1->prev;
			delete t2;
		}
		t2 = t1;
		head = 0;
		delete t2;
	}
}