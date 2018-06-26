#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll unsigned long long

ll fn(int left, int throwe);
pair<ll, ll> get();
ll gcd(ll a, ll b);

ll dp[150][25];
bool visited[150][25];
int val, n;

int main()
{
    pair<ll, ll> ans;
    memset(visited, 0, sizeof(visited));
    while(true)
    {
        scanf("%d %d", &n, &val);
        if(n + val == 0)
            break;
        ans = get();
        if(ans.first == 0 || ans.second == 1)
            printf("%llu\n", ans.first);
        else
            printf("%llu/%llu\n", ans.first, ans.second);
    }

    return 0;
}

pair<ll, ll> get()
{
    ll target = 0, all = 1;
    for(int i = val; i <= 6 * n; i++)
        target += fn(i, n);

    for(int i = 0; i < n; i++)
        all = all * 6;

    pair<ll, ll> ret;
    ll g = gcd(target, all);
    ret.first = target / g, ret.second = all / g;
    return ret;
}

ll fn(int left, int throwe)
{
    if(left < 0)
        return 0;

    if(throwe == 0)
        return (left == 0);

    ll& ret = dp[left][throwe];
    bool& flag = visited[left][throwe];
    if(flag)
        return ret;

    ret = 0, flag = 1;

    for(int i = 1; i <= 6; i++)
        ret += fn(left - i, throwe - 1);

    return ret;
}

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
