#pragma once
#include "machine.h"
class HashMap
{
public:
	Machine** machMap;
	HashMap(int identifier_space);
	void HashFunction(string);
	void insert(string);
	void deleteMachine(string);
	Machine* search(string);
};

