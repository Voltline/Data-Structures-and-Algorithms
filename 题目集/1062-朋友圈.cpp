#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& circle, int x)
{
    if (circle[x] < 0) {
        return x;
    }
    else {
        return circle[x] = find(circle, circle[x]);
    }
}

int Union(vector<int>& circle, int rootX, int rootY)
{
    int fx{ find(circle, rootX) }, fy{ find(circle, rootY) };
    if (fx != fy) {
        circle[fx] += circle[fy];
        circle[fy] = fx;
    }
    return fx;
}

int main()
{
    int N{ 0 }, M{ 0 };
    cin >> N >> M;
    vector<int> circle(N + 3, -1);
    for (int i = 0; i < M; i++) {
        int cnt{ 0 }, root{ 0 }, in{ 0 };
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> in;
            if (j == 0) {
                root = in;
            }
            else if (in != root) {
                int rt{ find(circle, in) };
                if (root != rt) {
                    root = Union(circle, rt, root);
                }
            }
        }
    }
    int min_val{ 0 };
    for (auto& i : circle) {
        if (i < min_val) min_val = i;
    }
    cout << -min_val << endl;
    return 0;
}
