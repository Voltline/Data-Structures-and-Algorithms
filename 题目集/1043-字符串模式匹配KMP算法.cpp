#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct chars
{
	char c;
	int idx;

	chars() : c(0), idx(-1) {}
	chars(char c1, int idx1) : c(c1), idx(idx1) {}
};

vector<chars> getNext(const string& sub_str)
{
	vector<chars> next;
	size_t sub_str_size{ sub_str.size() };
	next.push_back(chars{ sub_str[0], -1 });
	for (size_t i = 1; i < sub_str_size; i++) {
		next.push_back(chars{ sub_str[i], 0 });
	}
	for (size_t i = 1; i < sub_str_size; i++) {
		if (next[i - 1].idx != -1 && next[i - 1].c == next[next[i - 1].idx].c) {
			next[i].idx = next[i - 1].idx + 1;
		}
		else {
			int j = next[i - 1].idx;
			while (j != -1 && next[j].c != next[i - 1].c) {
				j = next[j].idx;
			}
			next[i].idx = j + 1;
		}
	}
	return next;
}

void kmp(const string& main_str, const string& sub_str)
{
	int ans{ -1 };
	auto next = getNext(sub_str);
	int main_str_size = main_str.size(), sub_str_size = sub_str.size();
	int i{ 0 }, j{ 0 };
	while (i < main_str_size) {
		if (j == -1 || main_str[i] == sub_str[j]) {
			i++, j++;
		}
		else {
			if (j < sub_str_size) j = next[j].idx;
		}

		if (j == sub_str_size) {
			ans = i - j;
			break;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < next.size(); i++) {
		cout << " " + !i << next[i].idx;
	}
}

int main()
{
	string main_str, sub_str;
	cin >> main_str >> sub_str;
	kmp(main_str, sub_str);
	return 0;
}
