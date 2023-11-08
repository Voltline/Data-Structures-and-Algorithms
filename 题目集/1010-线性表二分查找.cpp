#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n{ 0 }, u{ 0 };
	cin >> n;
	int lowerbound{ 0 }, upperbound{ n };
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		cin >> u;
		vec.push_back(u);
	}

	int v{ 0 };
	cin >> v;

	int q{ (lowerbound + upperbound) / 2 };
	while (vec[q] != v && (lowerbound < upperbound)) {
		if (upperbound - lowerbound > 1) {
			if (vec[q] > v) {
				upperbound = q;
				q += lowerbound;
				q = (q % 2 == 0) ? q : q - 1;
				q /= 2;
			}
			else if (vec[q] < v) {
				lowerbound = q;
				q += upperbound;
				q = (q % 2 == 0) ? q : q + 1;
				q /= 2;
			}
			else break;
		}
		else {
			if (vec[lowerbound] == v) q = lowerbound;
			else if (vec[upperbound] == v) q = upperbound;
			break;
		}
	}
	if (vec[q] == v) cout << q << endl;
	else cout << -1 << endl;
	return 0;
}
