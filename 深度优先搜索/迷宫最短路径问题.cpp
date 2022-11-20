#include <iostream>
// 求解迷宫路径问题
using namespace std;
int n, m, p, q, minimum = 99999999;
int a[51][51] = { 0 }, book[51][51] = { 0 };

void dfs(int x, int y, int step);

int main()
{
	int startx, starty;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> startx >> starty >> p >> q;
	book[startx][starty] = 1;
	dfs(startx, starty, 0);
	cout << minimum << endl;
	return 0;
}

void dfs(int x, int y, int step)
{
	int tx, ty;
	int next[4][2] = { {1, 0}, // 向下
	{0, 1}, // 向右
	{0, -1}, // 向左
	{-1, 0} }; // 向上
	if (x == p && y == q) {
		if (step < minimum) {
			minimum = step;
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (tx < 1 || tx > n || ty < 1 || ty > m) {
			continue;
		}

		if (a[tx][ty] == 0 && book[tx][ty] == 0) {
			book[tx][ty] = 1;
			dfs(tx, ty, step+1);
			book[tx][ty] = 0;
		}
	}
	return;
}