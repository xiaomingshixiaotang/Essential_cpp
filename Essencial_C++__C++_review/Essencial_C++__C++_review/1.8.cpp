#include<iostream>
#include<string>

using namespace std;

int main() {
	string tries_back[3] = {
		"I belive you",
		"Insist again",
		"Fighting"
	};
	int user_tries = 2;

	switch (user_tries)
	{
	case 1:
		cout << tries_back[0];
		break;
	case 2:
		cout << tries_back[1];
		break;
	case 3:
		cout << tries_back[2];
		break;
	default:
		break;
	}

	return 0;
}