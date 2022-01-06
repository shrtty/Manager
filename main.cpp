#include "Manager.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string filename(string path)
{
	size_t index = path.find_last_of("\\");
	if (index == string::npos)
		return path;
	return path.substr(index + 1);
}

int main()
{
	const string InputFileName("input.txt");
	ifstream in(InputFileName);
	ofstream out("output.txt");
	if (!in.is_open())
	{
		out << "error: " << filename(InputFileName) << " cannot be opened." << endl;
		return 1;
	}

	Manager manager;
	while (!in.eof())
	{
		in >> manager;
	}
	manager.print_cash(out);
	out << '\n';
	manager.print_bank(out);
	out << '\n';
	manager.print_others(out);
	out << '\n';

	out << manager;
#ifdef _DEBUG
	cout << manager;
#endif

	in.close();
	out.close();
#ifdef _DEBUG
	char c;
	cin.get(c);
#endif

	return 0;
}
