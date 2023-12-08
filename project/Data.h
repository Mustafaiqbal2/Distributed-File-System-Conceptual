#pragma once
#include <string>
using namespace std;

class Data
{
public:
	string key;
	string filepath;
	Data* next;
	Data()
	{
		next = nullptr;
	}
	Data(string& k1, string& c1)
	{
		key = k1;
		filepath = c1;
		next = nullptr;
	}
};

class DataList
{
public:
	Data* head;
	DataList()
	{
		head = nullptr;
	}
	void add(Data& node)
	{
		if (head == nullptr)
		{
			head = &node;
			return;
		}
		Data* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = &node;
	}
	~DataList()
	{
		head = nullptr;
	}
};

