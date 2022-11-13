#include<iostream>
#include<vector>

using namespace std;

inline bool is_size_ok(int size) 
{
	const int max_size = 1024;
	
	if (size <= 0 || size >= max_size)
	{
		cerr << "Oops: requested size is not supported: "
			<< size << " -- can't fulfill request\n";
		return false;
	}
	return true;
}

inline const vector<int>* fibon_seq(int size)
{
	static vector<int> elems;

	if (!is_size_ok(size))
	{
		return 0;//NULL
	}

	for (int i = elems.size(); i < size; i++)
	{
		if (i == 0 || i == 1)
		{
			elems.push_back(1);
		}
		else
		{
			elems.push_back(elems[i - 1] + elems[i - 2]);
		}
	}

	return &elems;
}

bool fibon_elem(int pos, int& elem);

int main()
{
	int elem = 0;
	fibon_elem(2, elem); cout << elem << " ";
	fibon_elem(4, elem); cout << elem << " ";

	return 0;
}

bool fibon_elem(int pos, int& elem)
{
	const vector<int>* pseq = fibon_seq(pos);

	if (!pseq)
	{
		elem = 0;
		return false;
	}

	elem = (*pseq)[pos - 1];
	return true;
}