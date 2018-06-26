#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MOD 100000000

ll fn(int left0, int left1, int mode);

ll dp[105][105][2];
int k0, k1, left0, left1;

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d %d", &left0, &left1, &k0, &k1);

    printf("%lld\n", (fn(left0, left1, 0) + fn(left0, left1, 1)) % MOD);

    return 0;
}

ll fn(int left0, int left1, int mode)
{
    if(left0 + left1 == 0)
        return 1;

    if(mode == 0 && left0 <= 0)
        return 0;

    if(mode == 1 && left1 <= 0)
        return 0;

    ll& ret = dp[left0][left1][mode];
    if(ret != -1)
        return ret;

    ret = 0;

    if(mode == 0)
    {
        for(int i = 1; i <= min(k0, left0); i++)
            ret += fn(left0 - i, left1, !mode) % MOD;
    }
    else
    {
        for(int i = 1; i <= min(k1, left1); i++)
            ret += fn(left0, left1 - i, !mode) % MOD;
    }

    return ret;
}
