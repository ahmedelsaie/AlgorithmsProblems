#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long

ll fn(ll r, ll left, int mode);

ll dp[MAX + 5][55][2];
ll mod = 1000000007, ans;
int cases = 1, n, tc, k;

int main()
{
    memset(dp, -1, sizeof(dp));
    for(ll i = 5; i <= MAX; i++)
        for(ll j = 5; j < 55; j++)
            fn(i, j, 0), fn(i, j, 1);

    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d", &n, &k);
        if(n == k)
            ans = (ll)0;
        else
            ans = fn(n, k, 0);
        printf("Case %d: %lld", cases++, ans);

        printf("\n");
    }

    return 0;
}

ll fn(ll r, ll left, int mode)
{
    if(r < 0 || left < 0)
        return 0;

    if(r + left == 0)
        return mode == 0;

    //  if(r == 0 && left)
    //    return 0;

    ll& ret = dp[r][left][mode];
    if(ret != -1)
        return ret;

    ret = 0;
    ///i can quit
    if(mode == 1)
    {
        ret += (r % mod * fn(r - 1, left, 0)) % mod, ret %= mod;
        ret += ((((r - 1) * r) % mod) * (fn(r - 1, left, 1) % mod)) % mod, ret %= mod;
    }
    else
    {
        ///one component only
        ll tmp = (r * (r - 1) / 2) % mod;
        tmp = tmp * fn(r - 1, left - 1, 1);
        tmp = tmp % mod;
        ret += tmp;
        ret = ret % mod;
    }

    return ret;
}
