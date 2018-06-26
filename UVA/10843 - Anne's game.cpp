#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long

ll fn(int taken, int left);
void pre_comb();

ll comb[105][105], dp[105][105];
ll MOD = 2000000011;
int x;
///formula  n^(n-2)

int main()
{
    int cases, p = 1;
    memset(dp, -1, sizeof(dp));
    pre_comb();
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &x);
        printf("Case #%d: %lld\n", p++, fn(1, x - 1));
    }
    return 0;
}

ll fn(int taken, int left)
{
    if(left == 0)
        return 1;

    if(taken == 0)
        return 0;

    ll& ret = dp[taken][left];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i = 1; i <= left; i++)
        ret += comb[left][i] * fn(taken - 1 + i, left - i), ret = ret % MOD;

    // if(left != x - 1)
    ret += fn(taken - 1, left), ret = ret % MOD;
    return ret;
}

void pre_comb()
{
    for(int left = 0; left <= 100; left++)
        for(int p = 0; p <= 100; p++)
        {
            ll& ret = comb[left][p];
            if(left == 0)
                ret = (p == 0);
            else
            {
                ret = (ret % MOD + comb[left - 1][p] % MOD) % MOD;
                if(p > 0)
                    ret = (ret % MOD + comb[left - 1][p - 1] % MOD) % MOD;
            }
        }
}

/*

*/
