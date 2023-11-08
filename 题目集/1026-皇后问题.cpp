#include <iostream>
using namespace std;
constexpr int N = 100002;
struct Queen
{
	int x;
	int y;
};

Queen queens[N]{ {0,0} };

long long calc(long long x)
{
	if (x == 0 || x == 1) return 0ll;
	else return x * (x - 1) / 2;
}

int main()
{
	int n{ 0 }, x{ 0 }, y{ 0 };
	cin >> n;
	int* row = new int[n + 2] { 0 }, * col = new int[n + 2] { 0 };
	int* diag = new int[2 * n + 2] { 0 }, * ndiag = new int[2 * n + 2] { 0 };
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		queens[i] = Queen{ x, y };
		row[y]++;
		col[x]++;
		diag[x + y]++;
		ndiag[y - x + n]++;
	}
	long long ans{ 0ll };
	for (int i = 1; i <= n; i++) {
		ans += calc(row[i]) + calc(col[i]);
	}

	for (int i = 1; i <= 2 * n; i++) {
		ans += calc(diag[i]) + calc(ndiag[i]);
	}
	cout << ans << endl;
	return 0;
}
