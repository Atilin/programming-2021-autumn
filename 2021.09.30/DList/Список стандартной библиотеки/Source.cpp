#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

using namespace std;

struct Subscriber
{
	string phone, name, address;
};

ostream& operator << (ostream& st, Subscriber x)
{
	return st << "�������: " << x.phone << endl << "���: " << x.name << endl << "�����: " << x.address << endl;
}
istream& operator >> (istream& st, Subscriber& x)
{
	st >> x.phone >> x.name >> x.address;
	return st;
}

ostream& operator << (ostream& st, list <Subscriber> l)
{
	return st << print(l, l.begin());
}
//istream& operator >> (istream& st, list <Subscriber> l)
//{
//	
//}


//void print(list <Subscriber> l)
//{
//	cout << "������ �������� ��������� ��������:\n\n";
//	list <Subscriber> ::iterator i;
//	for (i = l.begin(); i != l.end(); ++i)
//		cout << *i << endl;
//	cout << endl;
//	//for (Subscriber x : l) // �������� ����
//	//	cout << x << " ";
//	//cout << endl;
//}

Subscriber print(list <Subscriber> l, list <Subscriber> ::iterator i)
{
	if (i != l.end())
	{
		print(l, i++);
		return *i;
	}
}

void menu()
{
	cout << " ����:\n1. �������� ��������\n2. ������� �������� �� ������\n3. ����������� ��� � ����� �������� �� ������ ��������\n4. ����� �� ���������\n\n����������, ������� �������� ����� ����: ";
}

int main()
{
	setlocale(LC_ALL, "Russian"); //��� ������ ������� ����

	list <Subscriber> l;

	cout << "������� ������ � ������� *�����*, *���*, *�����* (Ctrl Z - ����� �����)" << endl;
	Subscriber x;

	while (cin >> x)
	{
		l.push_back(x);
	}


	cin.clear();
	int select = 0;
	do
	{
		menu();
		cin >> select;
		if (select == 1)
		{
			cout << "������� *�������*, *���*, *�����*\n";
			cin >> x;
			l.push_back(x);
		}
		if (select == 2)
		{
			cout << "������� ����� ��������: ";
			string s;
			cin >> s;
			list <Subscriber> ::iterator i;
			for (i = l.begin(); i != l.end(); ++i)
			{
				if ((*i).phone == s)
				{
					l.erase(i);
					break;
				}
			}
			cout << endl;
			//for (Subscriber x : l) // �������� ����
			//{
			//	if (x.phone == s)
			//	{
			//		l.erase(i);
			//		break;
			//	}
			//}
		}
		if (select == 3)
		{
			cout << "������� ����� ��������: ";
			string s;
			cin >> s;
			list <Subscriber> ::iterator i;
			for (i = l.begin(); i != l.end(); ++i)
			{
				if ((*i).phone == s)
				{
					cout << "���: " << (*i).name << " �����: " << (*i).address << endl;
					break;
				}
			}
		}
		cout<<l;

	} while (select != 4);

	return EXIT_SUCCESS;
}