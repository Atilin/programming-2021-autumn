#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct BNode
{
	string data;
	BNode* left, * right;
	BNode(string d, BNode* l = nullptr, BNode* r = nullptr) : data(d), left(l), right(r) {}
};

void f_print(BNode* r, int skip = 0)
{
	if (r == nullptr) return;
	f_print(r->right, skip + 3);
	for (int i = 0; i < skip; ++i)
		cout << ' ';
	cout << r->data << endl;
	f_print(r->left, skip + 3);
}

struct BTree
{
	BNode* root;//ukazatel na koren
	BTree(BNode* p) : root(p) {}

	void print()
	{
		cout << endl << "------------------" << endl;
		f_print(root);
		cout << endl << "------------------" << endl;
	}

};
//
//string highlightName(string s, int& i)
//{
//	string name = "";
//	while (i >= 0 && ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
//	{
//		name += s[i];
//		--i;
//	}
//	reverse(name.begin(), name.end());
//	return name;
//}
//
//string highlightNumber(string s, int& i)
//{
//	string name = "";
//	while (i >= 0 && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == ','))
//	{
//		name += s[i];
//		--i;
//	}
//	reverse(name.begin(), name.end());
//	return name;
//}

void skipBrackets(string s, int& i)
{
	while (i >= 0 && s[i] != '(')
	{
		--i;
	}
	--i;
	if (i >= 1 && s[i] == 'g' && s[i - 1] == 't')
	{
		i -= 2;
		if (i >= 0 && s[i] == 'c')
		{
			--i;
		}
	}
	else if (i >= 2 && (s[i] == 'n' || s[i] == 's'))
	{
		i -= 3;
	}
	++i;
}

void makeTree(string s, BNode * current, int beg, int end)
{
	bool flag1 = 0;
	int ind1 = 0;

	bool flag2 = 0;
	int ind2 = 0;

	bool flag3 = 0;
	int ind3 = 0;

	bool flag4 = 0;

	if (s[end - 1] == ')' && s[beg] == '(')
	{
		--end;
		++beg;
	}

	for (int i = end - 1; i >= beg; --i)
	{
		if (s[i] == ')')
		{
			skipBrackets(s, i);
		}
		else if (s[i] == '+')
		{
			current->data = "+";
			current->left = new BNode("");
			current->right = new BNode("");
			makeTree(s, current->left, beg, i);
			makeTree(s, current->right, i + 1, end);
			return;
		}
		else if (s[i] == '-')
		{
			current->data = "-";
			current->left = new BNode("");
			current->right = new BNode("");
			makeTree(s, current->left, beg, i);
			makeTree(s, current->right, i + 1, end);
			return;
		}
		else if (flag1 == 0 && s[i] == '*')
		{
			flag1 = 1;
			ind1 = i;
		}
		else if (flag2 == 0 && s[i] == '/')
		{
			flag2 = 1;
			ind2 = i;
		}
		else if (flag3 == 0 && s[i] == '^')
		{
			flag3 = 1;
			ind3 = i;
		}
	}
	if (flag1 == 1 && flag2 == 1)
	{
		if (ind1 > ind2)
		{
			current->data = "*";
			current->left = new BNode("");
			current->right = new BNode("");
			makeTree(s, current->left, beg, ind1);
			makeTree(s, current->right, ind1 + 1, end);
			return;
		}
		else
		{
			current->data = "/";
			current->left = new BNode("");
			current->right = new BNode("");
			makeTree(s, current->left, beg, ind2);
			makeTree(s, current->right, ind2 + 1, end);
			return;
		}
	}
	else if (flag1 == 1)
	{
		current->data = "*";
		current->left = new BNode("");
		current->right = new BNode("");
		makeTree(s, current->left, beg, ind1);
		makeTree(s, current->right, ind1 + 1, end);
		return;
	}
	else if (flag2 == 1)
	{
		current->data = "/";
		current->left = new BNode("");
		current->right = new BNode("");
		makeTree(s, current->left, beg, ind2);
		makeTree(s, current->right, ind2 + 1, end);
		return;
	}
	else if (flag3 == 1)
	{
		current->data = "^";
		current->left = new BNode("");
		current->right = new BNode("");
		makeTree(s, current->left, beg, ind3);
		makeTree(s, current->right, ind3 + 1, end);
		return;
	}
	else if ((end - beg) >= 5 && s[beg] == 's' && s[beg + 1] == 'i' && s[beg + 2] == 'n')
	{
		current->data = "sin";
		current->left = new BNode("");
		makeTree(s, current->left, beg + 4, end - 1);
		return;
	}
	else if ((end - beg) >= 5 && s[beg] == 'c' && s[beg + 1] == 'o' && s[beg + 2] == 's')
	{
		current->data = "cos";
		current->left = new BNode("");
		makeTree(s, current->left, beg + 4, end - 1);
		return;
	}
	else if ((end - beg) >= 4 && s[beg] == 't' && s[beg + 1] == 'g')
	{
		current->data = "tg";
		current->left = new BNode("");
		makeTree(s, current->left, beg + 3, end - 1);
		return;
	}
	else if ((end - beg) >= 5 && s[beg] == 'c' && s[beg + 1] == 't' && s[beg + 2] == 'g')
	{
		current->data = "ctg";
		current->left = new BNode("");
		makeTree(s, current->left, beg + 4, end - 1);
		return;
	}

	else if ((s[beg] >= 'A' && s[beg] <= 'Z') || (s[beg] >= 'a' && s[beg] <= 'z'))
	{
		for (int i = beg; i < end; ++i)
		{
			current->data += s[i];
		}
	}
	else if (s[beg] >= '0' && s[beg] <= '9')
	{
		for (int i = beg; i < end; ++i)
		{
			current->data += s[i];
		}
	}
}

void makeNameExpr(string s, string & name, string & expr)
{
	int i = 0;
	while (s[i] != '=')
	{
		name += s[i];
		++i;
		cout << name << endl;
	}
	++i;

	cout << endl;

	while (i < s.size())
	{
		expr += s[i];
		++i;
		cout << expr << endl;
	}
}

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	string expression;
	fin >> expression;

	int funcCount = 0;

	vector <string> funcNames;
	vector <BTree> funcTree;
	while (!fin.eof())
	{
		string str;
		fin >> str;

		string name = "";
		string expr = "";
		makeNameExpr(str, name, expr);

		funcNames.push_back(name);

		BNode* root = new BNode("");
		makeTree(expr, root, 0, expr.size());
		BTree exprTree(root);
		funcTree.push_back(exprTree);


		//fout << str << ' ';

	}
	fout.close();
	fin.close();

	BNode* root = new BNode("");
	makeTree(expression, root, 0, expression.size());
	BTree expr(root);
	expr.print();

	//for (int i = 0; i < funcNames.size(); ++i)
	//{
	//	cout << funcNames[i] << ' ';
	//}

	//for (int i = 0; i < funcTree.size(); ++i)
	//{
	//	funcTree[i].print();
	//}


	return EXIT_SUCCESS;
}