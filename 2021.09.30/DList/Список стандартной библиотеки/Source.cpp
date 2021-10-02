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
	return st << "Телефон: " << x.phone << endl << "Имя: " << x.name << endl << "Адрес: " << x.address << endl;
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
//	cout << "Список содержит следующие элементы:\n\n";
//	list <Subscriber> ::iterator i;
//	for (i = l.begin(); i != l.end(); ++i)
//		cout << *i << endl;
//	cout << endl;
//	//for (Subscriber x : l) // короткий цикл
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
	cout << " Меню:\n1. Добавить абонента\n2. Удалить абонента по номеру\n3. Распечатать имя и адрес абонента по номеру телефона\n4. Выйти из программы\n\nПожалуйста, введите желаемый пункт меню: ";
}

int main()
{
	setlocale(LC_ALL, "Russian"); //для вывода русских букв

	list <Subscriber> l;

	cout << "Введите данные в формате *номер*, *имя*, *адрес* (Ctrl Z - конец ввода)" << endl;
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
			cout << "Введите *телефон*, *имя*, *адрес*\n";
			cin >> x;
			l.push_back(x);
		}
		if (select == 2)
		{
			cout << "Введите номер абонента: ";
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
			//for (Subscriber x : l) // короткий цикл
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
			cout << "Введите номер абонента: ";
			string s;
			cin >> s;
			list <Subscriber> ::iterator i;
			for (i = l.begin(); i != l.end(); ++i)
			{
				if ((*i).phone == s)
				{
					cout << "Имя: " << (*i).name << " Адрес: " << (*i).address << endl;
					break;
				}
			}
		}
		cout<<l;

	} while (select != 4);

	return EXIT_SUCCESS;
}