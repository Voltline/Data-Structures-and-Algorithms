#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

struct trees
{
	string name;
	int cnt;

	bool operator<(const trees& t) const
	{
		return name < t.name;
	}
};

int main()
{
	int N{ 0 };
	cin >> N;
	cin.get();
	vector<string> ts;
	for (int i = 0; i < N; i++) {
		string tmp;
		getline(cin, tmp);
		ts.push_back(tmp);
	}
	sort(ts.begin(), ts.end());
	vector<trees> ans;
	int cnt{ 1 };
	string last{ ts[0]};
	for (int i = 1; i < N; i++) {
		if (ts[i] == last) {
			cnt++;
		}
		else {
			last = ts[i];
			ans.push_back(trees{ ts[i - 1], cnt });
			cnt = 1;
		}
	}
	ans.push_back(trees{ ts[N - 1], cnt });
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].name << " " << fixed <<setprecision(4) << ans[i].cnt * 100.0 / N << "%" << endl;
	}
	return 0;
}
