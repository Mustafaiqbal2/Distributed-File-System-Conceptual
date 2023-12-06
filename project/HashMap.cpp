#include "HashMap.h"


HashMap::HashMap(int numMachines)
{
	machMap = new Machine * [numMachines] {0};
	size = numMachines;
}
int HashMap::HashFunction(string s1)
{
	return s1 % size;
}
void HashMap::insert(string s1)
{
	index = HashFunction(s1);
}
void HashMap::deleteMachine(string)
{

}
Machine* HashMap::search(string)
{

}