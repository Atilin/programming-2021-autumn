#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void print(vector <double> a)
{
	//1 sposob
	vector <double > ::iterator i;
	for (i = a.begin(); i != a.end(); i++)
		cout << *i << ' ';
	cout << endl;

	//// печать 2-й вариант
	//for (int i = 0; i < a.size(); i++)
	//	cout << a[i] << ' ';
	//cout << endl;
	//// печать 3-й вариант
	//for (int x : a) // короткий цикл for
	//	cout << x << " ";
	//cout << endl;
	//// печать 4-й вариант
	//for (auto x : a) // короткий цикл for c auto
	//	cout << x << " ";
	//cout << endl;
}

template <typename T>
void enlarge(vector <T> & a)
{
	typename vector <T> ::iterator i;
	for (i = a.begin() + 1; i != a.end(); ++i)
	{
		i = a.insert(i, (*(i - 1) + *i) / 2);
		++i;
	}
}

template <typename T>
void del(vector <T> & a)
{
	typename vector <T> ::iterator i;

	for (i = a.begin(); i < a.end(); ++i)
	{
		if (i + 1 == a.end())
		{
			a.erase(i);
			break;
		}
		i = a.erase(i);
	}
}
//template <typename T>
//void del(vector <T> & a)
//{
//	vector <T> b;
//
//	for (int i = 1; i < a.size(); i += 2)
//	{
//		b.push_back(a[i]);
//	}
//	a = b;
//}

template <typename T>
vector<T> concat(vector <T> a, vector <T> b)
{
	vector <T> c(a.size() + b.size());
	copy(a.begin(), a.end(), c.begin());
	copy(b.begin(), b.end(), c.begin() + a.size());
	print(c);
	return c;
}

template <typename T>
vector<T> repeat(vector <T> a, int n)
{
	vector <T> c(a.size() * n);
	for (int i = 0; i < n; ++i)
	{
		copy(a.begin(), a.end(), c.begin() + i * a.size());
	}
	print(c);
	return c;
}

vector<double>::iterator find_second(vector <double> a, double num)
{
	vector<double>::iterator i;
	i = find(a.begin(), a.end(), num);
	if (i == a.end() || i == a.end() - 1)
	{
		return i;
	}
	return find(i + 1, a.end(), num);
}

vector<double>::iterator find_last(vector <double> a, double num)
{
	vector<double>::iterator i = a.begin();
	vector<double>::iterator out = a.end();
	while (i != a.end())
	{
		i = find(i + 1, a.end(), num);
		if (i != a.end())
		{
			out = i;
		}
	}
	return out;
}

void neighbour(vector <double> a, double x, int & i, int & j)
{
	vector<double>::iterator it = lower_bound(a.begin(), a.end(), x);
	if (it == a.end())
	{
		++i;
	}
	else if (*it == x)
	{
		i = it - a.begin();
		j = i;
	}
	else
	{
		++i;
	}
}


int main()
{
	vector <double> a;
	double x;
	while (cout << "Enter data: ", cin >> x)
	{
		a.push_back(x);
	}
	cin.clear();

	cout << "enlarge: ";
	enlarge(a);
	print(a);

	cout << "del: ";
	del(a);
	print(a);

	int cap = a.size();
	double* arr = new double[cap];
	copy(a.begin(), a.end(), arr);
	cout << "copy from vector to arr: ";
	for (int i = 0; i < cap; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	vector <double> b{ 32,64,128,256,512 };
	cout << "a: ";
	print(a);
	cout << "b: ";
	print(b);
	concat(a, b);

	cout << "enter how many times you want to repeat the vector: ";
	cin >> x;
	repeat(a, x);

	cout << "enter element which you want to find_second: ";
	double element = 0;
	cin >> element;
	find_second(a, element);

	cout << "enter element which you want to find_last: ";
	cin >> element;
	find_last(a, element);

	sort(a.begin(), a.end());
	cout << "Enter element relative to which you want to find neighbors: ";
	cin >> x;
	int i = 0;
	int j = 0;
	neighbour(a, x, i, j);
	cout << "i = " << i << ", j = " << j << endl;

	return EXIT_SUCCESS;
}