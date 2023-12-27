#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Point
{
	int val;
	int type; // 0 for leaf, 1 for *

	bool operator<(const Point& p) const
	{
		return val > p.val;
	}
};

int main()
{
	priority_queue<Point> point;
	vector<int> an;
	int n{ 0 }, in{ 0 }, cnt{ 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		point.push(Point{ in, 0 });
	}

	while (point.size() > 1) {
		Point p1{ point.top() };
		point.pop();
		Point p2{ point.top() };
		point.pop();
		Point p3{ p1.val + p2.val, 1 };
		point.push(p3);
		an.push_back(p1.val + p2.val);
	}
	int ans{ 0 };
	for (auto& i : an) {
		ans += i;
	}
	cout << ans << endl;
	return 0;
}