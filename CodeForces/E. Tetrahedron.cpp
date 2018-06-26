#include <stdio.h>
#include <cstring>
long long fn(long long left, int last);
long long fn_table(int x);

long long dp[2][5];

long long const MOD=1000000007;
long long x;

int main()
{
    scanf("%lld", &x);
    printf("%lld\n", fn_table(x));
    return 0;
}

long long fn_table(int x)
{
    ///Base Case
    for(int i = 0; i <= 4; i++)
        dp[0][i] = 0;

    dp[0][1] = 1;

    bool switch1 = false;

    for(int left = 1; left <= x; left++)
    {
        for(int last = 1; last <= 4; last++)
        {
            long long &ret = dp[!switch1][last];
            ret = 0;
            if(last != 1)
                ret += dp[switch1][1] % MOD;

            if(last != 2)
                ret += dp[switch1][2] % MOD;

            if(last != 3)
                ret += dp[switch1][3] % MOD;

            if(last != 4)
                ret += dp[switch1][4] % MOD;
        }

        switch1 = !switch1;
    }

    return dp[switch1][1] % MOD;
}

long long fn(long long left, int last)
{
    if(left == 0)
    {
        if(last == 1)
            return 1;
        return 0;
    }

    long long &ret = dp[left][last];
    if(ret != -1)
        return ret;
    ret=0;

    if(last != 1)
        ret += fn(left-1 ,1) % MOD;

    if(last != 2)
        ret += fn(left-1, 2) % MOD;

    if(last != 3)
        ret += fn(left-1, 3) % MOD;

    if(last != 4)
        ret += fn(left-1, 4) % MOD;

    return ret % MOD;
}
