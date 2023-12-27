#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> ma;
vector<int> v(120, -1);
int a[120][120]{ {0} }, cost[120][120]{ {0} };
constexpr int inf = 0xffffff;

void floyd(int n)
{
	int i{ 0 }, j{ 0 }, k{ 0 };
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][k] + a[k][j] < a[i][j]) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
}

int Find(vector<int>& v, int x)
{
	if (v[x] < 0) return x;
	return Find(v, v[x]);
}

void Union(vector<int>& v, int x, int y)
{
	int px{ Find(v, x) }, py{ Find(v, y) };
	if (px != py) {
		v[px] += v[py];
		v[py] = px;
	}
}

int main()
{
	int n{ 0 }, m{ 0 };
	int idx{ 1 };
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cost[i][j] = a[i][j] = inf;
		}
	}

	for (int i = 0; i < m; i++) {
		string a1, b1;
		int w{ 0 };
		cin >> a1 >> b1 >> w;
		if (ma[a1] == 0) ma[a1] = idx++;
		if (ma[b1] == 0) ma[b1] = idx++;
		int aidx{ ma[a1] }, bidx{ ma[b1] };
		a[aidx][bidx] = a[bidx][aidx] = w;
		cost[aidx][bidx] = cost[bidx][aidx] = w;
		Union(v, aidx, bidx);
	}
	floyd(n);
	int t{ 0 };
	cin >> t;
	for (int i = 0; i < t; i++) {
		string st, end;
		cin >> st >> end;
		int sidx{ ma[st] }, eidx{ ma[end] };
		if (sidx != 0 && eidx != 0
			&& Find(v, sidx) == Find(v, eidx)) {
			cout << a[sidx][eidx] << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}