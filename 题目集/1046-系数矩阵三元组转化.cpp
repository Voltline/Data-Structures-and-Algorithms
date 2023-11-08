#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mat_tuple
{
	int row;
	int col;
	int val;

	bool operator<(const mat_tuple& m) const
	{
		if (row != m.row) return row < m.row;
		else return col < m.col;
	}
};

int main()
{
	vector<mat_tuple> matrix;
	int m{ 0 }, n{ 0 }, c{ 0 };
	cin >> m >> n >> c;
	int x{ 0 }, y{ 0 }, val{ 0 };
	for (int i = 0; i < c; i++) {
		cin >> x >> y >> val;
		swap(x, y);
		matrix.push_back(mat_tuple{ x, y, val });
	}
	sort(matrix.begin(), matrix.end());
	for (auto& e : matrix) {
		cout << e.row << " " << e.col << " " << e.val << endl;
	}
	return 0;
}
