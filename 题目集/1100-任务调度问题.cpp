#include <iostream>
#include <queue>
#include <vector>
using namespace std;
constexpr int MAXN = 5e3 + 20;

int n, m;
vector<int> G[MAXN];
int in[MAXN]{ 0 };  // 存储每个结点的入度

bool toposort()
{
    vector<int> L;
    queue<int> S;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) S.push(i);
    while (!S.empty()) {
        int u = S.front();
        S.pop();
        L.push_back(u);
        for (const auto& v : G[u]) {
            if (--in[v] == 0) {
                S.push(v);
            }
        }
    }
    if (L.size() == n) {
        // for (const auto& i : L) cout << i << ' ';
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt{ 0 };
        cin >> cnt;
        int in1{ 0 };
        for (int j = 0; j < cnt; j++) {
            cin >> in1;
            G[i].push_back(in1);
            in[in1]++;
        }
    }
    if (toposort()) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}