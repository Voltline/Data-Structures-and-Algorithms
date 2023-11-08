#include <iostream>
#include <vector>
using namespace std;

int n{ 0 }, book[100000]{ 0 }, row[100000]{ 0 }, tmp[100000]{ 0 }, res{ 0 };


void dfs(int pos) // pos行
{
	if (pos == n) {
		res++;
		for (int i = 0; i < n; i++) {
			tmp[i] = row[i];
		}
		return;
	}
	int flag{ 0 };
	for (int j = 0; j < n; j++) {
		if (book[j] == 0) { // 如果第j列没有走过，就开始准备走这列
			flag = 1;
		}
		else continue; // 否则跳过
		for (int i = 0; i < pos; i++) {  // 从头开始搜，一直搜到第pos行
			if (abs(pos - i) == abs(row[i] - j)) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			row[pos] = j;
			book[j] = 1;
			dfs(pos + 1);
			book[j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if (n > 10) {
		if (n % 6 != 2 && n % 6 != 3) {
			if (n % 2 == 0) {
				for (int i = 2; i <= n; i += 2) cout << i-1 << " ";
				for (int i = 1; i <= n-1; i += 2) cout << i-1 << " ";
			}
			else {
				for (int i = 2; i <= n - 1; i += 2) cout << i-1 << " ";
				for (int i = 1; i <= n; i += 2) cout << i-1 << " ";
			}
		}
		else {
			int k{ 0 };
			if (n % 2 == 0) k = n / 2;
			else k = (n - 1) / 2;
			if (k % 2 == 0 && n % 2 == 0) {
				for (int i = k; i <= n; i += 2) cout << i-1 << " ";
				for (int i = 2; i <= k - 2; i += 2) cout << i-1 << " ";
				for (int i = k + 3; i <= n - 1; i += 2) cout << i-1 << " ";
				for (int i = 1; i <= k + 1; i += 2) cout << i-1 << " ";
			}
			else if (k % 2 == 0 && n % 2 == 1) {
				for (int i = k; i <= n - 1; i += 2) cout << i-1 << " ";
				for (int i = 2; i <= k - 2; i += 2) cout << i-1 << " ";
				for (int i = k + 3; i <= n - 2; i += 2) cout << i-1 << " ";
				for (int i = 1; i <= k + 1; i += 2) cout << i-1 << " ";
				cout << n - 1 << " ";
			}
			else if (k % 2 == 1 && n % 2 == 0) {
				for (int i = k; i <= n - 1; i += 2) cout << i-1 << " ";
				for (int i = 1; i <= k - 2; i += 2) cout << i-1 << " ";
				for (int i = k + 3; i <= n; i += 2) cout << i-1 << " ";
				for (int i = 2; i <= k + 1; i += 2) cout << i-1 << " ";
			}
			else {
				for (int i = k; i <= n - 2; i += 2) cout << i-1 << " ";
				for (int i = 1; i <= k - 2; i += 2) cout << i-1 << " ";
				for (int i = k + 3; i <= n - 1; i += 2) cout << i-1 << " ";
				for (int i = 2; i <= k + 1; i += 2) cout << i-1 << " ";
				cout << n-1 << " ";
			}
		}
	}
	else {
		dfs(0);
		if (res) {
			for (int i = 0; i < n; i++) {
				cout << tmp[i] << " ";
			}
		}
		else {
			cout << -1;
		}
	}
	cout << endl;
	return 0;
}
