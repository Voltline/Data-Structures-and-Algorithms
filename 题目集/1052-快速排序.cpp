#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void print(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++) {
		cout << " " + !i << vec[i];
	}
	cout << endl;
}

void quick_sort(vector<int>& vec, int low, int high)
{
	if (low >= high) return;
	int i{ low }, j{ high }, t{ vec[low] };
	while (i < j) {
		while (i < j && vec[j] >= t) {
			j--;
		}
		if (i < j) vec[i++] = vec[j];
		while (i < j && vec[i] <= t) {
			i++;
		}
		if (i < j) vec[j--] = vec[i];
	}
	vec[i] = t;
	print(vec);
	quick_sort(vec, low, j - 1);
	quick_sort(vec, j + 1, high);
}

int main()
{
	vector<int> vec;
	int n{ 0 }, tmp{ 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	quick_sort(vec, 0, vec.size()-1);
	return 0;
}
