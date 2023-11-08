#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dat
{
	int num;
	int times;
};

bool cmp(const dat& d1, const dat& d2)
{
	if (d1.times != d2.times) {
		return d1.times > d2.times;
	}
	else return d1.num < d2.num;
}

int find(const vector<dat>& vec, int num)
{
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].num == num) return i;
	}
	return -1;
}

int main()
{
	int T{ 0 };
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N{ 0 }, in{ 0 };
		cin >> N;
		vector<dat> vec;
		for (int j = 0; j < N; j++) {
			cin >> in;
			int idx{ find(vec, in) };
			if (idx != -1) {
				vec[idx].times++;
			}
			else vec.push_back(dat{ in, 1 });
		}
		sort(vec.begin(), vec.end(), cmp);
		cout << "case #" << i << ":" << endl;
		for (int j = 0; j < vec.size(); j++) {
			for (int k = 0; k < vec[j].times; k++) {
				if (j == vec.size() - 1 && k == vec[j].times - 1) {
					cout << vec[j].num << endl;
				}
				else cout << vec[j].num << " ";
			}
		}
	}

	return 0;
}
