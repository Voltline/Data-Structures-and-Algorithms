#include <iostream>
#include <vector>
using namespace std;

int deg[1020]{ 0 };

int Find(vector<int>& v, int x)
{
	if (v[x] < 0) {
		return x;
	}
	return Find(v, v[x]);
}

void Union(vector<int>& v, int x, int y)
{
	int px{ Find(v, x) }, py{ Find(v, y) };
	if (px != py) {
		v[px] += v[py];
		v[py] = x;
	}
}

int main()
{
	vector<int> nodes(1020, -1);
	int N{ 0 }, M{ 0 };
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int n1{ 0 }, n2{ 0 };
		cin >> n1 >> n2;
		Union(nodes, n1, n2);
		deg[n1]++;
		deg[n2]++;
	}

	bool isEuler{ true };
	int root{ Find(nodes, 1) };
	for (int i = 1; i <= N; i++) {
		if (Find(nodes, i) != root) {
			isEuler = false;
			break;
		}
		else {
			if (deg[i] % 2 != 0) {
				isEuler = false;
				break;
			}
		}
	}
	if (isEuler) cout << 1 << endl;
	else cout << 0 << endl;

	return 0;
}