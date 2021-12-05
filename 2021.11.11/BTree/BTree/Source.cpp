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
void f_scale(BNode * current)
{
	if (current != nullptr)
	{
		(current->data) *= 3;
		f_scale(current->left);
		f_scale(current->right);
	}
}
int f_sum(BNode * current)
{
	if (current == nullptr)
	{
		return 0;
	}
	return current->data + f_sum(current->left) + f_sum(current->right);
}
int f_count_neg(BNode * current)
{
	if (current == nullptr)
	{
		return 0;
	}
	return (current->data < 0) ? 1 : 0 + f_count_neg(current->left) + f_count_neg(current->right);
}
int f_height(BNode * current)
{
	if (current == nullptr)
	{
		return 0;
	}
	return 1 + max(f_height(current->left), f_height(current->right));
}
void f_reflect(BNode * current)
{
	if (current != nullptr)
	{
		swap(current->left, current->right);
		f_reflect(current->left);
		f_reflect(current->right);
	}
}
int f_mult(BNode * current)
{
	if (current == nullptr)
	{
		return 1;
	}
	return ((current->left != nullptr && current->right != nullptr) ? current->data : 1) * f_mult(current->left) * f_mult(current->right);
}
int f_eval(BNode * current)
{
	if (current->left == nullptr && current->right == nullptr)
	{
		return current->data;
	}
	if (current->left != nullptr && current->right != nullptr && current->data == 1)
	{
		return f_eval(current->left) + f_eval(current->right);
	}
	if (current->left != nullptr && current->right != nullptr && current->data == 2)
	{
		return f_eval(current->left) - f_eval(current->right);
	}
	if (current->left != nullptr && current->right != nullptr && current->data == 3)
	{
		return f_eval(current->left)* f_eval(current->right);
	}
	if (current->left != nullptr && current->right != nullptr && current->data == 4)
	{
		return f_eval(current->left) / f_eval(current->right);
	}
}
BNode* f_rightmost(BNode * current)
{
	if (current == nullptr)
		return current;
	while (current->right != nullptr)
	{
		current = current->right;
	}
	return current;
}
//template <class T>
//BNode* f_find(T d, BNode * current, BNode * rm)
//{
//	if (current != nullptr)
//	{
//		if (d == current->data)
//		{
//			return current;
//		}
//		f_find(d, current->left, rm);
//		f_find(d, current->right, rm);
//		if (current == rm)
//		{
//			return nullptr;
//		}
//	}
//}


template <class T>
BNode* f_find1(T d, BNode * current)
{
	BNode* p;
	if (current == nullptr)
	{
		return nullptr;
	}

	if (d == current->data)
	{
		return current;
	}
	p=f_find1(d, current->left);
	if (p != nullptr)
		return p;
	else
		return f_find1(d, current->right);
}

int f_min(int minimum, BNode * current)
{
	if (current != nullptr)
	{
		if (current->data < minimum)
		{
			return min(f_min(current->data, current->left), f_min(current->data, current->right));
		}
		else
		{
			return min(f_min(minimum, current->left), f_min(minimum, current->right));
		}
	}
	return minimum;
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

	void scale()
	{
		f_scale(root);
	}
	int sum()
	{
		return f_sum(root);
	}
	int count_neg()
	{
		return f_count_neg(root);
	}

	int height()
	{
		return f_height(root);
	}
	void reflect()
	{
		f_reflect(root);
	}
	int mult()
	{
		return f_mult(root);
	}
	int eval()
	{
		return f_eval(root);
	}
	BNode* rightmost()
	{
		return f_rightmost(root);
	}
	template <class T>
	BNode* find(T d)
	{
		return f_find1(d, root);
	}
	int min()
	{
		return f_min(INT_MAX, root);
	}
};

int main()
{
	BNode* p1 = new BNode(1),
		* p4 = new BNode(4),
		* p7 = new BNode(-7),
		*p13 = new BNode(13),
		*p6 = new BNode(6, p4, p7),
		*p14 = new BNode(-14, p13),
		*p10 = new BNode(10, nullptr, p14),
		*p3 = new BNode(3, p1, p6),
		*p8 = new BNode(8, p3, p10);

	BTree t(p8);

	t.beautiful_print();

	cout << "SCALE:" << endl;
	t.scale();

	t.beautiful_print();

	cout << "SUM:  " << t.sum() << endl;

	t.beautiful_print();

	cout << "COUNT_NEG:  " << t.count_neg() << endl;

	t.beautiful_print();

	cout << "HEIGHT:  " << t.height() << endl;

	t.beautiful_print();

	cout << "REFLECT:" << endl;
	t.reflect();

	t.beautiful_print();

	cout << "MULT:  " << t.mult() << endl;

	t.beautiful_print();

	BNode * q1 = new BNode(rand() % 100 - 50),
		*q2 = new BNode(rand() % 100 - 50),
		*q4 = new BNode(rand() % 100 - 50),
		*q3 = new BNode(rand() % 4 + 1, q1, q2),
		*q5 = new BNode(rand() % 4 + 1, q3, q4);

	BTree q(q5);

	q.beautiful_print();

	cout << "EVAL:  " << q.eval() << endl;

	q.beautiful_print();

	cout << "enter the number what you want to search: ";
	int d;
	cin >> d;
	cout << "FIND:  " << t.find(d) << endl;

	t.beautiful_print();

	cout << "MIN:  " << t.min() << endl;

	t.beautiful_print();


	return EXIT_SUCCESS;
}