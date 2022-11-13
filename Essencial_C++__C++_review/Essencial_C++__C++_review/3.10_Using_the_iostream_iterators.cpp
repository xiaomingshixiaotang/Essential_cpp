#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	istream_iterator<string> is(cin);
	istream_iterator<string> eof;//ctrl + z + enter express input finishing

	vector<string> text;
	copy(is, eof, back_inserter(text));//Use insertion adaptor

	sort(text.begin(), text.end());

	ostream_iterator<string> os(cout, " ");

	copy(text.begin(), text.end(), os);

	return 0;
}