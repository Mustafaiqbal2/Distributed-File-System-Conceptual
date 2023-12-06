#pragma once
#include "machine.h"
class HashMap
{
public:
	Machine** machMap;
	HashMap(int);
	void HashFunction(string);
	void insert(string);
	void deleteMachine(string);
	Machine* search(string);
};

