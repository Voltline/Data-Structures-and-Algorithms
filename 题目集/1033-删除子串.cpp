#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int T{ 0 };
	cin >> T;
	for (int i = 0; i < T; i++) {
		char s[2023]{ 0 }, s0[101]{ 0 };
		cin >> s >> s0;
		int slen = strlen(s), s0len = strlen(s0);
		char* sp{ s }, *s0p{ s0 };
		for (int j = 0; j < slen; j++) {
			bool isCmp{ false };
			sp = &s[j], s0p = s0;
			while (s0p < s0 + s0len - 1 && *sp++ == *s0p++);
			if (*s0p == *sp) {
				memset(&s[j], 0, s0len * sizeof(char));
				j += s0len - 1;
			}
			else {
				if (s0len != 1) j += s0p - s0 - 1;
			}
		}
		cout << "case #" << i << ":" << endl;
		for (int i = 0; i < slen; i++) {
			if (s[i] != 0) {
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}
