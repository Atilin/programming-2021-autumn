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

	//// ������ 2-� �������
	//for (int i = 0; i < a.size(); i++)
	//	cout << a[i] << ' ';
	//cout << endl;
	//// ������ 3-� �������
	//for (int x : a) // �������� ���� for
	//	cout << x << " ";
	//cout << endl;
	//// ������ 4-� �������
	//for (auto x : a) // �������� ���� for c auto
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

//template <typename T1, typename T2>
//vector<T1> concat(vector <T1> a, vector <T2> b)
//{
//	a.resize(a.size() + b.size());
//	copy(b.begin(), b.end(), a.begin() + a.size());
//	print(a);
//	return a;
//}

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
		i = find(i+1, a.end(), num);
		if (i != a.end())
		{
			out = i;
		}
	}
	return out;
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

	/*cout << "del: ";
	del(a);
	print(a);*/

	int cap = a.size();
	double* arr = new double[cap];
	copy(a.begin(), a.end(), arr);
	cout << "copy from vector to arr: ";
	for (int i = 0; i < cap; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	/*vector <double> b{ 32,64,128,256,512 };
	cout << "a: ";
	print(a);
	cout << "b: ";
	print(b);
	concat(a, b);*/

	cout << "enter element which you want to find: ";
	double element = 0;
	cin >> element;
	find_second(a, element);


	return EXIT_SUCCESS;
}