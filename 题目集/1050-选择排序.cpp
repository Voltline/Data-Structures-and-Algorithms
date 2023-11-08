#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++) {
		cout << " " + !i << vec[i];
	}
	cout << endl;
}

int min_idx(const vector<int>& vec, int beg)
{
	int min_idx{ beg };
	for (int j = beg; j < vec.size(); j++) {
		if (vec[j] < vec[min_idx]) {
			min_idx = j;
		}
	}
	return min_idx;
}

void select_sort(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++) {
		int min_index{ min_idx(vec, i) };
		int temp{ vec[i] };
		vec[i] = vec[min_index];
		vec[min_index] = temp;
		print(vec);
	}
}

int main()
{
	int n{ 0 }, in{ 0 };
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		vec.push_back(in);
	}
	select_sort(vec);
	return 0;
}
