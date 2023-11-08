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

void insert_sort(vector<int>& vec)
{
	for (int i = 1; i < vec.size(); i++) {
		int tmp{ vec[i] }, j{ 0 };
		for (j = i - 1; j >= 0 && vec[j] > tmp; j--) {
			vec[j + 1] = vec[j];
		}
		vec[j + 1] = tmp;
		print(vec);
	}
}

int main()
{
	vector<int> vec;
	int n{ 0 }, in{ 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		vec.push_back(in);
	}
	insert_sort(vec);
	return 0;
}
