#include<iostream>

using namespace std;

bool fibon_elem(int pos, int& elem);

bool print_sequence(int pos);

int main() {
	int pos;
	cout << "Please enter a position:";
	cin >> pos;

	int elem;
	if (fibon_elem(pos, elem))
	{
		cout << "element # " << pos
			<< " is " << elem << endl;
	}
	else
	{
		cout << "Sorry.Could not caculate element #"
			<< pos << endl;
	}

	print_sequence(pos);
}

bool fibon_elem(int pos, int& elem)
{
	if (pos <= 0 || pos >= 1024)
	{
		elem = 0;
		return false;
	}
	
	elem = 1;
	int n_1 = 1, n_2 = 1;
	for (int i = 3; i <= pos; i++)
	{
		elem = n_2 + n_1;
		n_1 = n_2;
		n_2 = elem;
	}

	return true;
}

bool print_sequence(int pos)
{
	if (pos <= 0 || pos >= 1024)
	{
		cerr << "invalid position:" << pos
			<< "--- cannot handle request!\n" << endl;
		return false;
	}

	cout << "The Fibonacci Sequence for"
		<< pos << "positions:\n\t";

	switch (pos)
	{
	default:
	case 2:
		cout << "1 ";//No break!
	case 1:
		cout << "1 ";
	}

	int elem = 0;
	int n_1 = 1, n_2 = 1;
	for (int i = 3; i <= pos; i++)
	{
		elem = n_2 + n_1;
		n_1 = n_2;
		n_2 = elem;

		cout << elem << ((elem % 10) ? " " : "\n\t");
	}
	cout << endl;

	return true;
}
