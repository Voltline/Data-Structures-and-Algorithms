#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

constexpr int N = 102, M = 202;
int n, m, qs;

struct Edge 
{
	int u, v, nxt;
}e[M * 2];
int fst[N];
int in[N];

string name[N];
unordered_map<string, int> idx;
priority_queue<int, vector<int>, greater<int>> h;

void Init() 
{
	qs++;
	cout << "Case #" << qs << ":";
	h = priority_queue<int, vector<int>, greater<int>>();
	idx.clear();
	for (int i = 0; i <= n; i++)
		fst[i] = -1, in[i] = 0;
}

int main() 
{
	while (cin >> n) {
		Init();
		for (int i = 0; i < n; i++)
			cin >> name[i], idx[name[i]] = i;
		cin >> m;
		for (int i = 0; i < m; i++) {
			string u, v;
			cin >> u >> v;
			e[i].u = idx[u];
			e[i].v = idx[v];
			e[i].nxt = fst[idx[u]];
			fst[idx[u]] = i;
			in[idx[v]]++;
		}
		for (int i = 0; i < n; i++)
			if (!in[i])
				h.push(i);

		for (int cnt = 0, u, v, j; cnt < n; cnt++) {
			u = h.top(), h.pop();
			cout << " " << name[u];
			for (j = fst[u]; j >= 0; j = e[j].nxt) {
				v = e[j].v;
				in[v]--;
				if (!in[v]) h.push(v);
			}
		}

		cout << "." << endl << endl;
	}

	return 0;
}