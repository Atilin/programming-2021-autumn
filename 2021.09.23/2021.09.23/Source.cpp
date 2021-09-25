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
		//t = new DNode(d, head, nullptr);
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

	cout << "add_last: " << endl;
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

	return EXIT_SUCCESS;
}