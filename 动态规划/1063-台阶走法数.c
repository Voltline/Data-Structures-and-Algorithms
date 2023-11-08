#include <stdio.h>
long long ans[51] = {0, 1, 2, 4, 8};

long long solve()
{
    for (int i = 5; i < 51; i++) {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3] + ans[i-4];
    }
}

int main()
{
    solve();
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int stairs = 0;
        scanf("%d", &stairs);
        printf("case #%d:\n%lld\n", i, ans[stairs]);
    }

    return 0;
}
