#include <stdio.h>
#include <cstring>
#define MOD 10056
#define ll long long

ll fn(int left);
void pre_comb();
void tabular(int x);

ll dp_comb[1005][1005];
ll dp[1005];

int main()
{
    //  memset(dp, -1, sizeof(dp));
    pre_comb();
    int cases, x, p = 1;

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &x);
        tabular(x);
        printf("Case %d: %lld\n", p++, dp[x]);
    }

    return 0;
}

ll fn(int left)
{
    if(left <= 0)
        return 1;

    ll& ret = dp[left];
    if(ret != -1)
        return ret ;
    ret = 0;
    for(int i = 1; i <= left; i++)
    {
        ll x = fn(left - i) % MOD;
        ret = (ret % MOD) + (x * dp_comb[left][i] % MOD) % MOD; // % MOD)) % MOD;
        ret = ret % MOD;
    }
    return ret % MOD;
}

void tabular(int x)
{
    for(int left = 0; left <= x; left++)
    {
        ll& ret = dp[left];
        ret = 0;
        if(left == 0)
            ret = 1;
        else
        {
            for(int i = 1; i <= left; i++)
            {
                ll x = dp[left - i] % MOD;
                ret = (ret % MOD) + (x * dp_comb[left][i] % MOD) % MOD; // % MOD)) % MOD;
                ret = ret % MOD;
            }
        }
    }

}

void pre_comb()
{
    for(int left = 0; left <= 1000; left++)
        for(int p = 0; p <= 1000; p++)
        {
            ll& ret = dp_comb[left][p];
            if(left == 0)
                ret = (p == 0);
            else
            {
                ret = (ret % MOD + dp_comb[left - 1][p] % MOD) % MOD;
                if(p > 0)
                    ret = (ret % MOD + dp_comb[left - 1][p - 1] % MOD) % MOD;
            }
        }


}
