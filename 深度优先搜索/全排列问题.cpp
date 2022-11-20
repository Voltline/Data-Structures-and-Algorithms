#include <iostream>
using namespace std;

namespace n21 {
	int n, * a, * book;

	void dfs(int step);

	int main()
	{
		cin >> n;
		a = new int[n + 1];
		book = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			book[i] = 0;
		}
		dfs(1);
		delete[] a;
		delete[] book;
		return 0;
	}

	void dfs(int step)
	{
		if (step == n + 1) {
			for (int i = 1; i < n + 1; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			return;
		}
		for (int i = 1; i < n + 1; i++) {
			if (book[i] == 0) {
				a[step] = i;
				book[i] = 1;
				dfs(step + 1);
				book[i] = 0;
			}
		}
		return;
	}
}
