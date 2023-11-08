#include <iostream>
using namespace std;

int check(int to_alloc[])
{
	int cnt{ 0 };
	for (int i = 1; i < 102; i++) {
		if (to_alloc[i] != 0) cnt++;
	}
	return cnt;
}

int main()
{
	int N{ 0 };
	cin >> N;
	int seat[10010]{ 0 }, to_alloc[102]{ 0 };
	int in{ 0 }, people{ 0 };
	for (int i = 1; i <= N; i++) {
		cin >> in;
		to_alloc[i] = in * 10;
		people += in * 10;
	}

	int school{ 1 }, i{ 1 };
	for (; i < 10010; i++) {
		if (check(to_alloc) > 1) {
			if (school > N) school = 1;
			if (to_alloc[school] == 0) {
				while (to_alloc[school] == 0) {
					school++;
					if (school > N) school = 1;
				}
			}
			to_alloc[school]--;
			seat[i] = school++;
		}
		else break;
	}
	int rest{ 1 };
	for (; rest < N; rest++) {
		if (to_alloc[rest] != 0) break;
	}

	if (seat[i] == rest) i++;

	for (; to_alloc[rest] > 0; to_alloc[rest]--) {
		seat[i] = rest;
		i += 2;
	}

	int print{ 0 };
	for (int t = 1; t <= N; t++) {
		cout << "#" << t;
		for (int u = 1; u < i; u++) {
			if (seat[u] == t) {
				if (print % 10 == 0) {
					cout << endl;
				}
				else cout << ' ';
				cout << u;
				print++;
			}
		}
		cout << endl;
	}

	return 0;
}
