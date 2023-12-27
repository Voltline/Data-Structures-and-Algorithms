#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
constexpr int MAXN = 1001;
double w[MAXN][MAXN]{ 0.0 }, c[MAXN][MAXN]{ 0.0 };
double p[MAXN]{ 0.0 }, q[MAXN]{ 0.0 };

double min(double a, double b)
{
	return (a < b) ? a : b;
}

int main()
{
	int n{ 0 };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 0; i <= n; i++) {
		cin >> q[i];
	}
	for (int i = 0; i <= n; i++) w[i][i] = q[i];
	for (int i = 0; i <= n; i++) c[i][i] = 0;

	for (int diff = 1; diff <= n; diff++) {
		for (int i = 0; i <= n - diff; i++) {
			int j = i + diff;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			double cmp = 1e9;
			for (int t = i + 1; t <= j; t++) cmp = min(cmp, c[i][t - 1] + c[t][j]);
			c[i][j] = w[i][j] + cmp;
		}
	}
	double ans{ c[0][n] };
	for (int i = 0; i <= n; i++) ans += q[i];
	cout << setprecision(6) << fixed << ans << endl;
	return 0;
}