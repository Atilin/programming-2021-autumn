#include <iostream>
#include <algorithm>
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

void f_del(BNode * &p) // указатель p передается по ссылке
{
	if (p == nullptr) // дерево пусто
		return;
	f_del(p->left); // удалить левое поддерево
	f_del(p->right); // удалить правое поддерево
	delete p; // удалить сам узел
	p = nullptr; // обнулить указатель
}

void f_del0(BNode * &current)
{
	if (current != nullptr)
	{
		if (current->data == 0)
		{
			f_del(current);
		}
		else
		{
			f_del0(current->left);
			f_del0(current->right);
		}
	}
}
void f_delLeaves(BNode * &current)
{
	if (current != nullptr)
	{
		if (current->left == nullptr && current->right == nullptr)
		{
			delete current;
			current = nullptr;
		}
		else
		{
			f_delLeaves(current->left);
			f_delLeaves(current->right);
		}
	}
}
void f_enlarge(int d, BNode * &current)
{
	if (current != nullptr)
	{
		if (current->left == nullptr)
		{
			current->left = new BNode(d);
		}
	}
}

struct BTree
{
	BNode* root;//ukazatel na koren
	BTree(BNode* p) : root(p) {}

	~BTree()
	{
		f_del(root); // удалить дерево
	}

	void print()
	{
		cout << endl << "------------------" << endl;
		f_print(root);
		cout << "------------------" << endl << endl;
	}

	void del0()
	{
		f_del0(root);
	}
	void delLeaves()
	{
		f_delLeaves(root);
	}

};

int main()
{
	BNode* p1 = new BNode(1),
		* p4 = new BNode(4),
		* p7 = new BNode(-7),
		*p13 = new BNode(0),
		*p6 = new BNode(6, p4, p7),
		*p14 = new BNode(0, p13),
		*p10 = new BNode(10, nullptr, p14),
		*p3 = new BNode(3, p1, p6),
		*p8 = new BNode(8, p3, p10);

	BTree t(p8);

	t.print();

	//cout << "DEL0:";
	//t.del0();

	t.print();

	//cout << "DEL_LEAVES:";
	//t.delLeaves();

	t.print();


	return EXIT_SUCCESS;
}