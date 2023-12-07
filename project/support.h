#pragma once
#include<sstream>
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
	return 0;
}

int translate(char x)
{
	if (x >= 'a' && x <= 'f')
		return x - 87;
	else if (x >= '0' && x <= '9')
		return x - 48;
	else
		return 0;
}
char translate(int x)
{
	if (x >= 0 && x <= 9)
		return x + 48;
	else if (x >= 10 && x <= 15)
		return x + 87;
	else
		return 0;
}

string addHash(string h1, long long int calculate)
{
	int size = h1.size();
	int carry = 0;

	stringstream oss;
	oss << std::hex << calculate;
	string num = oss.str();
	int size2 = num.size();

	string ans;
	ans.resize((max(size, size2) + 1));
	int size3 = ans.size();

	int h0 = 0;
	int d0 = 0;
	for (int i = size - 1, j = size2 - 1, k = size3 - 1; i >= 0 && j >= 0; i--, j--, k--)
	{
		if (i >= 0)
			h0 = translate(h1[i]);
		else
			h0 = 0;
		if (j > 0)
			d0 = translate(num[j]);
		else
			d0 = 0;
		int sum = h0 + d0 + carry;
		carry = sum / 16;
		sum = sum % 16;

		ans[k] = translate(sum);
	}
	int x = 0;
	for (; x < size3; x++)
	{
		if (translate(ans[x]))
			break;
	}
	ans.substr(x, size3 - 1);
	return ans;
}


///////////////////////////////////////////////////////////////////