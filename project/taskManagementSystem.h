#pragma once
#include "HashMap.h"

class taskManagementSystem
{
public:
	Machine* head;
	HashMap* dht;

	taskManagementSystem();
	void insertMachine(string,int);
	void deleteMachine(string);
	void dividerange();
	void reMapBtree(Machine*,Machine*);
	string generateID(string);
	void insertData(string);
	void removeData();
	string& search(string);
};

