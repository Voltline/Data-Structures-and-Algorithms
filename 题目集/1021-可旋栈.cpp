#include <iostream>
#include <deque>
using namespace std;

void push(deque<int>& vstack, bool tail, int value)
{
	if (tail) {
		vstack.push_back(value);
	}
	else {
		vstack.push_front(value);
	}
}

void pop(deque<int>& vstack, bool tail)
{
	if (tail) {
		vstack.pop_back();
	}
	else {
		vstack.pop_front();
	}
}

int main()
{
	deque<int> vstack;
	bool tail{ true };
	int q{ 0 }, choice{ 0 }, cnt{ 0 };
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> choice;
		if (choice == 1) {
			int X{ 0 };
			cin >> X;
			push(vstack, tail, X);
			cnt++;
		}
		else if (choice == 2) {
			pop(vstack, tail);
			cnt--;
		}
		else {
			tail = !tail;
		}

		if (cnt != 0) {
			if (tail) {
				cout << vstack.back() << endl;
			}
			else {
				cout << vstack.front() << endl;
			}
		}
		else cout << -1 << endl;
	}

	return 0;
}
