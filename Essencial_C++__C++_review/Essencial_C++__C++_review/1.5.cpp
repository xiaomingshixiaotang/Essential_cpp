#include<iostream>
#include<string>

using namespace std;

int main() {
	string s_user_name;

	cout << "Please enter your name:";
	cin >> s_user_name;
	if (s_user_name.size() > 2)
	{
		cout << '\n'
			<< "hello,"
			<< s_user_name
			<< "...goodbye!";
	}

	char c_user_name[10];

	cout << "Please enter your name:";
	cin >> c_user_name;
	if (strlen(c_user_name) > 2)
	{
		cout << '\n'
			<< "hello,"
			<< c_user_name
			<< "...goodbye!";
	}

	return 0;
}
