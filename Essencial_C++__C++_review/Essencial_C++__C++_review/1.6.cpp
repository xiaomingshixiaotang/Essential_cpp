#include<iostream>
#include<vector>

using namespace std;

int main() {
	int arr[100] = {0};
	vector<int> vec;

	cout << "Please enter some integer(000 is mean to exit):";
	int num;
	int i = 0;
	cin >> num;
	while (num != 000)
	{
		arr[i] = num;
		i++;

		vec.push_back(num);

		cin >> num;
	}

	int sum = 0;
	int size = 0;
	int avr = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += arr[i];
		if (arr[i] != 0)
		{
			size++;
		}
	}
	avr = sum / size;
	cout << sum
		<< ' '
		<< avr;

	return 0;
}