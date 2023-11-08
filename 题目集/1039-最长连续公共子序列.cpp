#include <iostream>
#include <string>
#include <vector>
using namespace std;

int d[60000]{ 0 };

int DP(const string& s1, const string& s2)
{
	int size1 = s1.size(), size2 = s2.size(), res{ 0 };
	for (int i = 0; i < size1; i++) {
		for (int j = size2 - 1; j >= 0; j--) {
			if (s1[i] == s2[j]) {
				if (j == 0) d[0] = 1;
				d[j] = d[j - 1] + 1;
			}
			else d[j] = 0;
			res = (d[j] > res) ? d[j] : res;
		}
	}
	return res;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << DP(s1, s2) << endl;
	return 0;
}
