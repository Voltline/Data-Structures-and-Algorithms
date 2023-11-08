#include <iostream>
using namespace std;

struct Node
{
	Node* prev;
	int value;
	Node* next;
};

struct List
{
	Node* anchor;
	Node* tail;

	List()
	{
		anchor = new Node;
		tail = new Node;
		anchor->next = tail;
		anchor->prev = tail;
		anchor->value = -1;
		tail->next = anchor;
		tail->prev = anchor;
		tail->value = -1;
	}

	~List()
	{
		Node* p{ tail }, * q{ tail };
		while (p != anchor) {
			p = q->prev;
			delete q;
			q = p;
		}
		delete anchor;
	}

	List& insert(int value)
	{
		if (tail->value == -1) {
			tail->value = value;
		}
		else {
			Node* p{ new Node{nullptr, value, nullptr} };
			p->next = anchor;
			p->prev = tail;
			tail->next = p;
			tail = p;
			anchor->prev = tail;
		}
		return *this;
	}

	List& del(int value)
	{
		bool hasValue{ false };
		Node* p{ anchor->next }, * q{ nullptr };
		if (tail->prev == anchor) {
			if (tail->value == value) {
				tail->value = -1;
				hasValue = true;
			}
		}
		else {
			while (p != tail) {
				if (p->value == value) {
					q = p->prev;
					p->prev->next = p->next;
					p->next->prev = q;
					q = p;
					p = p->next;
					delete q;
					hasValue = true;
				}
				else p = p->next;
			}
			if (tail->value == value) {
				q = tail->prev;
				q->next = anchor;
				anchor->prev = q;
				delete tail;
				tail = q;
				hasValue = true;
			}
		}
		if (!hasValue) cout << -1 << endl;
		return *this;
	}

	void print()
	{
		if (tail->value != -1) {
			Node* p{ anchor->next };
			while (p != anchor) {
				cout << p->value << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
};

int main()
{
	List ls;
	int val{ 0 };
	do {
		cin >> val;
		if (val != -1) {
			ls.insert(val);
		}
	} while (val != -1);

	do {
		cin >> val;
		if (val != -1) {
			ls.del(val);
		}
	} while (val != -1);

	ls.print();
	return 0;
}
