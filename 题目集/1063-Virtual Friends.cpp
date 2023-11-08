#include <iostream>
#include <vector>
#include <map>
#include <string>
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
    int T{ 0 };
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n{ 0 };
        cin >> n;
        vector<int> circle(n + 3, -1);
        int index{ 1 };
        map<string, int> table;
        string a, b;
        for (int j = 0; j < n; j++) {
            cin >> a >> b;
            if (table.find(a) == table.end()) {
                table[a] = index++;
            }
            if (table.find(b) == table.end()) {
                table[b] = index++;
            }
            int a_i{ table[a] }, b_i{ table[b] };
            int root = Union(circle, a_i, b_i);
            cout << -circle[root] << endl;
        }

    }
    return 0;
}
