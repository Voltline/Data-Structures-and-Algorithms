#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T{ 0 };
	cin >> T;
	for (int i = 0; i < T; i++) {
		char s[520]{ 0 };
		int N{ 0 };
		cin >> N >> s;
		char ans[520]{ 0 };
		char* beg{ s }, * end{ s + N - 1 };
		int t{ 0 };
		while (beg <= end) {
			if (*beg < *end) {
				ans[t++] = *beg;
				beg++;
			}
			else if (*beg > *end) {
				ans[t++] = *end;
				end--;
			}
			else {
				auto front = beg, back = end;
				while (*front == *back && front < back) {
					front++;
					back--;
				}
				if (*front < *back) {
					ans[t++] = *beg;
					beg++;
				}
				else {
					ans[t++] = *end;
					end--;
				}
			}
		}
		cout << "case #" << i << ":\n" << ans << endl;
	}
	return 0;
}
