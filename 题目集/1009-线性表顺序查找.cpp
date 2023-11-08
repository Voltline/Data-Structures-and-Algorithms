#include <iostream>
#include <vector>
using namespace std;

int find(const vector<int>& vec, int v)
{
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == v) return i;
	}
	return -1;
}

int main()
{
	int n{ 0 }, u{ 0 };
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> u;
		vec.push_back(u);
	}
	int v{ 0 };
	cin >> v;
	cout << find(vec, v) << endl;
	return 0;
}
