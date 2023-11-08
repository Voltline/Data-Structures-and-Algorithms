#include <iostream>
using namespace std;

int n{ 0 }, book[15]{ 0 }, row[15]{ 0 }, tmp[15]{ 0 }, res{ 0 };

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
			if ((abs(pos-i) == abs(row[i]-j))) {
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
	cin >> n;
	dfs(0);
	cout << res << endl;
	if (res) {
		for (int i = 0; i < n; i++) {
			cout << tmp[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
