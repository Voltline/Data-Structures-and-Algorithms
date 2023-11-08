#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n{ 0 }, m{ 0 };
	cin >> n >> m;
	vector<int> total(n);
	int master[5001]{ 0 };
	int input{ 0 };
	for (int i = 0; i < n; i++) {
		cin >> total[i];
	}

	int l{ 0 }, r{ n }, left{ 0 }, right{ -1 }, MAX{ n }, cnt{ 0 };
	while (right < n) {
		right++;
		if (right == n) break;

		if (master[total[right] - 1] == 0) {
			cnt++;
		}
		master[total[right] - 1]++;
		if (cnt == m) {
			while (master[total[left] - 1] > 0) {
				master[total[left] - 1]--;
				if (master[total[left] - 1] == 0) {
					cnt--;
					break;
				}
				else left++;
			}

			if (right - left < MAX) {
				MAX = right - left;
				l = left;
				r = right;
			}
			left++;
		}
	}
	if (r < 0) r++;

	cout << l+1 << " " << r+1 << endl;
	return 0;
}
