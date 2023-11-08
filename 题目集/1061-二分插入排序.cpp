#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& vec, int end, int val)
{
	int left{ 0 }, right{ end };
	int cnt{ 0 };
	while (left <= right) {
		int mid{ (left + right) / 2 };
		cnt++;
		if (vec[mid] <= val) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << cnt << endl;
	return left;
}

void insertion_sort(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++) {
		if (i > 0) {
			int insert_loc{ binary_search(vec, i - 1, vec[i]) };
			int val{ vec[i] };
			for (int j = i; j > insert_loc; j--) {
				vec[j] = vec[j - 1];
			}
			vec[insert_loc] = val;
		}
	}
}

int main()
{
	int N{ 0 };
	vector<int> arr;
	cin >> N;
	int in{ 0 };
	for (int i = 0; i < N; i++) {
		cin >> in;
		arr.push_back(in);
	}
	insertion_sort(arr);
	return 0;
}
