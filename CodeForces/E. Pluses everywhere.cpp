#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

void pre_process();
ll powr(ll x, ll y, ll mod);
ll comb(int n, int c);

ll fact[MAX], calc[MAX];
char arr[MAX];

int n, k;
ll mod = 1000000007;
int t;

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", arr);

    pre_process();

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        int b = min(n - i - 1, n - k);

        ll tmp = calc[b];
        tmp = tmp * (arr[i] - '0') % mod;

        ans += tmp, ans %= mod;

        if(i >= k)
        {
            ll tmp = ((arr[i] - '0') * powr(10, n - i - 1, mod)) % mod;
            tmp = (tmp * comb(i, k)) % mod;
            ans += tmp, ans %= mod;
        }
    }

    if(k == 0)
    {
        ans = 0;

        for(int i = 0; i < n; i++)
            ans = ans * 10 + (arr[i] - '0'), ans %= mod;
    }

    printf("%lld\n", ans);

    return 0;
}

void pre_process()
{
    fact[0] = fact[1] = 1;

    for(int i = 2; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    calc[0] = 0;
    int tmp = n - 2;
    ll p = 1;

    for(int i = 1; i <= n && tmp >= k - 1; i++)
    {
        calc[i] = comb(tmp, k - 1) * p;

        calc[i] = (calc[i - 1] + calc[i]) % mod;

        tmp--;
        p *= 10;
        p = p % mod;
        t = i;
    }

    return ;
}

ll powr(ll x, ll y, ll mod)
{
    ll ret = 1;
    while(y)
    {
        if(y & 1) ret = ret * x, ret %= mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return ret;
}

ll comb(int n, int c)
{
    if(c == 0 || n == 0)return 1;
    if(c == 1)return n;

    ll num = fact[n];
    ll denom = (fact[c] * fact[n - c]) % mod;
    denom = powr(denom, mod - 2, mod);

    return (num * denom) % mod;
}
