#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e3 + 2;
int e1[N][N], book[N], dis[N], res[N], preway[N], val[N], num[N];
int n, m, s, d, u, v;
int main()
{
    cin >> n >> m >> s >> d;
    //初始化数组
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) e1[i][j] = 0;
            else e1[i][j] = inf;
        }
    }
    //res表示每个点的点权
    for (int i = 1; i <= n; ++i) {
        cin >> res[i];
    }
    //读入边
    for (int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        e1[x][y] = w;
        e1[y][x] = w;
    }
    for (int i = 1; i <= n; ++i) {
        dis[i] = e1[s][i]; //起点到其余各点的初始路径
        val[i] = res[s] + res[i]; //从起点到其余点的点权和
        num[i] = 1;  //初始最短路径只有一条
        preway[i] = s; //
    }
    book[s] = 1; //起点已经在集合中，所以标记为 1
    val[s] = res[s]; //初始起点点权
    int min;
    for (int i = 1; i < n; ++i) {
        min = inf;
        for (int j = 1; j <= n; ++j) {
            if (book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;   //每次找到离源点最近的一个顶点
            }
        }
        //然后通过该顶点进行扩展，对其它边开始松弛
        book[u] = 1;
        for (v = 1; v <= n; ++v) {
            if (book[v] == 0) {
                if (dis[v] > dis[u] + e1[u][v]) {  //如果可以通过u->v这条边来松弛
                    dis[v] = dis[u] + e1[u][v];
                    num[v] = num[u];
                    val[v] = val[u] + res[v]; //点权和
                    preway[v] = u; //记录前驱节点
                }
                else if (dis[v] == dis[u] + e1[u][v]) {
                    num[v] += num[u];
                    if (val[v] < val[u] + res[v]) { //路径相同时，选择点权和更大的
                        val[v] = val[u] + res[v];
                        preway[v] = u;
                    }
                }
            }
        }
    }
    int k = 0, cur = d;
    int path[N];
    while (cur != s) {
        path[k++] = cur;
        cur = preway[cur];
    }
    path[k++] = s;
    printf("%d %d\n", num[d], val[d]);
    for (int i = k - 1; i >= 0; i--)
        printf("%d%c", path[i], i == 0 ? '\n' : ' ');
    return 0;
}
