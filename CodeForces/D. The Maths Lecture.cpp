#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 1005

ll fn(int left, int mod, int flag, int ten);

ll MOD, dp[MAX][105][2];
int n, k;

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %lld", &n, &k, &MOD);
    printf("%lld\n", fn(n, 0, 0, 1) % MOD);

    return 0;
}

ll fn(int left, int mod, int flag, int ten)
{
    if(left == 0)
        return flag;

    ll& ret = dp[left][mod][flag];
    if(ret != -1)
        return ret;

    ret = 0;

    if(flag == 1)
    {
        ///proceed
        ret += 9 * fn(left - 1, mod, flag, ten * 10 % k), ret = ret % MOD;
        if(left != 1)
            ret += fn(left - 1, mod, flag, ten * 10 % k) % MOD, ret = ret % MOD;
    }
    else
    {
        for(int i = 1; i <= 9; i++)
        {
            if((ten * i + mod) % k == 0)
                ret += fn(left - 1, 0, 1, ten * 10 % k) % MOD, ret = ret % MOD;
            else
                ret += fn(left - 1, (ten * i + mod) % k, 0, ten * 10 % k) % MOD, ret = ret % MOD;
        }

        if(left != 1)
        {
         //   if((ten * 0 + mod) % k == 0)
          //      ret += fn(left - 1, 0, 1, ten * 10 % k) % MOD, ret = ret % MOD;
          //  else
                ret += fn(left - 1, (ten * 0 + mod) % k, 0, ten * 10 % k) % MOD, ret = ret % MOD;
        }
    }

    return ret % MOD;
}
