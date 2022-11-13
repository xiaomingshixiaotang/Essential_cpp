#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

int main() {
	ifstream infile("infile.txt");
	vector<string> data;
	string ch;

	if (!infile)
	{
		cerr << "Error:file is not existed";
	}
	else 
	{
		while (infile >> ch)
		{
			data.push_back(ch);
		}
	}

	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i];
	}

	ofstream outfile("outfile.txt");
	for (int i = 0; i < data.size(); i++)
	{
		outfile << data[i];
	}

	return 0;
}