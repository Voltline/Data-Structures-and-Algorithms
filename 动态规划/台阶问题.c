#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
ll ans[100020] = {0, 1};

ll solve(int N, int K)
{
    memset(ans, 0, 100020 * sizeof(ll));
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j < i; j++) {
            ans[i] += ans[j];
        }
        ans[i]++;
        ans[i] %= 100003;
    }
    for (int i = K+1; i <= N; i++) {
        for (int j = i-K; j < i; j++) {
            ans[i] += ans[j];
        }
        ans[i] %= 100003;
    }
    return ans[N];
}

int main()
{
    int N = 0, K = 0;
    scanf("%d%d", &N, &K);
    printf("%lld\n", solve(N, K));
    return 0;
}
