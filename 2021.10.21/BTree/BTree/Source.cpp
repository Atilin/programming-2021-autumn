#include <iostream>
using namespace std;

struct BNode
{
	int data;
	BNode* left, * right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) : data(d), left(l), right(r) {}
};

void f_print(BNode* r, int skip = 0) // skip - отступ
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
		f_print(root);
	}

	void beautiful_print()
	{
		cout << endl << "------------------" << endl;
		print();
		cout << "------------------" << endl << endl;
	}

	BNode* leftmost()
	{
		BNode* current = root;
		while (current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}

	void del_leftmost()
	{
		BNode* current = root;
		BNode* father = root;
		while (current->left != nullptr)
		{
			father = current;
			current = current->left;
		}
		father->left = current->right;
		delete current;
	}

	void insert_leftmost(int x)
	{
		BNode* current = root;
		while (current->left != nullptr)
		{
			current = current->left;
		}
		BNode* v = new BNode(x, nullptr, nullptr);
		current->left = v;
	}

	BNode* leftmost_leaf()
	{
		BNode* current = root;
		while (current->left != nullptr || current->right != nullptr)
		{
			if (current->left != nullptr)
			{
				current = current->left;
			}
			else if (current->right != nullptr)
			{
				current = current->right;
			}
		}
		return current;
	}

	void del_leftmost_leaf()
	{
		BNode* current = root;
		BNode* father = root;
		while (current->left != nullptr || current->right != nullptr)
		{
			if (current->left != nullptr)
			{
				father = current;
				current = current->left;
			}
			else if (current->right != nullptr)
			{
				father = current;
				current = current->right;
			}
		}
		if (father->left == current)
		{
			father->left = nullptr;
		}
		else if (father->right == current)
		{
			father->right = nullptr;
		}
		delete current;
	}

	BNode* second_leaf()
	{
		BNode* current = root;
		BNode* second_start = root;
		while (current->left != nullptr || current->right != nullptr)
		{
			if (current->left != nullptr)
			{
				if (current->right != nullptr)
				{
					second_start = current->right;
				}
				current = current->left;
			}
			else if (current->right != nullptr)
			{
				current = current->right;
			}
		}
		current = second_start;
		while (current->left != nullptr || current->right != nullptr)
		{
			if (current->left != nullptr)
			{
				current = current->left;
			}
			else if (current->right != nullptr)
			{
				current = current->right;
			}
		}
		return current;
	}
};

int main()
{
	BNode* p1 = new BNode(1),
		* p4 = new BNode(4),
		* p7 = new BNode(7),
		* p13 = new BNode(13),
		* p6 = new BNode(6, p4, p7),
		* p14 = new BNode(14, p13),
		* p10 = new BNode(10, nullptr, p14),
		* p3 = new BNode(3, p1, p6),
		* p8 = new BNode(8, p3, p10);

	BTree t(p8);

	t.beautiful_print();

	cout << "LEFTMOST:  " << t.leftmost()->data << endl;

	t.beautiful_print();

	cout << "DEL_LEFTMOST:" << endl;
	t.del_leftmost();

	t.beautiful_print();

	cout << "INSERT_LEFTMOST:  enter x: ";
	int x;
	cin >> x;
	t.insert_leftmost(x);

	t.beautiful_print();

	cout << "LEFTMOST_LEAF:  " << t.leftmost_leaf()->data << endl;

	t.beautiful_print();

	cout << "DEL_LEFTMOST_LEAF:" << endl;
	t.del_leftmost_leaf();

	t.beautiful_print();

	cout << "SECOND_LEAF:  " << t.second_leaf()->data << endl;

	t.beautiful_print();

	return EXIT_SUCCESS;
}