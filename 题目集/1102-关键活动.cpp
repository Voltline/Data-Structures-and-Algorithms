#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int MAXN = 120;

struct edge
{
	int beg;
	int end;
	int w;
};

vector<edge> e[MAXN];
int in[MAXN]{ 0 };
int ee[MAXN]{ 0 }, le[MAXN]{ 0 };
int xe[MAXN]{ 0 }, l[MAXN]{ 0 };
bool v[MAXN]{ 0 };
vector<edge> all_es;
map<int, edge> ma;
vector<int> ans;

bool toposort(int n)
{
	vector<int> L;
	queue<int> S;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) S.push(i);
	}

	while (!S.empty()) {
		int u{ S.front() };
		S.pop();
		if (v[u]) continue;
		v[u] = true;
		L.push_back(u);
		for (const auto& v : e[u]) {
			if (--in[v.end] == 0) S.push(v.end);
			ee[v.end] = max(ee[v.end], ee[u] + v.w);
		}
	}
	if (L.size() == n) {
		ans = L;
		return true;
	}
	else {
		ans = vector<int>{};
		return false;
	}
}

int main()
{
	int n{ 0 }, m{ 0 };
	cin >> n >> m;
	memset(le, 0x3f, sizeof(le));
	all_es.push_back({ 0,0,0 });
	ee[1] = 0, le[n] = n;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({ u, v, w });
		all_es.push_back({ u,v,w });
		in[v]++;
	}
	bool available{ toposort(n) };
	if (available) {
		int mx = 0, mxi = 0;
		for (int i = 1; i <= n; i++) {
			if (ee[i] > mx) {
				mx = ee[i];
				mxi = i;
			}
		}
		le[mxi] = ee[mxi];
		for (auto it = ans.rbegin() + 1; it != ans.rend(); it++) {
			for (const auto& eg : e[*it]) {
				le[*it] = min(le[*it], le[eg.end] - eg.w);
			}
		}

		for (int i = 1; i <= m; i++) {
			xe[i] = ee[all_es[i].beg];
			l[i] = le[all_es[i].end] - all_es[i].w;
		}

		vector<edge> all;
		mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, ee[i]);
		}
		cout << mx << endl;
		for (int i = 1; i <= m; i++) {
			if (xe[i] == l[i]) {
				all.push_back(all_es[i]);
			}
		}
		stable_sort(all.begin(), all.end(),
			[](const edge& e1, const edge& e2) {
				if (e1.beg != e2.beg) {
					return e1.beg < e2.beg;
				}
				else {
					return e1.end > e2.end;
				}
			});
		for (const auto& fe : all) {
			cout << fe.beg << "->" << fe.end << endl;
		}
	}
	else cout << 0 << endl;
	return 0;
}
