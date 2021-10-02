#include <iostream>

using namespace std;

struct DNode
{
	int data; // элемент данных
	DNode* next; // указатель на следующий узел
	DNode* prev; // указатель на предыдущий узел
	DNode(int d = 0, DNode* n = nullptr, DNode* p = nullptr) :
		data(d), next(n), prev(p) {} // конструктор
};

struct DList
{
private:
	DNode* head, * tail;
public:
	DList() { head = nullptr; tail = nullptr; }
	// конструктор, создающий пустой список

	int count = 0;

	//DList(const DList& l, DNode*& t)
	//{
	//	head = copy(l.head, t);
	//	tail = t;
	//}
	DList(const DList& l)
	{
		head = copy(l.head);
		tail = head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		count = l.count;
	}

	~DList()
	{
		del();
	}

	void add_first(int d)
	{
		DNode* t;
		t = new DNode;
		t->data = d;
		t->next = head;
		t->prev = nullptr;
		//t = new DNode(d, head, nullptr);

		if (head == nullptr) // если исходный список пустой
		{
			head = t;
			tail = t; // не забываем установить tail
		}
		else
		{
			head->prev = t;
			head = t;
		}
		count++;
	}

	void del_first() // удалить узел из начала списка
	{
		if (head == nullptr)
		{
			cout << "List is empty";
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		DNode* t;
		t = head;
		head = head->next;
		head->prev = nullptr;
		delete t;
		count--;
	}

	void add_last(int d)
	{
		DNode* t;
		t = new DNode;
		t->data = d;
		t->next = nullptr;
		t->prev = tail;

		if (tail == nullptr)
		{
			head = t;
			tail = t;
		}
		else
		{
			tail->next = t;
			tail = t;
		}
		count++;
	}

	void add_after_first(int d)
	{
		DNode* t;
		t = new DNode;
		t->data = d;
		t->next = head->next;
		t->prev = head;
		if (head->next == nullptr)
		{
			head->next = t;
			tail = t;
		}
		else
		{
			head->next->prev = t;
			head->next = t;
		}
		count++;
	}

	void del_last()
	{
		if (tail == nullptr)
		{
			cout << "List is empty";
			return;
		}
		if (tail->prev == nullptr)
		{
			delete tail;
			head = nullptr;
			tail = nullptr;
			return;
		}
		DNode* t;
		t = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete t;
		count--;
	}

	void del_second()
	{
		DNode* t;
		t = head->next;
		if (t == tail)
		{
			tail = tail->prev;
			tail->next = nullptr;
		}
		else
		{
			head->next = head->next->next;
			head->next->prev = head;
		}
		delete t;
		count--;
	}

	void insertp(int index, int d)
	{
		if (index == 0)
		{
			return add_first(d);
		}
		if (index == count)
		{
			return add_last(d);
		}

		DNode* t = head;
		for (int i = 0; i < index - 1; ++i)
		{
			t = t->next;
		}
		t->next = new DNode(d, t->next, t);
		t->next->next->prev = t->next;
		t->next->next->prev->prev = t;
		++count;
	}

	void delp(int index)
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		if (index == 0)
		{
			del_first();
		}
		else if (index == count - 1)
		{
			del_last();
		}
		else
		{
			DNode* t = head;
			for (int i = 0; i < index - 1; ++i)
			{
				t = t->next;
			}
			DNode* p = t->next;
			t->next = t->next->next;
			t->next->prev = t;
			delete p;
			count--;
		}
	}

	void del()
	{
		if (head == nullptr)
		{
			tail = nullptr;
			return;
		}
		DNode* t = head;
		head = head->next;
		delete t;
		del();
	}

	//DNode* copy(DNode * x, DNode*& t)
	//{
	//	if (x == nullptr)
	//		return nullptr;
	//	if (x->next == nullptr)
	//	{
	//		t = new DNode(x->data, nullptr, nullptr);
	//		return t;
	//	}
	//	DNode * y;
	//	y = new DNode(x->data, copy(x->next, t), nullptr);
	//	if (y->next != nullptr)
	//	{
	//		y->next->prev = y;
	//	}
	//	return y;
	//}
	DNode* copy(DNode * x)
	{
		if (x == nullptr)
			return nullptr;
		DNode * y;
		y = new DNode(x->data, copy(x->next), nullptr);
		if (y->next != nullptr)
		{
			y->next->prev = y;
		}
		return y;
	}

	//DList& operator = (const DList & l, DNode*& t)
	//{
	//	if (this == &l) // (a=a)
	//		return *this;
	//	del();
	//	this->head = copy(l.head, t);
	//	return *this;
	//}
	DList& operator = (const DList& l)
	{
		if (this == &l) // (a=a)
			return *this;
		del();
		this->head = copy(l.head);

		tail = head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		//this->tail = tail;
		this->count = l.count;

		return *this;
	}

	void print() // печать в прямом порядке
	{
		DNode* p = head;
		while (p != nullptr)
		{
			cout << p->data << "\t";
			p = p->next; // переход к следующему элементу
		}
		cout << endl;
	}
	void print_reverse() // печать в обратном порядке
	{
		DNode* p = tail;
		while (p != nullptr)

		{
			cout << p->data << "\t";
			p = p->prev; // переход к следующему элементу
		}
		cout << endl;
	}
	void Print() // печать в прямом и обратном порядках
	{
		print();
		print_reverse();
		cout << endl;
	}
}; // конец структуры DList



int main()
{
	DList l; // l пустой список
	l.add_first(3); // добавление
	l.add_first(2);
	l.add_first(1);

	l.Print();

	/*cout << "add_last: " << endl;
	l.add_last(100);
	l.Print();

	cout << "add_after_first: " << endl;
	l.add_after_first(17);
	l.Print();

	cout << "del_last: " << endl;
	l.del_last();
	l.Print();

	cout << "del_second: " << endl;
	l.del_second();
	l.Print();

	cout << "insertp: " << endl << "index: ";
	int index = 0;
	cin >> index;
	cout << "data: ";
	int d = 0;
	cin >> d;
	l.insertp(index, d);
	l.Print();

	cout << "delp: " << endl << "index: ";
	index = 0;
	cin >> index;
	l.delp(index);
	l.Print();*/

	cout << "operator= (l_copy = l):" << endl << "l: " << endl;
	DList l_copy = l;
	l.Print();
	cout << "l_copy: " << endl;
	l_copy.Print();

	return EXIT_SUCCESS;
}