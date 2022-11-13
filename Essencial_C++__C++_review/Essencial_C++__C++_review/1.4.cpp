#include<iostream>
#include<string>

using namespace std;

int main() {
	string first_name;
	string last_name;

	cout << "Please enter your first name:";
	cin >> first_name;
	cout << "Please enter you last_name:";
	cin >> last_name;
	cout << '\n'
		<< "hello,"
		<< last_name
		<< " "
		<< first_name
		<< "...goodbye!";

	return 0;
}