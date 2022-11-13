#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

// Use pointer to funtion
vector<int> filter(const vector<int>& vec,int filter_value,bool (*pred)(int, int)); 

bool less_than(int, int);

bool greater_than(int, int);

//Implementation of count() algorithm
int count_occurs(const vector<int>& vec, int val);

//Use funtion object to improve filter func
vector<int> imp_filter(const vector<int>& vec, int filter_value, less<int>& lt);

//Implementation of generic algorthm filter()
template<typename InputIterator,typename OutputIterator,typename ElemType,typename Comp>
OutputIterator gen_filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType& val, Comp pred);

int main()
{
	int arr[8] = {
		1,2,4,5,6,2,7,8,
	};

	vector<int> vec(arr, arr + 8);

	vector<int> res = filter(vec, 5, greater_than);

	for (int n : res)
	{
		cout << n << " ";
	}
	cout << "\n" << "---" << "\n";

	cout << count_occurs(vec, 5);
	cout << "\n" << "---" << "\n";

	less<int> lt;
	vector<int> res2 = imp_filter(vec, 5, lt);
	for (int n : res2)
	{
		cout << n << " ";
	}
	cout << "\n" << "---" << "\n";

	const int elem_size = 8;
	int ia[elem_size] = { 4,5,6,7,8,7,10,1};
	vector<int> ivec(ia, ia + elem_size);
	int ia2[elem_size];
	vector<int> ivec2(elem_size);

	gen_filter(ia, ia + elem_size, ia2, 8, less<int>());
	gen_filter(ivec.begin(), ivec.end(), ivec2.begin(), 8, greater<int>());

	for (int i = 0; i < elem_size; i++)
	{
		cout << ia2[i] << " ";
	}
	cout << "\n";
	for (int n : ivec2)
	{
		cout << n << " ";
	}
	cout << "\n" << "---" << "\n";

	return 0;
}

vector<int> filter(const vector<int>& vec, int filter_value, bool(*pred)(int, int))
{
	vector<int> res;

	for (int n : vec)
	{
		if (pred(n, filter_value))
		{
			res.push_back(n);
		}
	}

	return res;
}

bool less_than(int val1, int val2)
{
	return val1 < val2 ? true : false;
}

bool greater_than(int val1, int val2)
{
	return val1 > val2 ? true : false;
}

int count_occurs(const vector<int>& vec, int val)
{
	vector<int>::const_iterator iter = vec.begin();
	int count = 0;

	while ((iter = find(iter,vec.end(),val)) != vec.end())
	{
		count++;
		iter++;
	}

	return count;
}

vector<int> imp_filter(const vector<int>& vec, int filter_value, less<int>& lt)
{
	vector<int> res;
	vector<int>::const_iterator iter = vec.begin();

	while ((iter = find_if(iter,vec.end(),bind2nd(lt,filter_value))) != vec.end())//bind2nd(func,val)
	{
		res.push_back(*iter);
		iter++;
	}

	return res;
}

template<typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator gen_filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType& val, Comp pred)
{
	while ((first = find_if(first,last,bind2nd(pred,val))) != last)
	{
		*(at++) = *(first++);
	}

	return at;
}
