#include <iostream>
#include <list>
#define MIN(a, b) (a < b) ? (a) : (b)
using namespace std;

int main()
{
	int P{ 0 }, C{ 0 }, Case{ 1 };
	do {
		cin >> P >> C;
		if (P != 0 && C != 0) {
			cout << "Case " << Case++ << ":" << '\n';
			list<int> que;
			int m{ MIN(P, C) };
			for (int i = 1; i <= m; i++) {
				que.push_back(i);
			}
			char c1{ 0 };
			for (int i = 0; i < C; i++) {
				cin >> c1;
				if (c1 == 'N') {
					int head{ *que.begin() };
					cout << head << '\n';
					que.pop_front();
					que.push_back(head);
				}
				else {
					int c2{ 0 };
					cin >> c2;
					if (m >= c2) {
						que.remove(c2);
						que.push_front(c2);
					}
					else {
						que.push_front(c2);
					}
				}
			}
		}
	} while (P != 0 && C != 0);

	return 0;
}
