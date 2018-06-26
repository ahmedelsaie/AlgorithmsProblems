#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 100000
#define MOD  1000000007

void fn();

ll dp[MAX + 5];
int cases, k, a, b;

int main()
{
    scanf("%d %d", &cases, &k);
    fn();

    while(cases--)
    {
        scanf("%d %d", &a, &b);
        printf("%lld\n", (dp[b] - dp[a - 1] + MOD) % MOD);
    }

    return 0;
}

void fn()
{
    dp[0] = 1;

    for(int left = 1; left <= MAX; left++)
    {
        dp[left] = dp[left - 1];
        if(left - k >= 0)
            dp[left] += dp[left - k];
        dp[left] = dp[left] % MOD;
    }

    dp[0] = 0;
    for(int i = 1; i <= MAX; i++)
        dp[i] = (dp[i - 1] + dp[i]) % MOD;

    return;
}
