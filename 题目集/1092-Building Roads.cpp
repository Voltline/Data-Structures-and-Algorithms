#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

double sqr(double x)
{
	return x * x;
}

struct edge
{
	int beg;
	int end;
	double w;

	bool operator<(const edge& e) const
	{
		return w < e.w;
	}
};

struct Point
{
	long long x, y;
};

double get_distance(const Point& p1, const Point& p2)
{
	double ans = 0.0;
	ans = sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
	return ans;
}

vector<edge> g;
Point points[1020];
vector<int> v(1020, -1);
double mst{ 0.0 };

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

int main()
{
	int N{ 0 }, M{ 0 };
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x{ 0 }, y{ 0 };
		cin >> x >> y;
		points[i] = { x, y };
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Point pi{ points[i] }, pj{ points[j] };
			g.push_back({ i, j, get_distance(pi, pj) });
		}
	}

	for (int i = 1; i <= M; i++) {
		int st{ 0 }, end{ 0 };
		double w{ 0.0 };
		cin >> st >> end;
		int px{ Find(v, st) }, py{ Find(v, end) };
		Union(v, px, py);
	}
	sort(g.begin(), g.end());
	for (auto& e : g) {
		int px{ Find(v, e.beg) }, py{ Find(v, e.end) };
		if (px != py) {
			Union(v, px, py);
			mst += e.w;
		}
	}
	cout << fixed << setprecision(2) << mst << endl;
	return 0;
}