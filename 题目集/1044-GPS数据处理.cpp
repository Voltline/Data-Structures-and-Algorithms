#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string check(const string& s)
{
	string ans, tmp;
	istringstream sin{ s };
	vector<string> info;
	while (getline(sin, tmp, ',')) {
		info.push_back(tmp);
	}
	if (info[0] == "$GPRMC") {
		if (info[2] == "A") {
			ans = info[1];
			int check{ 0 };
			for (int i = 1; i < s.size() && s[i] != '*'; i++) {
				check ^= s[i];
			}
			check %= 65536;
			int start{ 0 };
			for (; info[12][start] != '*' && start < info[12].size(); start++);
			int c{ stoi(info[12].substr(start + 1, 100), nullptr, 16)};
			if (check == c) {
				ans[6] = 0;
				string hour{ ans.substr(0, 2) },
					min{ ans.substr(2, 2) },
					sec{ ans.substr(4,2) };
				int h{ (stoi(hour) + 8) % 24 };
				ans = "";
				if (h < 10) {
					ans += "0" + to_string(h);
				}
				else ans += to_string(h);
				ans += ":" + min + ":" + sec;
			}
			else ans = "";
		}
	}
	return ans;
}

int main()
{
	string s, ans;
	while (s != "END") {
		cin >> s;
		string tmp{ check(s) };
		if (tmp != "") {
			ans = tmp;
		}
	}
	cout << ans << endl;
	return 0;
}
