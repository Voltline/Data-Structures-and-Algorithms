#include <iostream>
// 求解[][][] + [][][] = [][][]的问题（无重复9位数字）
using namespace std;

namespace n22 {
	int a[10] = { 0 }, book[10] = { 0 };

	void dfs_add(int step);

	int main()
	{
		dfs_add(1);
		return 0;
	}

	void dfs_add(int step)
	{
		if (step == 10) {
			if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9]) {
				cout << a[1] << a[2] << a[3] << " + " << a[4] << a[5] << a[6] << " = " << a[7] << a[8] << a[9] << endl;
			}
			return;
		}
		for (int i = 1; i < 10; i++) {
			if (book[i] == 0) {
				a[step] = i;
				book[i] = 1;
				dfs_add(step + 1);
				book[i] = 0;
			}
		}
		return;
	}
}
