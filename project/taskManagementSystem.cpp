#include "taskManagementSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "sha1.hpp"
using namespace std;

//////////////////////SUPPORT FUNCTIONS////////////////////////////

bool strcmp(string& s1, string& s2)
{
	int size = s1.size();
	for (int i = 0; i < size; i++)
	{
		if (s1[i] < s2[i])
			return 0;
		if (s1[i] > s2[i])
			return 1;
	}
}


///////////////////////////////////////////////////////////////////

taskManagementSystem::taskManagementSystem()
{
	numberMachines = 0;
	int no_machines;
	long double test = 0;

	do
	{

		cout << "ENTER NUMBER OF IDENTIFIER BITS: \t";
		cin >> identifier_bits;

		if (identifier_bits <= 0)
			cout << "\n\nIDENTIFIER BITS CANNOT BE 0 or less\n\n";
	} 
	while (identifier_bits <= 0);

	do
	{
		cout << "ENTER NUMBER OF MACHINES: \t";
		cin >> no_machines;

		test = pow(no_machines, 0.5);
		if ((test > identifier_bits))
			cout << "\n\nMACHINES CANNOT EXCEED POSIBLE FILES\n\n";
	}
	while (test > identifier_bits);


	machID = 1;
}

string taskManagementSystem::hashingFunc(string s1)
{
	SHA1 checksum;
	checksum.update(s1);
	string s2= checksum.final();
	int bits = identifier_bits;
	bits/= 4;
	int upper = identifier_bits % 4;

	int size = s2.size();
	size--;
	if(upper == 0)
		s2 = s2.substr(size - bits, size);
	else
	{
		s2 = s2.substr(size - bits, size);
		char msb = s2[0];
		int temp;
		if (msb >= 48 && msb <= 57)
		{
			temp = msb - 48;
		}
		else
		{
			switch (msb)
			{
			case 'f':
				temp = 15;
				break;
			case 'e':
				temp = 14;

				break;
			case 'd':
				temp = 13;

				break;
			case 'c':
				temp = 12;

				break;
			case 'b':
				temp = 11;

				break;
			case 'a':
				temp = 10;
				break;

			}
		}
		temp &= int(pow(2,upper))-1;
		if (temp >= 0 && temp <= 9)
		{
			msb = temp + 48;
		}
		else
		{
			switch (temp)
			{
			case 10:
				msb = 'a';
				break;
			case 11:
				msb = 'b';
				break;
			case 12:
				msb = 'c';
				break;
			case 13:
				msb = 'd';
				break;
			case 14:
				msb = 'e';
				break;
			case 15:
				msb = 'f';
				break;

			}
		}
		s2[0] = msb;
	}



	return s2;
}

void taskManagementSystem::insertMachine()
{
	char choice;
	string manualID;
	Machine* temp = 0;
	cout << "WOULD YOU LIKE TO ASSIGN A MACHINE ID? (y/n)\n\n";
	cin >> choice;
	if (choice == 'y')
	{
		cout << "ENTER MACHINE ID:\t";
		cin.ignore();
		getline(cin,manualID);
		string hash= hashingFunc(manualID);
		temp = new Machine(manualID, hash);
	}
	else
	{
		cout << "GENERATING MACHINE ID";
		manualID = generateID();
		string hash = hashingFunc(manualID);
		temp = new Machine(manualID, hash);
		machID++;
	}
	if (head == NULL)
	{
		head = temp;
		temp->next = head;
	}
	else
	{
		Machine* temp2 = head;
		bool flag = 1;
		if (strcmp(head->hash, temp->hash))
		{
			while (temp2->next != head)
			{
				temp2 = temp2->next;
			}
			temp2->next = temp;
			temp->next = head;
			head = temp;
			flag = 0;
		}
		while (temp2->next != head && flag)
		{
			if (strcmp(temp->hash, temp2->hash) && strcmp(temp2->next->hash, temp->hash))
			{
				temp->next = temp2->next;
				temp2->next = temp;
				flag = 0;
				break;
			}
			temp2 = temp2->next;
		}
		if (flag)
		{
			temp->next = temp2->next;
			temp2->next = temp;
		}
	}
	numberMachines++;
	// At this point machine is stored in ring dht
	// things left to implement are 1-Routing table reintialization 2-BTree readjustment
	Machine* temp3 = head;
	do
	{
		temp3->CreateRouting(numberMachines);
		temp3 = temp3->next;
	} 
	while (temp3->next != head);

}
void taskManagementSystem::deleteMachine(string hash)
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
	mach+= char(machID + 48);
	return mach;
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
	//ENTER HASH VALUE TO FIND FILE
	string ok= "ok";
	return ok;

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
