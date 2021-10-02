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

void menu()
{
	cout << " ����:\n1. �������� ��������\n2. ������� �������� �� ������\n3. ����������� ��� � ����� �������� �� ������ ��������\n4. ����� �� ���������\n\n����������, ������� �������� ����� ����: ";
}

int main()
{
	setlocale(LC_ALL, "Russian"); //��� ������ ������� ����

	list <Subscriber> l;

	cout << "������� ������ � ������� *�����* *���* *�����* (Ctrl Z - ����� �����)" << endl;
	Subscriber x;
	while (cin >> x)
		l.push_back(x);

	list <Subscriber> ::iterator i;
	for (i = l.begin(); i != l.end(); ++i)
		cout << *i << ' ';
	cout << endl;

	//for (int x : l) // �������� ����
	//	cout << x << " ";
	//cout << endl;

	int select = 0;
	do
	{
		menu();
		cin >> select;

	} while (select != 4);

	return EXIT_SUCCESS;
}