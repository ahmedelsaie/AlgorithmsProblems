#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009
#define ll long long

ll fn(int i, int mode);

ll dp[MAX][2];

ll const MOD = 1000000007;

int n, m;

int main()
{
    scanf("%d %d", &n, &m);

    memset(dp, -1, sizeof(dp));

    printf("%lld\n", (fn(0, 1) + fn(0, 0)) % MOD);

    return 0;
}

ll fn(int i, int mode)
{
    if(i == n)
        return mode == 0;

    ll &ret = dp[i][mode];
    if(ret != -1)
        return ret;

    ret = 0;

    if(mode == 0)
        ret += (m * fn(i + 1, 0)) % MOD;
    else
    {
        ret += (m * fn(i + 1, 1)) % MOD, ret %= MOD;
        ret += ((m - 1) * fn(i + 1, 1)) % MOD, ret %= MOD;
        ret += fn(i, 0), ret %= MOD;
    }

    return ret;
}
