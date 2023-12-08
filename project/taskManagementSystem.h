#pragma once
#include "machine.h"
#include "support.h"

class Dictionary
{
public:
	string key;
	string value;
	Dictionary* next;
	Dictionary(string key, string value)
	{
		this->key = key;
		this->value = value;
		next = NULL;
	}
};

class taskManagementSystem
{
public:
	Machine* head;
	Dictionary* dictionary;
	int identifier_bits;
	int machID;
	int numberMachines;
	int order;
	string hashingFunc(string s1);
	taskManagementSystem();
	void insertMachine();
	void deleteMachine(string);
	string generateID();
	void insertData();
	void removeData();
	void search();
};

