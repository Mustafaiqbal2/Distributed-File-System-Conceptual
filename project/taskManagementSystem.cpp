#include "taskManagementSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <openssl/sha.h>


using namespace std;

taskManagementSystem::taskManagementSystem()
{
	int no_machines;
	cout << "ENTER NUMBER OF MACHINES";
	cin >> no_machines;

	cout<<"ENTER NUMBER OF IDENTIFIER BITS";
	cin >> identifier_bits;
}

string taskManagementSystem::SHA1(string s1)
{
	string s2;
	SHA1(s1, sizeof(s1) - 1, s2);
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
		cin.getline(cin, manualID);
		Machine* temp = new Machine(manualID);
	}
	else
	{
		cout << "GENERATING MACHINE ID";
		choice = generateID("machine");
	}
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
string taskManagementSystem::generateID(string)
{

}
void taskManagementSystem::insertData(string)
{

}
void taskManagementSystem::removeData()
{

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
