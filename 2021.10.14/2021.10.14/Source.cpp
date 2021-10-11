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
		a.erase(i);
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

template <typename T1, typename T2>
T1 concat(vector <T1> a, vector <T2> b)
{
	a.resize(a.size() + b.size());
	copy(b.begin(), b.end(), a.begin() + a.size());
	print(a);
	return a;
}



int main()
{
	vector <double> a;
	double x;
	while (cout << "Enter data: ", cin >> x)
	{
		a.push_back(x);
	}
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

	return EXIT_SUCCESS;
}