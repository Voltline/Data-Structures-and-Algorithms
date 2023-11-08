#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;

	List()
		: head(new Node{ 0, nullptr })
		, tail(nullptr) {}

	~List()
	{
		Node* p{ head }, * q{ head->next };
		do {
			q = p;
			p = p->next;
			delete q;
		} while (p);
	}

	List& push_back(int x)
	{
		if (!tail) {
			tail = new Node{ x, nullptr };
			head->next = tail;
		}
		else {
			Node* newNode = new Node{ x, nullptr };
			tail->next = newNode;
			tail = newNode;
		}
		head->value++;
		return *this;
	}

	Node* findKth(int k)
	{
		int cnt{ 0 };
		if (k >= 0 && k < head->value) {
			Node* p{ head->next };
			while (p && cnt < k) p = p->next, cnt++;
			return p;
		}
		else return nullptr;
	}

	List& insert(int k, int x)
	{
		Node* p{ head->next };
		if (k < head->value) {
			if (k == 0) {
				Node* newNode = new Node{ x, p };
				head->next = newNode;
			}
			else {
				p = findKth(k);
				Node* newNode = new Node{ x, p->next };
				p->next = newNode;
			}
			head->value++;
		}
		else {
			push_back(x);
		}
		return *this;
	}

	List& del(int k)
	{
		if (k >= 0 && k < head->value) {
			if (k == 0) {
				cout << head->next->value << endl;
				if (head->next == tail) {
					delete tail;
					tail = nullptr;
					head->next = tail;
				}
				else {
					Node* ptr{ head->next };
					head->next = ptr->next;
					delete ptr;
				}
			}
			else {
				Node* nodePtr{ findKth(k - 1) }, * q{ nullptr };
				cout << nodePtr->next->value << endl;
				q = nodePtr->next;
				nodePtr->next = q->next;
				delete q;
			}
			head->value--;
		}
		else {
			cout << -1 << endl;
		}
		return *this;
	}
};

int main()
{
	int n{ 0 };
	cin >> n;
	List ls;
	for (int i = 0; i < n; i++) {
		int temp{ 0 };
		cin >> temp;
		ls.push_back(temp);
	}
	int q{ 0 }, cmd{ 0 }, k{ 0 };
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> cmd >> k;
		k--;
		if (cmd == 1) {
			int x{ 0 };
			cin >> x;
			ls.insert(k, x);
		}
		else {
			ls.del(k);
		}
	}
	return 0;
}
