#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 40005
#define ll long long

ll comb(int n, int c);
ll fn(int node);
int fn_cnt(int i);
long long mpow(long long x, long long y, long long mod);

vector<int> tree[MAX];
int father[MAX];
int m, n, cases = 1, cnt[MAX], x, y;
const int mod = 1000000007;
long long fact[MAX + 10];

int main()
{
    memset(father, -1, sizeof(father));

    fact[0] = 1, fact[1] = 1;
    for(int i = 2; i <= MAX; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &n, &m);

        for(int i = 0; i <= n; i++)
            tree[i].clear();

        for(int i = 0; i < m; i++)
            scanf("%d %d", &x, &y), tree[y].push_back(x), father[x] = cases;

        for(int i = 1; i <= n; i++)
            if(father[i] != cases)
                tree[0].push_back(i);

        fn_cnt(0);
        printf("%lld\n", fn(0));
    }

    return 0;
}

ll fn(int node)
{
    if(tree[node].size() == 0)
        return 1;

    ll ret = 1, tmp;
    int nodes = 0;
    if(tree[node].size())
        ret = fn(tree[node][0]);

    for(int j = 0; j < tree[node].size(); j++)
    {

        if(j != 0)
        {
            tmp = fn(tree[node][j]) % mod;

            ll r = (tmp % mod * comb(nodes + cnt[tree[node][j]], cnt[tree[node][j]]) % mod) % mod;
            ret = (ret % mod * r % mod) %

                  mod;
        }
        nodes += cnt[tree[node][j]];

    }

    return ret % mod;
}

ll comb(int n, int c)
{
    if(c == 0 || n == 0)
        return 0;
    if(c == 1)
        return n;

    long long ret = fact[n];
    long long denom = (fact[c] * fact[n - c]) % mod;
    denom = mpow(denom, mod - 2, mod);

    ret = (ret * denom) % mod;
    return ret;
}

int fn_cnt(int i)
{
    if(i == -1)
        return 0;

    int& ret = cnt[i];

    ret = 1;
    if(i == 0)
        ret = 0;
    for(int j = 0; j < tree[i].size(); j++)
        ret += fn_cnt(tree[i][j]);

    return ret;
}

long long mpow(long long x, long long y, long long mod)
{
    long long ret = 1;
    while(y)
    {
        if(y & 1) ret = ret * x, ret %= mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return ret;
}
