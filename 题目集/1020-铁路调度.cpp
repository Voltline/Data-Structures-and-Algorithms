#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int k{ 0 };
	cin >> k;
	for (int i = 0; i < k; i++) {
		int n{ 0 };
		string order;
		cin >> n >> order;
		int order_ptr{ 0 };
		stack<int> sim;
		for (int j = 1; j <= n; j++) {
			sim.push(j);
			while (!sim.empty() && sim.top() == order[order_ptr] - '0') {
				sim.pop();
				order_ptr++;
			}
		}
		if (sim.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}
