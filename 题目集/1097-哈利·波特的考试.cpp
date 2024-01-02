#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MAXN = 220;
constexpr int inf = 0x3f3f3f3f;

int G[MAXN][MAXN]{ {0} }, cost[MAXN][MAXN]{ {0} };

void floyd(int n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			G[i][j] = cost[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (G[i][j] > G[i][k] + G[k][j]) {
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
}

int main()
{
	int n{ 0 }, m{ 0 };
	cin >> n >> m;
	for (int i = 1; i <= MAXN; i++) {
		for (int j = 1; j <= MAXN; j++) {
			cost[i][j] = (i == j) ? 0 : inf;
		}
	}
	for (int i = 1; i <= m; i++) {
		int beg{ 0 }, end{ 0 }, w{ 0 };
		cin >> beg >> end >> w;
		if (w < cost[beg][end])
			cost[beg][end] = cost[end][beg] = w;
	}
	floyd(n);
	int MIN{ inf }, idx{ inf };
	for (int i = 1; i <= n; i++) {
		int M{ 0 };
		for (int j = 1; j <= n; j++) {
			if (G[i][j] > M) {
				M = G[i][j];
			}
		}
		if (MIN > M) {
			MIN = M;
			idx = i;
		}
	}
	if (MIN == inf) cout << 0 << endl;
	else cout << idx << " " << MIN << endl;
	
	return 0;
}