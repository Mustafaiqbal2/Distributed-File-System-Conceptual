#pragma once
#include "machine.h"
#include <sstream>

using namespace std;

int translate(char x)
{
	if (x >= 'a' && x <= 'f')
		return x - 87;
	else if (x >= '0' && x <= '9')
		return x - 48;
	else 
		return 0;
}
char translate(int x)
{
	if (x >= 0 && x <= 9)
		return x + 48;
	else if (x >= 10 && x <= 15)
		return x + 87;
	else
		return 0;
}

string addHash(string h1, long long int calculate)
{
	int size = h1.size();
	int carry = 0;

	stringstream oss;
	oss << std::hex << calculate;
	string num = oss.str();
	int size2 = num.size();

	string ans;
	ans.resize((max(size, size2) + 1));
	int size3 = ans.size();

	int h0 = 0;
	int d0 = 0;
	for (int i = size - 1, j=size2-1 ,k = size3-1; i >= 0 && j>=0; i--,j--,k--)
	{
		if (i >= 0)
			h0 = translate(h1[i]);
		else
			h0 = 0;
		if (j > 0)
			d0 = translate(num[j]);
		else
			d0 = 0;
		int sum = h0 + d0 + carry;
		carry = sum / 16;
		sum = sum % 16;
		
		ans[k] = translate(sum);
	}
	int x = 0;
	for (; x < size3; x++)
	{
		if (translate(ans[x]))
			break;
	}
	ans.substr(x, size3 - 1);
	return ans;
}

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