#include <iostream>
#include <vector>
using namespace std;

int map[1020][1020]{ 0 };
int vis[1020]{ 0 };
int node_cnt{ 1 }, cnt{ 0 };

void dfs(int p, int N)
{
	if (cnt != 0) {
		cout << ' ';
	}
	cnt++;
	cout << p;
	for (int i = 1; i <= N; i++) {
		if (vis[i] == 0 && map[p][i] == 1) {
			vis[i] = 1;
			node_cnt++;
			dfs(i, N);
			cout << " " << p;
		}
	}
}

int main()
{
	int N{ 0 }, M{ 0 }, S{ 0 };
	cin >> N >> M >> S;
	for (int i = 1; i <= M; i++) {
		int n1{ 0 }, n2{ 0 };
		cin >> n1 >> n2;
		map[n1][n2] = 1;
		map[n2][n1] = 1;
	}
	vis[S] = 1;
	dfs(S, N);
	if (node_cnt != N) cout << " 0" << endl;
	return 0;
}