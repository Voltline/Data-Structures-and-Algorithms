#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct item
{
	string mandarin;
	string shanghainese;
};

bool cmp(const item& i1, const item& i2)
{
	return i1.shanghainese < i2.shanghainese;
}

int binary_search(const vector<item>& dict, const string& dialect)
{
	int left{ 0 }, right = dict.size() - 1, mid{ 0 };
	while (left <= right) {
		mid = (left + right) / 2;
		if (left != right) {
			if (dict[mid].shanghainese > dialect) {
				right = mid - 1;
			}
			else if (dict[mid].shanghainese < dialect) {
				left = mid + 1;
			}
			else return mid;
		}
		else {
			if (dict[left].shanghainese == dialect) {
				return left;
			}
			else return -1;
		}
	}
	return -1;
}

int main()
{
	vector<item> dict;
	string line, mandarin, shanghainese;
	istringstream sin;
	do {
		getline(cin, line);
		if (line != "") {
			sin = istringstream(line);
			sin >> mandarin >> shanghainese;
			dict.emplace_back(item{ mandarin, shanghainese });
		}
	} while (line != "");
	sort(dict.begin(), dict.end(), cmp);

	while (cin >> line) {
		int idx = binary_search(dict, line);
		if (idx != -1) cout << dict[idx].mandarin << endl;
		else cout << "eh" << endl;
	}
	return 0;
}
