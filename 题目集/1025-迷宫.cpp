#include <iostream>
#include <stack>
using namespace std;

int maze[101][101]{ {0} }, arrived[101][101]{ {0} };

struct location
{
	int x;
	int y;
};

struct route
{
	int x;
	int y;
	int d;
};

location loc[8]{
	{0, 1}, {0, -1}, {1,  0}, {1,  -1},
	{1, 1}, {-1, 0}, {-1, 1}, {-1, -1}
};

bool dfs(int x1, int y1, int x2, int y2, int n)
{
	stack<route> s;
	arrived[x1][y1] = 1;
	s.push(route{ x1, y1, -1 });

	int now_x{ 0 }, now_y{ 0 };
	int i{ 0 }, j{ 0 }, k{ 0 };

	while (!s.empty()) {
		i = s.top().x, j = s.top().y, k = s.top().d;
		s.pop();
		while (k < 7) {
			k++;
			now_x = i + loc[k].x , now_y = j + loc[k].y ;
			if (now_x == x2 && now_y == y2) return true;

			if (now_x >= 0 && now_x < n && now_y >= 0 && now_y < n && maze[now_x][now_y] == 0 && arrived[now_x][now_y] == 0) {
				arrived[now_x][now_y] = 1;
				s.push(route{ i, j, k });
				i = now_x, j = now_y, k = -1;
			}
		}
	}
	return false;
}

int main()
{
	int n{ 0 }, x1{ 0 }, y1{ 0 }, x2{ 0 }, y2{ 0 };
	cin >> n >> x1 >> y1 >> x2 >> y2;
	char c{ 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			maze[i][j] = c - '0';
		}
	}
	if (maze[x1][y1] == 1 || maze[x2][y2] == 1) {}
	else {
		if (dfs(x1, y1, x2, y2, n)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
