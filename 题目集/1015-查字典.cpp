#include <iostream>
#include <list>
using namespace std;

bool find(const list<int>& l, int i)
{
	for (auto it = l.begin(); it != l.end(); it++) {
		if (i == *it) return true;
	}
	return false;
}

int main()
{
	int m{ 0 }, n{ 0 }, cnt{ 0 }, ans{ 0 }, input{ 0 };
	cin >> m >> n;
	list<int> voc;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (cnt < n) {
			if (!find(voc, input)) {
				if (cnt >= m) {
					voc.pop_front();
				}
				else {
					cnt++;
				}
				voc.push_back(input);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
