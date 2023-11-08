#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	auto it_s1 = s1.begin(), it_s2 = s2.begin();
	while (it_s1 != s1.end() && it_s2 != s2.end()) {
		cout << *it_s1++ << *it_s2++;
	}
	if (it_s1 == s1.end()) {
		while (it_s2 != s2.end()) {
			cout << *it_s2++;
		}
	}
	else {
		while (it_s1 != s1.end()) {
			cout << *it_s1++;
		}
	}
	return 0;
}
