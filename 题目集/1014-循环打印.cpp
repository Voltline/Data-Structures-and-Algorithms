#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n{ 0 }, i{ 0 }, k{ 0 };
	cin >> n >> i >> k;
	int cnt{ n };
	vector<int> Josephus(n+1);
	for (int u = 0; u <= n; u++) {
		Josephus[u] = u;
	}
	int next{ i-1 };

	while (cnt != 0) {
		int realcnt{ 0 };
		while (cnt != 1 && realcnt != k) {
			if (Josephus[(++next) % (n + 1)] != 0) {
				realcnt++;
			}
			next %= n + 1;
		}
		if (cnt == 1) {
			for (int u = 1; u <= n; u++) {
				if (Josephus[u] != 0) {
					cout << Josephus[u] << '\n';
					Josephus[u] = 0;
					break;
				}
			}
		}
		else {
			cout << Josephus[next] << " ";
			Josephus[next] = 0;
		}
		cnt--;
	}
	return 0;
}
