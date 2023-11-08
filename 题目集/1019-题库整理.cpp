#include <iostream>
#include <vector>
using namespace std;

vector<int> stack(200000);
int hardest{ 0 };
int top{ 0 };

int find_max()
{
	int m{ 0 };
	for (int i = 0; i < top - 1; i++) {
		if (m < stack[i]) m = stack[i];
	}
	return m;
}

int main()
{
	int N{ 0 }, choice{ 0 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> choice;
		if (choice == 0) {
			int X{ 0 };
			cin >> X;
			stack[top++] = X;
			hardest = (X > hardest) ? X : hardest;
		}
		else if (choice == 1) {
			if (top != 0) {
				hardest = find_max();
				top--;
			}
		}
		else {
			cout << hardest << endl;
		}
	}
	return 0;
}
