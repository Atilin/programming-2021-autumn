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
	List()
	{
		head = nullptr;
	}
	// конструктор, создающий пустой список

	Node* copy(Node* x)
	{
		Node* p = nullptr;
		if (x != nullptr)
		{
			p = new Node(x->data, copy(x->next));
		}
		return p;
	}

	List(const List& l)
	{
		head = copy(l.head);
	}

	~List()
	{
		del();
	}

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
		if (p == nullptr)
		{
			cout << "EMPTY" << endl;
			return;
		}
		while (p != nullptr)
		{
			cout << p->data << "\t";
			p = p->next; // переход к следующему элементу
		}
		cout << endl;
	}

	void del()
	{
		if (head == nullptr)
		{
			return;
		}
		Node* t = head;
		head = head->next;
		delete t;
		del();
	}

	List& operator = (const List& l)
	{
		if (this == &l) // проверка на самоприсваивание (a=a)
			return *this;
		del();
		// вызов метода del (или функции del)
		this->head = copy(l.head);                 //почему нельзя написать this.head = copy(l.head);
		// вызов функции copy
		return *this;
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

	cout << "del: " << endl;
	l.del();
	l.print();

	l.add_first(56);
	l.add_first(23);
	l.add_first(6);
	l.add_first(18);
	l.add_first(4);

	List l1;
	l1.add_first(1);
	l1.add_first(2);
	l1.add_first(3);
	l1.add_first(4);
	l1.add_first(5);
	cout << "l1: ";
	l1.print();
	l1 = l;
	cout << "l1 = l" << endl<<"l1: ";
	l1.print();
	cout << "l: ";
	l.print();


	return EXIT_SUCCESS;
}