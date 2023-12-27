#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
vector<int> nodes[10010];

int main()
{
	int N{ 0 }, M{ 0 };
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n1{ 0 }, n2{ 0 };
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		nodes[n2].push_back(n1);
	}

	for (int i = 1; i <= N; i++) {
		vector<int> mark(N + 1, 0);
		queue<pair<int, int>> q;
		int cnt{ 1 };
		q.push({ i, 0 });
		mark[i] = 1;
		while (!q.empty()) {
			int mid{ q.front().first };
			int dis{ q.front().second };
			q.pop();
			if (dis >= 6) break;
			for (auto& node : nodes[mid]) {
				if (!mark[node]) {
					q.push({ node, dis + 1 });
					cnt++;
					mark[node] = 1;
				}
			}
		}
		cout << i << ": " << fixed << setprecision(2) << (double)cnt / N * 100 << "%\n";
	}
	return 0;
}