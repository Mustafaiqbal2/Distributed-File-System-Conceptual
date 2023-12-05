#pragma once
#include <string>
using namespace std;

class Data
{
public:
	string key;
	string content;
	Data()
	{

	}
	Data(string& k1, string& c1)
	{
		key = k1;
		content = c1;
	}
};

