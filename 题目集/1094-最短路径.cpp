#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
constexpr long long inf = 0xffffff;
struct edge
{
	int end;
	int w;
};

vector<edge> es[120];
int mark[120]{ 0 }, road[120]{ 0 };
ll cnt[120]{ 0ll }, dist[120]{ 0ll };

void print_route(int n)
{
	if (n != 0) {
		print_route(road[n]);
		cout << n << " ";
	}
}

int main()
{
	int n{ 0 }, m{ 0 };
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int n1{ 0 }, n2{ 0 }, w;
		cin >> n1 >> n2 >> w;
		es[n1].push_back({ n2, w });
		es[n2].push_back({ n1, w });
	}
	priority_queue<pair<int, int>,
		vector<pair<int,int>>,
		greater<pair<int,int>>> que;
	for (int i = 2; i <= n; i++) dist[i] = inf;
	dist[1] = 0;
	que.push({ 0, 1 });
	cnt[1] = 1;
	while (!que.empty()) {
		int node{ que.top().second };
		que.pop();
		if (mark[node]) continue;
		mark[node] = 1;

		for (auto& e : es[node]) {
			int end{ e.end }, w{ e.w };
			if (!mark[end]) {
				if (dist[end] > dist[node] + w) {
					dist[end] = dist[node] + w;
					cnt[end] = cnt[node];
					road[end] = node;
					que.push({ dist[end], end });
				}
				else if (dist[end] == dist[node] + w) {
					cnt[end] += cnt[node];
				}
			}
		}
	}
	if (cnt[n] == 0) {
		cout << "-1\n0\n-1\n";
	}
	else {
		cout << dist[n] << endl << cnt[n] << endl;
		print_route(n);
	}
	return 0;
}