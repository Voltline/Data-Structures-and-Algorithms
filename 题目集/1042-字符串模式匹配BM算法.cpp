#include <iostream>
#include <string>
#include <vector>
using namespace std;

int d[26]{ 0 };

void df(const string& p)
{
	// p stands for pattern
	int _size = p.size();
	for (int i = 0; i < 26; i++) d[i] = _size;
	for (int i = 0; i < _size - 1; i++) {
		d[p[i] - 'a'] = _size - i - 1;
	}
}

int bm_match(const string& t, const string& p)
{
	int n = t.size(), m = p.size();
	int i{ m - 1 };
	do {
		int j{ m - 1 }, k{ i };
		while (j >= 0 && p[j] == t[k]) {
			j--;
			k--;
		}
		if (j < 0) return i - m + 1;
		i = i + d[t[i] - 'a'];
	} while (i < n);
	return -1;
}

int main()
{
	string t, p;
	cin >> t >> p;
	df(p);
	cout << bm_match(t, p) << endl;
	for (int i = 0; i < 26; i++) {
		cout << " " + !i << d[i];
	}
	cout << endl;
	return 0;
}
