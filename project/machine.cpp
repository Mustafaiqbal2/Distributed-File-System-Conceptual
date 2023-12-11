#pragma once
#include <iostream>
#include "machine.h"
#include "support.h"

using namespace std;

Machine::Machine(string& name, string& hash, int idBits, int order)
{
	data = 0;
	this->name = name;
	this->hash = hash;
	identifier_bits = idBits;
	head = 0;
	next = 0;
	this->order = order;
	data = new BTree;//(order);
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
	data->traverse();
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
void Machine::insertData(string filename,string key, string content)
{	
	Machine* temp = this;
	do
	{
		if (strcmp(temp->hash , key) && strcmp(temp->next->hash , key)) // LESS THAN ROOT
		{
			string path = temp->next->hash + '\\' + filename;
			temp->data->insert(key, path, content);
			return;
		}
		if (strcmp(key, temp->hash) && strcmp(temp->next->hash, key)) // GREATER THAT CURRENT LESS THAN NEXT
		{
			string path= temp->hash + '\\' + filename;
			temp->next->data->insert(key, path, content);
			return;
		}
		if (temp->next == this)
		{
			if (strcmp(key, temp->hash) && strcmp(key, temp->next->hash)) //GREATER THAN FURTHEST MACHINE AND GREATER THAN ROOT ALLOCATED TO ROOT
			{
				string path = temp->next->hash + '\\' + filename;
				temp->data->insert(key, path, content);
				return;
			}
		}
		temp = temp->next;
	}
	while (temp != this);
}
void Machine::deleteData(string key)
{
	Machine* temp = this;
	do
	{
		if (strcmp(temp->hash, key) && strcmp(temp->next->hash, key)) // LESS THAN ROOT
		{
			temp->data->DeleteNode(key);
			return;
		}
		if (strcmp(key, temp->hash) && strcmp(temp->next->hash, key)) // GREATER THAT CURRENT LESS THAN NEXT
		{
			temp->data->DeleteNode(key);
			return;
		}
		if (temp->next == this)
		{
			if (strcmp(key, temp->hash) && strcmp(key, temp->next->hash)) //GREATER THAN FURTHEST MACHINE AND GREATER THAN ROOT ALLOCATED TO ROOT
			{
				temp->data->DeleteNode(key);
				return;
			}
		}
		temp = temp->next;
	} while (temp != this);
}
string Machine::search(string key)
{
	RoutingTable* temp2 = head;
	if (strcmp(key, hash) && strcmp(temp2->data->hash, key))
	{
		return temp2->data->search(key);
	}
	temp2 = temp2->next;
	while (temp2 != 0)
	{
		if (strcmp(key, temp2->prev->data->hash) && strcmp(temp2->data->hash, key))
		{
			return temp2->prev->data->search(key);
		}
		temp2 = temp2->next;
	}
	if (data == 0)
		data = new BTree;//(order);
	return data->search(key);
}