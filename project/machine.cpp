#pragma once
#include <iostream>
#include "machine.h"
#include "support.h"

using namespace std;

Machine::Machine(string& name, string& hash, int idBits)
{

	this->name = name;
	this->hash = hash;
	identifier_bits = idBits;
	head = 0;
	next = 0;
}

void Machine::PrintRoutingTable()
{
	if (head == 0)
		return;
	else
	{
		RoutingTable* t1 = head;
		int x = 1;
		cout << "\n\nROUTING TABLE FOR MACHINE: " << name << endl;
		while (t1->next != 0)
		{
			cout <<"INDEX: "<<x << " |MACHINE NAME: " << t1->data->name << "  |MACHINE HASH/ID: " << t1->data->hash << endl;
			t1 = t1->next;
			//cout << endl;
			x++;
		}
		cout << "INDEX: " << x << " |MACHINE NAME: " << t1->data->name << "  |MACHINE HASH/ID: " << t1->data->hash << endl;

	}
}
void Machine::PrintBTree()
{

}
void Machine::SearchinRoutingTable()
{

}
void Machine::CreateRouting(int size)
{
	Machine* temp;
	deleteTable();
	for (int x = 1; x <= size; x++)
	{
		long long int calculate = pow(2, x - 1);
		string s1 = addHash(hash, calculate);

		//////////MOD NEEDS TO BE DONE BEST LOGIC CAN BE TO USE AND FUNCTIONALITY USING TRANSLATE FUNCTIONS  x % 2^n == x & (2^n - 1) as max identifier space is in power of 2
		s1 = modHash(s1, identifier_bits);
		if (strcmp(s1, hash))
			temp = this;
		else
			temp = next;
		if (s1 != temp->hash)
		{
			while (strcmp(s1, temp->hash))
			{
				if (s1 == temp->hash)
					break;
				temp = temp->next;
				if (temp->next == next)
				{
					//temp = temp->next;
					break;
				}
			}
		}

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