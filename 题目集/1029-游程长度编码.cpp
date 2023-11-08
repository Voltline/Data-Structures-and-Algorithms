#include <iostream>
#include <string>
using namespace std;

void RLE(const string& s)
{
	char c{ s[0] };
	int cnt{ 1 };
	for (int i = 1; i < s.size(); i++) {
		if ((cnt == 255 && s[i] == c) || s[i] != c) {
			cout << cnt << c;
			if (s[i] != c) {
				c = s[i];
			}
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	cout << cnt << c;
}

int main()
{
	int T{ 0 };
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		cout << "case #" << i << ": " << endl;
		RLE(s);
		cout << endl;
	}
	return 0;
}
