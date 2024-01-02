#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MAXN = 520;
constexpr int inf = 0x3f3f3f3f;

struct weight
{
	int len;
	int cost;
	
	weight operator+(const weight& w) const
	{
		return weight{ len + w.len, cost + w.cost };
	}

	bool operator<(const weight& w) const
	{
		if (len != w.len) return len < w.len;
		else return cost < w.cost;
	}
	
	bool operator>(const weight& w) const
	{
		if (len != w.len) return len > w.len;
		else return cost > w.cost;
	}
};

weight G[MAXN+10][MAXN+10]{ {0} }, cost[MAXN+10][MAXN+10]{ {0} };

void floyd(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = cost[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (G[i][j] > G[i][k] + G[k][j]) {
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
}

int main()
{
	int n{ 0 }, m{ 0 }, S{ 0 }, D{ 0 };
	cin >> n >> m >> S >> D;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			cost[i][j] = (i == j) ? weight{ 0, 0 } : weight{ inf, inf };
		}
	}
	for (int i = 1; i <= m; i++) {
		int beg{ 0 }, end{ 0 }, w{ 0 }, c{ 0 };
		cin >> beg >> end >> w >> c;
		//if (weight{ w, c } < cost[beg][end])
		cost[beg][end] = cost[end][beg] = weight{ w, c };
	}
	floyd(n);

	cout << G[S][D].len << " " << G[S][D].cost << endl;
	return 0;
}