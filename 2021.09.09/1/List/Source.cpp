#include <iostream>

using namespace std;

struct Node
{
	int data; // элемент данных
	Node* next; // указатель на следующий узел
	Node(int d = 0, Node* n = nullptr) : data(d), next(n) {}
	// конструктор
};

struct List
{
	Node* head;
	List() { head = nullptr; }
	// конструктор, создающий пустой список

	void add_first(int d)
	{
		Node* tmp; // указатель на новый узел
		tmp = new Node(d, head);

		// выделили память и заполнили поля

		head = tmp; // установили новое начало списка
	}

	void print()
	{
		Node* p = head; // указатель p пробегает все элементы
		// списка, начиная с того, на который указывает head
		while (p != nullptr)
		{
			cout << p->data << "\t";
			p = p->next; // переход к следующему элементу
		}
		cout << endl;
	}

	Node* returnLast()
	{
		Node* last = head;
		while (last->next != nullptr)
		{
			last = last->next;
		}
		return last;
	}

	Node* returnPrelast()
	{
		Node* prelast = head;
		while (prelast->next->next != nullptr)
		{
			prelast = prelast->next;
		}
		return prelast;
	}

	Node* returnN(int n)
	{
		Node* p = head;
		for (int i = 1; i < n; ++i)
		{
			p = p->next;
		}
		return p;
	}

	void add_after_first(int d)
	{
		Node* tmp;
		tmp = new Node(d, head->next);
		head->next = tmp;
	}

	void add_last(int d, List l)
	{
		Node* tmp;
		tmp = new Node(d, nullptr);
		l.returnLast()->next = tmp;
	}

	void del_last(List l)
	{
		if (head == nullptr)
		{
			cout << "Empty" << endl;
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		Node* prelast = head;
		while (prelast->next->next != nullptr)
		{
			prelast = prelast->next;
		}
		delete prelast->next;
		prelast->next = nullptr;
	}

};

int main()
{
	List l;
	l.add_first(56);
	l.add_first(23);
	l.add_first(6);
	l.add_first(18);
	l.add_first(4);

	l.print();

	cout << "returnLast:   " << l.returnLast()->data << endl;

	cout << "returnPrelast:   " << l.returnPrelast()->data << endl;

	cout << "returnN: please, input N-number:   ";
	int n;
	cin >> n;
	cout << l.returnN(n)->data << endl;

	cout << "add_after_first: please, input D-number:   ";
	int d;
	cin >> d;
	l.add_after_first(d);
	l.print();

	cout << "add_last: please, input D-number:   ";
	cin >> d;
	l.add_last(d, l);
	l.print();

	cout << "del_last: " << endl;
	l.del_last(l);
	l.print();

	return EXIT_SUCCESS;
}