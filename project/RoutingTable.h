#pragma once
#include "machine.h"

class RoutingTable
{
public:
	Machine* data;
	RoutingTable* next;
	RoutingTable* prev;

	RoutingTable();
	RoutingTable(Machine*);
};