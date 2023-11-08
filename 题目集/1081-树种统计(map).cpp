#include <iostream>
#include <map>
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
	map<string, int> ans;
	cin.get();
	for (int i = 0; i < N; i++) {
		string tmp;
		getline(cin, tmp);
		if (ans.find(tmp) != ans.end()) {
			ans[tmp]++;
		}
		else ans[tmp] = 1;
	}
	for (auto& [k, v] : ans) {
		cout << k << " " << fixed << setprecision(4) << v * 100.0 / N << "%" << endl;
	}
	return 0;
}
