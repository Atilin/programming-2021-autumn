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

//void enlarge(vector <double> &a)
//{
//	for (int i = 1; i < a.size(); ++i)
//	{
//		a.insert(i, (a[i - 1] + a[i]) / 2);
//	}
//}
template <typename T>
void enlarge(vector <T> & a)
{
	typename vector <T> ::iterator i;
	for (i = a.begin() + 1; i != a.end(); ++i)
	{
		i = a.insert(i, (*(i - 1) + *i) / 2);
		++i;
	}
	cout << "size == " << a.size() << endl;
}

//template <typename T>
//void del(vector <T> & a)
//{
//	typename vector <T> ::iterator i;
//
//	for (i = a.begin(); i < a.end()-1; ++i)
//	{
//		i = a.erase(i);
//	}
//}
template <typename T>
void del(vector <T>& a)
{
	vector <T> b;

	for (int i = 1; i < a.size(); i+=2)
	{
		b.push_back(a[i]);
	}
	a = b;
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


	return EXIT_SUCCESS;
}