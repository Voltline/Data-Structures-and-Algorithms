#include <iostream>
#include <string>
#include <vector>
using namespace std;

int DP(const string& s, vector<vector<int>>& d)
{
	int size = s.size(), res{ 1 };
	for (int i = 0; i < size; i++) {
		d[i][i] = 1;
	}
	for (int i = size - 1; i >= 0; i--) {
		for (int j = i + 1; j < size; j++) {
			if (s[i] != s[j]) {
				d[i][j] = 0;
			}
			else {
				if (j == i + 1) {
					d[i][j] = d[i][j - 1];
				}
				else {
					d[i][j] = d[i + 1][j - 1];
				}
			}

			if (d[i][j]) {
				if (j - i + 1 > res) res = j - i + 1;
			}
		}
	}
	return res;
}

int main()
{
	int T{ 0 };
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		vector<vector<int>> vec;
		for (int i = 0; i < s.size(); i++) {
			vec.push_back(vector<int>(s.size()));
		}
		cout << "case #" << i << ":\n" << DP(s, vec) << endl;
	}
	return 0;
}
