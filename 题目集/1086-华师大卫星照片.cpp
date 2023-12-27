#include <iostream>
#include <string>
using namespace std;
int pic[1020][1020]{ {0} }, book[1020][1020]{ {0} };
int cnt{ 0 };

bool islegal(int x, int y, int W, int H)
{
	if (x >= 0 && y >= 0 && x < W && y < H) {
		return true;
	}
	return false;
}

void dfs(int x, int y, int W, int H)
{
	if (!islegal(x, y, H, W)) return;
	if (pic[x][y] == 0 || book[x][y] == 1) return;
	book[x][y] = 1;
	cnt++;
	dfs(x + 1, y, W, H);
	dfs(x - 1, y, W, H);
	dfs(x, y + 1, W, H);
	dfs(x, y - 1, W, H);
}

int main()
{
	int W{ 0 }, H{ 0 };
	cin >> W >> H;
	string line;
	for (int i = 0; i < H; i++) {
		cin >> line;
		for (int j = 0; j < W; j++) {
			pic[i][j] = (line[j] == '.') ? 0 : 1;
		}
	}

	int ans{ 0 };
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cnt = 0;
			if (book[i][j] == 0) {
				dfs(i, j, W, H);
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans << endl;
	return 0;
}