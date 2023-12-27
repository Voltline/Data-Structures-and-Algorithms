#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
	int beg;
	int end;
	int w;
	bool operator<(const edge& e) const
	{
		return w < e.w;
	}
};

edge g[20020];
vector<int> v(3020, -1);
int mst{ 0 };

int Find(vector<int>& vec, int x)
{
	if (vec[x] < 0) return x;
	return Find(vec, vec[x]);
}

void Union(vector<int>& vec, int x, int y)
{
	int px{ Find(vec, x) }, py{ Find(vec, y) };
	if (px != py) {
		vec[px] += vec[py];
		vec[py] = px;
	}
}

void Kruskal(int N, int M)
{
	sort(g + 1, g + 1 + M);
	for (int i = 1; i <= M; i++) {
		int px{ Find(v, g[i].beg) }, py{ Find(v, g[i].end) };
		if (px != py) {
			Union(v, px, py);
			mst += g[i].w;
		}
	}
}

int main()
{
	int N{ 0 }, M{ 0 };
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int st{ 0 }, end{ 0 }, w{ 0 };
		cin >> st >> end >> w;
		g[i] = { st, end, w };
	}
	Kruskal(N, M);
	int root{ Find(v, 1) };
	for (int i = 2; i <= N; i++) {
		if (Find(v, i) != root) {
			mst = -1;
			break;
		}
	}
	cout << mst << endl;
	return 0;
}