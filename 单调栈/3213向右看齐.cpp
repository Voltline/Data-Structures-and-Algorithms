#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Height
{
public:
	int height;
	int index;	
};

int main()
{
	int N{0}, h{0};
	cin >> N;
	vector<Height> heights;
	vector<int> indexs(N);
	for (int i = 0; i < N; i++) {
		cin >> h;
		heights.push_back(Height{h, i+1});
	}
	stack<Height> s;
	for (int i = N-1; i >= 0; i--) {
		while (!s.empty() && s.top().height <= heights[i].height) {
			s.pop();
		}
		indexs[i] = s.empty() ? 0 : s.top().index;
		s.push(heights[i]);
		vector<Height> s_1(s.size());
		stack<Height> s_2{s};
		for (int i = s.size() - 1; i >= 0; i--) {
			s_1[i] = s_2.top();
			s_2.pop();
		}
		cout << "--------" << endl;	
		for (auto& i : s_1) {
			cout << "(" << i.height << ", " << i.index << ")" << '\t';
		}
		cout << endl << "--------" << endl;
	}
	for (auto& i : indexs) {
		cout << i << endl;
	}
	return 0;
}