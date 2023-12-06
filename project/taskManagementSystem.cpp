#include "taskManagementSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <sha1.hpp>
using namespace std;

taskManagementSystem::taskManagementSystem()
{
	int no_machines;
	cout << "ENTER NUMBER OF MACHINES";
	cin >> no_machines;

	cout<<"ENTER NUMBER OF IDENTIFIER BITS";
	cin >> identifier_bits;

	machID = 1;
}

string taskManagementSystem::hashingFunc(string s1)
{
	SHA1 checksum;
	checksum.update(s1);
	string s2= checksum.final();
	return s2;
}

void taskManagementSystem::insertMachine(string, int)
{
	char choice;
	string manualID;
	Machine* temp = 0;
	cout << "WOULD YOU LIKE TO ASSIGN A MACHINE ID? (y/n)\n\n";
	cin >> choice;
	if (choice == 'y')
	{
		cout << "ENTER MACHINE ID";
		getline(cin,manualID);
		string hash= hashingFunc(manualID);
		Machine* temp = new Machine(manualID, hash,machID);
		machID++;
	}
	else
	{
		cout << "GENERATING MACHINE ID";
		manualID = generateID();
		string hash = hashingFunc(manualID);;
		Machine* temp = new Machine(manualID, hash, machID);
	}
	if (head == NULL)
	{
		head = temp;
		temp->next = head;
	}
	else
	{
		Machine* temp2 = head;
		while (temp2->next != head)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp;
		temp->next = head;
	}
	dht->insert(temp);
}
void taskManagementSystem::deleteMachine(string)
{

}
void taskManagementSystem::dividerange()
{

}
void taskManagementSystem::reMapBtree(Machine*, Machine*)
{

}
string taskManagementSystem::generateID()
{
	string mach = "Machine ";
	mach+= (machID);
}
void taskManagementSystem::insertData(string)
{
	//EITHER CREATE FILE OR OPEN FILE
}
void taskManagementSystem::removeData()
{
	//ENTER HASH VALUE TO FIND FILE
}
string& taskManagementSystem::search(string)
{

}

std::string readEntireFile(const std::string& fileName) {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cout << "Error opening file: " << fileName << std::endl;
		return "";
	}

	std::ostringstream contentStream;
	std::string line;

	// Read the file line by line
	while (std::getline(file, line)) {
		// Append the line to the string
		contentStream << line << '\n';
	}

	// Close the file
	file.close();

	// Get the content from the stringstream
	std::string content = contentStream.str();

	return content;
}
