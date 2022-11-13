#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void bubble_sort(vector<int>&, ofstream* = 0);

void display(const vector<int>&, ostream & = cout);

int main() {
	int ia[8] = { 8,9,45,6,7,8,3,2 };
	vector<int> vec(ia, ia + 8);

	//bubble_sort(vec);
	//display(vec);

	ofstream ofil("data.txt");
	bubble_sort(vec, &ofil);
	display(vec, ofil);

	return 0;
}

void bubble_sort(vector<int>& vec, ofstream* ofil) 
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[i] > vec[j])
			{
				if (ofil != 0)
				{
					(*ofil) << "about to call swap! i: " << i
						<< " j " << j << "\tswapping: " << vec[i]
						<< " with " << vec[j] << endl;
				}

				swap(vec[i], vec[j]);
			}
		}
	}
}

void display(const vector<int>& vec, ostream& ost) 
{
	for (int i = 0; i < vec.size(); i++)
	{
		ost << vec[i] << " ";
	}

	cout << endl;
}