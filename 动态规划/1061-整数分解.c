#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1100
typedef long long ll;
int primes[MAXN] = {0}, cnt = 0;
ll dp[MAXN] = {1};

int isPrime(int n)
{
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void prime()
{
    for (int i = 0; i < 1020; i++) {
        if (isPrime(i)) primes[cnt++] = i;
    }
}

void DP()
{
    for (int i = 0; i < 168; i++) {
        for (int t = primes[i]; t < 1001; t++) {
            dp[t] += dp[t - primes[i]];
        }
    }
}

int main()
{
    prime();
    DP();
    int n = 0;
    scanf("%d", &n);
    printf("%lld\n", dp[n]);
    return 0;
}

