// FNTASTIC_Test_Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void error(string s);
string replacements(const string & input);

int main()
{
	ifstream input{ "input.txt" };
	if (!input.is_open()) error("Could not open the file");

	ofstream output{ "output.txt" };
	if (!output.is_open()) error("Could not open the file");

	string line;

	while (getline(input, line))
	{
		output << replacements(line) << endl;
	}

	input.close();
	output.close();

	return 0;
}

void error(string s)
{
	throw runtime_error(s);
}

string replacements(const string & input)
{
	string output = input;
	for (int i = 0; i < input.length(); ++i)
	{
		int duplCount = 0;
		for (int j = 0; j < input.length(); ++j) {
			if (tolower(input[i]) == tolower(input[j]))
			{
				duplCount++;
			}
		}

		if (duplCount > 1)
		{
			output[i] = ')';
		}
		else {
			output[i] = '(';
		}
	}

	return output;
}