#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
constexpr int MAXN = 100;
constexpr int inf = 0x3f3f3f3f;

map<string, int> money;
double cost[MAXN][MAXN]{ {0.0} }, a[MAXN][MAXN]{ {0.0} };

void floyd(int n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = cost[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] < a[i][k] * a[k][j]) {
					a[i][j] = a[i][k] * a[k][j];
				}
			}
		}
	}
}

int main()
{
	int cnt{ 1 }, n{ 0 };
	while (cin >> n && n != 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cost[i][j] = (i == j) ? 1 : 0;
			}
		}
		int m{ 0 };
		string line;

		for (int i = 1; i <= n; i++) {
			cin >> line;
			money[line] = i;
		}
		cin >> m;
		for (int i = 1; i <= m; i++) {
			string a, b;
			double cur;
			cin >> a >> cur >> b;
			cost[money[a]][money[b]] = cur;
		}
		floyd(n);
		cout << "Case " << cnt++ << ": ";
		bool y{ false };
		for (int i = 1; i <= n; i++) {
			if (a[i][i] > 1) {
				y = true;
				break;
			}
		}
		if (y) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}