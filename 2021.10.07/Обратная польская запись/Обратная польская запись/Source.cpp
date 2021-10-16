#include <iostream>
#include <stack>
#include <string>

using namespace std;

void f1(string& s)
{
	stack <char> a;
	string r = "";

	//DEBUG
	/*stack <char> a_copy;*/

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			r += s[i];
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			while (!a.empty() && (a.top() == '*' || a.top() == '/'))
			{
				r += a.top();
				a.pop();
			}
			a.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			while (!a.empty() && (a.top() == '*' || a.top() == '/' || a.top() == '+' || a.top() == '-'))
			{
				r += a.top();
				a.pop();
			}
			a.push(s[i]);
		}
		else if (s[i] == '(')
		{
			a.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (a.top() != '(')
			{
				r += a.top();
				a.pop();
			}
			a.pop();
		}

		//DEBUG
		/*cout << endl;
		cout << "DEBUG: s[i] = " << s[i] << endl;
		cout << "DEBUG: r = " << r << endl;
		if (!a.empty())
		{
			cout << "DEBUG: stack_last_el = " << a.top() << endl;
		}
		else
		{
			cout << "DEBUG: stack is empty" << endl;
		}
		a_copy = a;
		cout << "DEBUG: stack: ";
		while (!a_copy.empty())
		{
			cout << a_copy.top() << ' ';
			a_copy.pop();

		}
		cout << endl << endl;*/

	}
	while (!a.empty())
	{
		r += a.top();
		a.pop();
	}
	s = r;
}

int f2()
{
	char x;
	int num;
	stack <int> a;

	while (cin >> x)
	{
		if (x >= '0' && x <= '9')
		{
			cin.putback(x);
			cin >> num;
			a.push(num);
		}
		if (x == '+' || x == '-' || x == '*' || x == '/')
		{
			int n = a.top();
			a.pop();
			int m = a.top();
			a.pop();

			if (x == '+')
			{
				a.push(m + n);
			}
			else if (x == '-')
			{
				a.push(m - n);
			}
			else if (x == '*')
			{
				a.push(m * n);
			}
			else if (x == '/')
			{
				a.push(m / n);
			}
		}

		//DEBUG
		/*stack <int> a_copy = a;
		cout << endl << "DEBUG: " << endl << "stack: ";
		while (!a_copy.empty())
		{
			cout << a_copy.top() << ' ';
			a_copy.pop();
		}
		cout << endl << endl;*/
		//DEBUG

	}
	return a.top();
}

int main()
{
	string s = "";
	cin >> s;

	string inpt = s;

	// 3+4*2/(1-5)

	f1(s);
	cout << endl << "Reverse Polish notation: " << s << endl << endl;

	cout << "Enter the resulting expression with spaces: ";

	cout << endl << "Result: " << inpt << " = " << f2() << endl << endl;

	return EXIT_SUCCESS;
}