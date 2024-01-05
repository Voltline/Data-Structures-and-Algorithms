#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 505;
int G[N][N]{ {0} }, used[N][N]{ {0} }, path[N][N]{ {0} };
int pre[N]{ 0 }, dis[N]{ 0 };
bool vis[N]{ false };
int m, n;

void init() 
{
	for (int i = 1; i <= n; i++) {
		vis[i] = false;
		for (int j = 1; j <= n; j++)
			G[i][j] = INF;
	}
}

int Prim(int st) 
{
	int sum = 0, Min;
	for (int i = 1; i <= n; i++) {
		dis[i] = G[st][i];
		pre[i] = st;
	}
	dis[st] = 0;
	vis[st] = 1;
	for (int i = 1; i < n; i++) {
		Min = INF;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && Min > dis[j]) {
				Min = dis[j];
				st = j;
			}
		}
		vis[st] = 1;
		sum += Min;
		used[st][pre[st]] = used[pre[st]][st] = 1;
		for (int j = 1; j <= n; j++) {
			if (vis[j] && j != st)
				path[j][st] = path[st][j] = max(path[j][pre[st]], dis[st]);
			if (!vis[j] && dis[j] > G[st][j]) {
				dis[j] = G[st][j];
				pre[j] = st;
			}
		}
	}
	return sum;
}

int sec_Prim(int tmp) 
{
	int sum{ INF };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && !used[i][j])
				sum = min(sum, tmp + G[i][j] - path[i][j]);
		}
	}
	return sum;
}

int main() 
{
	int st, ed, len;
	while (cin >> n >> m) {
		init();
		for (int i = 0; i < m; i++) {
			cin >> st >> ed >> len;
			G[st][ed] = G[ed][st] = len;
		}
		int ans1 = Prim(1);
		int ans2 = sec_Prim(ans1);
		if (ans2 != INF) {
			cout << ans1 << " " << ans2 << endl;
		}
		else {
			cout << ans1 << " -1\n";
		}
	}
	return 0;
}