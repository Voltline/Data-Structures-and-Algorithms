#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int Find(vector<int>& circle, int x)
{
	if (circle[x] < 0) return x;
	else return Find(circle, circle[x]);
}

int Union(vector<int>& circle, int x, int y)
{
	int fx{ Find(circle, x) }, fy{ Find(circle, y) };
	if (fx != fy) {
		circle[fx] += circle[fy];
		circle[fy] = fx;
	}
	return fx;
}

bool in(const vector<int>& v, int val)
{
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == val) return true;
	}
	return false;
}

struct enemy
{
	int x;
	int y;
};

int main()
{
	int T{ 0 };
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n{ 0 }, m{ 0 };
		cin >> n >> m;
		vector<int> circle(n + 3, -1);
		map<int, vector<int>> relation;
		char choice{ 0 };
		int x{ 0 }, y{ 0 };
		for (int j = 0; j < m; j++) {
			cin >> choice >> x >> y;
			if (choice == 'Q') {
				int fx{ Find(circle, x) }, fy{ Find(circle, y) };
				if (fx == fy) {
					cout << "In the same gang." << endl;
				}
				else {
					if (relation.find(fx) != relation.end()) {
						auto& v = relation[fx];
						if (find(v.begin(), v.end(), fy) != relation[fx].end())
							cout << "In different gangs." << endl;
						else cout << "Not sure yet." << endl;
					}
					else {
						cout << "Not sure yet." << endl;
					}
				}
			}
			else {
				int fx{ Find(circle, x) }, fy{ Find(circle, y) };
				relation[fx].push_back(fy);
				relation[fy].push_back(fx);
				for (int k = 0; k < relation[fy].size(); k++) {
					if (!in(relation[fx], relation[fy][k])) {
						Union(circle, fx, relation[fy][k]);
						break;
					}
				}
				for (int k = 0; k < relation[fx].size(); k++) {
					if (!in(relation[fy], relation[fx][k])) {
						Union(circle, fy, relation[fx][k]);
						break;
					}
				}
			}
		}
	}

	return 0;
}
