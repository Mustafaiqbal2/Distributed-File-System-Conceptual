#pragma once
#include "machine.h"

class HashMap
{
public:
	Machine** machMap;
	int size;
	HashMap(int);
	int convertToInt(string);
	int HashFunction(string);
	void insert(Machine*);
	void deleteMachine(Machine*);
	Machine* search(string);
};

