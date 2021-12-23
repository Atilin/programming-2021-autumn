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
	~BNode()
	{
		delete left;
		delete right;
	}
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

void print(BNode * r)
{
	cout << "-------------------------" << endl;
	f_print(r);
	cout << "-------------------------" << endl;
}

void skipBrackets(string s, int& i)
{
	--i;
	while (i >= 0 && s[i] != '(')
	{
		if (s[i] == ')')
		{
			skipBrackets(s, i);
		}
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

bool isSameBracket(string s, int beg, int end)
{
	int countBrackets = 0;
	int i = end - 1;
	while (i >= beg)
	{
		if (s[i] == ')')
		{
			++countBrackets;
		}
		else if (s[i] == '(')
		{
			--countBrackets;
		}
		if (countBrackets == 0 && i > beg)
		{
			return false;
		}
		--i;
	}
	return true;
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
	int ind4 = 0;

	bool flag5 = 0;
	int ind5 = 0;

	if (s[end - 1] == ')')
	{
		if (isSameBracket(s, beg, end))
		{
			++beg;
			--end;
		}
	}

	for (int i = end - 1; i >= beg; --i)
	{
		if (s[i] == ')')
		{
			skipBrackets(s, i);
		}
		else if (flag4 == 0 && s[i] == '+')
		{
			flag4 = 1;
			ind4 = i;
		}
		else if (flag5 == 0 && s[i] == '-')
		{
			flag5 = 1;
			ind5 = i;
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
		else if (s[i] == '^')
		{
			flag3 = 1;
			ind3 = i;
		}
	}
	if (flag4 == 1 && flag5 == 1)
	{
		if (ind4 > ind5)
		{
			current->data = "+";
			current->left = new BNode("");
			current->right = new BNode("");
			makeTree(s, current->left, beg, ind4);
			makeTree(s, current->right, ind4 + 1, end);
		}
		else
		{
			current->data = "-";
			current->left = new BNode("");
			current->right = new BNode("");
			makeTree(s, current->left, beg, ind5);
			makeTree(s, current->right, ind5 + 1, end);
		}
	}
	else if (flag4 == 1)
	{
		current->data = "+";
		current->left = new BNode("");
		current->right = new BNode("");
		makeTree(s, current->left, beg, ind4);
		makeTree(s, current->right, ind4 + 1, end);
	}
	else if (flag5 == 1)
	{
		current->data = "-";
		current->left = new BNode("");
		current->right = new BNode("");
		makeTree(s, current->left, beg, ind5);
		makeTree(s, current->right, ind5 + 1, end);
	}
	else if (flag1 == 1 && flag2 == 1)
	{
		if (ind1 > ind2)
		{
			current->data = "*";
			current->left = new BNode("");
			current->right = new BNode("");
			makeTree(s, current->left, beg, ind1);
			makeTree(s, current->right, ind1 + 1, end);
		}
		else
		{
			current->data = "/";
			current->left = new BNode("");
			current->right = new BNode("");
			makeTree(s, current->left, beg, ind2);
			makeTree(s, current->right, ind2 + 1, end);
		}
	}
	else if (flag1 == 1)
	{
		current->data = "*";
		current->left = new BNode("");
		current->right = new BNode("");
		makeTree(s, current->left, beg, ind1);
		makeTree(s, current->right, ind1 + 1, end);
	}
	else if (flag2 == 1)
	{
		current->data = "/";
		current->left = new BNode("");
		current->right = new BNode("");
		makeTree(s, current->left, beg, ind2);
		makeTree(s, current->right, ind2 + 1, end);
	}
	else if (flag3 == 1)
	{
		current->data = "^";
		current->left = new BNode("");
		current->right = new BNode("");
		makeTree(s, current->left, beg, ind3);
		makeTree(s, current->right, ind3 + 1, end);
	}
	else if ((end - beg) >= 5 && s[beg] == 's' && s[beg + 1] == 'i' && s[beg + 2] == 'n')
	{
		current->data = "sin";
		current->left = new BNode("");
		makeTree(s, current->left, beg + 4, end - 1);
	}
	else if ((end - beg) >= 5 && s[beg] == 'c' && s[beg + 1] == 'o' && s[beg + 2] == 's')
	{
		current->data = "cos";
		current->left = new BNode("");
		makeTree(s, current->left, beg + 4, end - 1);
	}
	else if ((end - beg) >= 4 && s[beg] == 't' && s[beg + 1] == 'g')
	{
		current->data = "tg";
		current->left = new BNode("");
		makeTree(s, current->left, beg + 3, end - 1);
	}
	else if ((end - beg) >= 5 && s[beg] == 'c' && s[beg + 1] == 't' && s[beg + 2] == 'g')
	{
		current->data = "ctg";
		current->left = new BNode("");
		makeTree(s, current->left, beg + 4, end - 1);
	}

	else
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
	}
	++i;
	while (i < s.size())
	{
		expr += s[i];
		++i;
	}
}

void isFits(BNode * tree, BNode * subtree, bool& flagFits, vector <pair<string, vector<BNode*>>> & knots)//можно ли наложить дерево функции на исходное дерево
{
	if (flagFits == 0)
	{
		return;
	}

	//cout << "DEBUG: F1 FLAG_FITS: " << flagFits << endl;

	if (tree != nullptr && subtree != nullptr)
	{
		//cout << "DEBUG: F2 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

		if (tree->data == subtree->data)
		{

			//cout << "DEBUG: F3 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;
			isFits(tree->left, subtree->left, flagFits, knots);
			isFits(tree->right, subtree->right, flagFits, knots);
			return;
		}
		if (tree->data == "+" || tree->data == "-" || tree->data == "*" || tree->data == "/" || tree->data == "^" || tree->data == "sin" || tree->data == "cos" || tree->data == "tg" || tree->data == "ctg")
		{

			//cout << "DEBUG: F4 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

			if (subtree->data == "+" || subtree->data == "-" || subtree->data == "*" || subtree->data == "/" || subtree->data == "^" || subtree->data == "sin" || subtree->data == "cos" || subtree->data == "tg" || subtree->data == "ctg") //если операции не совпадают
			{

				//cout << "DEBUG: F5 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

				if (tree->data != subtree->data)
				{

					//cout << "DEBUG: F6 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

					flagFits = false;
				}
			}
			if (subtree->data[0] >= '0' && subtree->data[0] <= '9') //ставим на место операции цифру
			{

				//cout << "DEBUG: F7 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

				flagFits = false;
			}
		}
		if ((tree->data[0] >= 'a' && tree->data[0] <= 'z') || (tree->data[0] >= 'A' && tree->data[0] <= 'Z'))
		{

			//cout << "DEBUG: F8 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

			if (subtree->data[0] >= '0' && subtree->data[0] <= '9') //ставим на место переменной число
			{

				//cout << "DEBUG: F9 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

				flagFits = false;
			}
			if (subtree->data == "+" || subtree->data == "-" || subtree->data == "*" || subtree->data == "/" || subtree->data == "^" || subtree->data == "sin" || subtree->data == "cos" || subtree->data == "tg" || subtree->data == "ctg") //ставим на место переменной операцию
			{

				//cout << "DEBUG: F10 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

				flagFits = false;
			}
		}
		if (tree->data[0] >= '0' && tree->data[0] <= '9')
		{

			//cout << "DEBUG: F11 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

			if (subtree->data[0] >= '0' && subtree->data[0] <= '9' && tree->data != subtree->data) //числа не совпадают 
			{

				//cout << "DEBUG: F12 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

				flagFits = false;
			}
			if (subtree->data == "+" || subtree->data == "-" || subtree->data == "*" || subtree->data == "/" || subtree->data == "^" || subtree->data == "sin" || subtree->data == "cos" || subtree->data == "tg" || subtree->data == "ctg") //ставим на место числа операцию
			{

				//cout << "DEBUG: F13 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

				flagFits = false;
			}
		}
		if ((subtree->data[0] >= 'a' && subtree->data[0] <= 'z') || (subtree->data[0] >= 'A' && subtree->data[0] <= 'Z'))//
		{

			//cout << "DEBUG: F14 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

			if (subtree->data != "sin" && subtree->data != "cos" && subtree->data != "tg" && subtree->data != "ctg")
			{
				for (int i = 0; i < knots.size(); ++i)//если имя такое же как в векторе knots, то добавить ссылку на этот узел
				{

					//cout << "DEBUG: F15 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

					if (knots[i].first == subtree->data)
					{

						//cout << "DEBUG: F16 FLAG_FITS: " << flagFits << " TREE_DATA: " << tree->data << " SUBTREE_DATA: " << subtree->data << endl;

						//cout << "IFFITS: " << knots[i].first << endl;
						knots[i].second.push_back(tree);
						//cout << "KNOTS[" << i << "].SECOND.SIZE() == " << knots[i].second.size() << endl;
						break;
					}
				}
			}
		}
	}
}

void countVariable(string name, vector <pair<string, vector<BNode*>>> & knots, vector <pair<string, string>> & nameAndInterpretation)//считает количество различных переменных и заполняет вектор этими переменными
{
	int i = 0;
	while (name[i] != '(')
	{
		++i;
	}
	++i;
	while (name[i] != ')')
	{
		string s = "";
		while (name[i] != ',' && name[i] != ')')
		{
			s += name[i];
			++i;
		}
		pair<string, vector < BNode*>> p;
		p.first = s;
		knots.push_back(p);

		pair<string, string> q;
		q.first = s;
		nameAndInterpretation.push_back(q);

		if (name[i] == ')')
		{
			--i;
		}
		++i;
	}
}

void isEqualSubtrees(BNode * branch1, BNode * branch2, bool& flagEqual)//совпадают ли ветви исходного дерева
{
	if (flagEqual == true)
	{
		if (branch1 != nullptr && branch2 != nullptr)
		{
			if (branch1->data == branch2->data)
			{
				isEqualSubtrees(branch1->left, branch2->left, flagEqual);
				isEqualSubtrees(branch1->right, branch2->right, flagEqual);
			}
			else
			{
				flagEqual = false;
			}
		}
		if ((branch1 == nullptr && branch2 != nullptr) || (branch1 != nullptr && branch2 == nullptr))
		{
			flagEqual = false;
		}
	}
}

void countKnots(BNode * current, int& n)
{
	if (current != nullptr)
	{
		n++;
		countKnots(current->left, n);
		countKnots(current->right, n);
	}
}

void cleverCountKnots(BNode * tree, BNode * subtree, int& n)
{
	if (subtree != nullptr)
	{
		if (subtree->left == nullptr)
		{
			if (tree->left == nullptr)
			{
				n++;
			}
		}
		else
		{
			n++;
			cleverCountKnots(tree->left, subtree->left, n);
			cleverCountKnots(tree->right, subtree->right, n);
		}
	}
}

void fillNameAndInterpretation(BNode * tree, BNode * subtree, vector <pair<string, string>> & nameAndInterpretation)
{
	if (subtree != nullptr)
	{
		if (subtree->left == nullptr)
		{
			for (int i = 0; i < nameAndInterpretation.size(); ++i)
			{
				if (nameAndInterpretation[i].first == subtree->data)
				{
					if (tree->data == "+" || tree->data == "-" || tree->data == "*" || tree->data == "/" || tree->data == "^" || tree->data == "sin" || tree->data == "cos" || tree->data == "tg" || tree->data == "ctg")
					{
						nameAndInterpretation[i].second = "";
					}
					else
					{
						nameAndInterpretation[i].second = tree->data;
					}
				}
			}
		}
		fillNameAndInterpretation(tree->left, subtree->left, nameAndInterpretation);
		fillNameAndInterpretation(tree->right, subtree->right, nameAndInterpretation);
	}
}

bool isSelfsame(BNode * subtree)
{
	if (subtree->data != "sin" && subtree->data != "cos" && subtree->data != "tg" && subtree->data != "ctg")
	{
		if (subtree->data[0] >= 'a' && subtree->data[0] <= 'z')
		{
			return 1;
		}
	}
	return 0;
}
bool isNoOperations(BNode * root)
{
	if (root->data != "sin" && root->data != "cos" && root->data != "tg" && root->data != "ctg" && root->data != "+" && root->data != "-" && root->data != "*" && root->data != "/" && root->data != "^")
	{
		return 1;
	}
	return 0;
}

void composition(BNode * currentRoot, vector <BNode*> funcRoots, vector <string> funcNames, int allKnots, int& currentNumberOfKnots, bool& isYeah, string & output)
{
	if (isYeah == true)
	{
		return;
	}

	for (int i = 0; i < funcRoots.size(); ++i)
	{
		if (isYeah == true)
		{
			break;
		}

		if (isSelfsame(funcRoots[i]))
		{
			++i;
			if (i == funcRoots.size())
			{
				break;
			}
		}

		bool flagFits = 1;
		vector <pair<string, vector<BNode*>>> knots;
		vector <pair<string, string>> nameAndInterpretation;

		countVariable(funcNames[i], knots, nameAndInterpretation);

		isFits(currentRoot, funcRoots[i], flagFits, knots);

		//cout << "DEBUG 1: testing function " << i + 1 << " output=" << output << endl;

		if (flagFits == 1)
		{

			//cout << "DEBUG: C2" << " output=" << output << endl;

			for (int j = 0; j < knots.size(); ++j)//проверка на одинаковость поддеревьев
			{

				//cout << "DEBUG: C3" << " output=" << output << endl;

				if (knots[j].second.size() > 1)
				{

					//cout << "DEBUG: C4" << " output=" << output << endl;

					for (int k = 1; k < knots[j].second.size(); ++k)
					{

						//cout << "DEBUG: C5" << " output=" << output << endl;

						bool flagEqual = 1;
						isEqualSubtrees(knots[j].second[0], knots[j].second[k], flagEqual);
						if (flagEqual == 0)
						{

							//cout << "DEBUG: C6" << " output=" << output << endl;

							flagFits = 0;
							break;
						}
					}
					if (flagFits == 0)
					{

						//cout << "DEBUG: C7" << " output=" << output << endl;

						break;
					}
				}
			}
			if (flagFits == 1)
			{

				for (int a = 0; funcNames[i][a] != '('; ++a)
				{
					output += funcNames[i][a];
				}

				//cout << "DEBUG: C8" << " output=" << output << endl;

				int n = 0;
				cleverCountKnots(currentRoot, funcRoots[i], n);
				currentNumberOfKnots += n;
				//cout << "CURRENT_NUMBER_OF_KNOTS: " << currentNumberOfKnots << endl;
				//cout << "NUMBER_OF_ALL_KNOTS: " << allKnots << endl;

				if (currentNumberOfKnots == allKnots)
				{

					//cout << "DEBUG: C9" << " output=" << output << endl;

					isYeah = true;
				}


				//cout << "DEBUG: C10" << " output=" << output << endl;
				//cout <<"KNOTS_SIZE: "<< knots.size()<<endl;
				//cout << "KNOTS[0].SECOND.SIZE(): " << knots[0].second.size() << endl;

				output += '(';

				fillNameAndInterpretation(currentRoot, funcRoots[i], nameAndInterpretation);

				//cout << "DEBUG: C11" << " output=" << output << endl;

				for (int m = 0; m < knots.size(); ++m)
				{

					//cout << "DEBUG: C12" << " output=" << output << endl;

					int r = 0;

					//cout << "KNOTS[" << m << "].SECOND.SIZE() == " << knots[m].second.size() << endl;
					if (knots[m].second.size() > 0)
					{
						countKnots(knots[m].second[0], r);//посчитали количество узлов в одном из одинаковых поддеревьев
						currentNumberOfKnots += r * (knots[m].second.size() - 1);//заполнили те ветки, которые не рассматриваем

						composition(knots[m].second[0], funcRoots, funcNames, allKnots, currentNumberOfKnots, isYeah, output);
					}
					//cout << "DEBUG: C13" << " output=" << output << endl;

					output += nameAndInterpretation[m].second;

					if (m < knots.size() - 1)
					{
						output += ',';
					}
				}

				output += ')';
			}
		}
		if (flagFits == 1)
		{
			break;
		}
	}
}

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	string expression;
	fin >> expression;

	vector <string> funcNames;
	vector <BNode*> funcRoots;
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

		funcRoots.push_back(root);
	}

	BNode* root = new BNode("");
	makeTree(expression, root, 0, expression.size());

	print(root);
	for (int i = 0; i < funcRoots.size(); ++i)
	{
		print(funcRoots[i]);
	}

	if (isNoOperations(root))
	{
		for (int i = 0; i < funcRoots.size(); ++i)
		{
			if (isSelfsame(funcRoots[i]))
			{
				for (int j = 0; funcNames[i][j] != '('; ++j)
				{
					fout << funcNames[i][j];
				}
				fout << '(';
				fout << expression;
				fout << ')';
				break;
			}
		}
	}
	else
	{
		string output = "";
		int allKnots = 0;
		countKnots(root, allKnots);
		int currentNumberOfKnots = 0;
		bool isYeah = false;
		composition(root, funcRoots, funcNames, allKnots, currentNumberOfKnots, isYeah, output);
		if (isYeah == 0)
		{
			fout << "IMPOSSIBLE" << endl;
		}
		else
		{
			fout << output << endl;
		}
		//cout << "FINAL_OUTPUT: " << output << endl;
	}


	fout.close();
	fin.close();

	return EXIT_SUCCESS;
}