#include <stdio.h>
#include <cstring>
#define ll long long
#define mod 1000000000

ll fn2(int open, int closed);
ll fn(int open, int closed);
void correct(ll& x);

ll dp[1005][1005];
ll dp2[1005][1005];
int visited[1005][1005];
int n, x, y;
int curr = 0;

int main()
{
    memset(dp, -1, sizeof(dp));
    memset(visited, -1, sizeof(visited));
    while(scanf("%d %d %d", &n, &x, &y) != EOF)
    {
        ll ans = fn2(0, 0);
        correct(ans);
        printf("%lld\n", ans);
        curr++;
    }

    return 0;
}

ll fn2(int open, int closed)
{
    if(open > n || closed > n || closed > open)
        return 0;

    if(open == n && closed == n)
        return 1;

    ll& ret = dp2[open][closed];
    int& flag = visited[open][closed];
    if(flag == curr)
        return ret;

    ret = 0;
    flag = curr;
    ll tmp;

    if(open == x)
    {
        for(int i = y - x; i <= n - x; i++)
        {
            tmp = fn(i, i) * fn2(open + i , closed + i + 1);
            ret = (ret + tmp) % mod;
        }
    }
    else
    {
        ret += fn2(open + 1, closed);
        correct(ret);
        ret += fn2(open, closed + 1);
        correct(ret);
    }

    return ret;
}

ll fn(int open, int closed)
{
    if(open < 0 || closed < 0 || closed < open)
        return 0;

    if(open == 0 && closed == 0)
        return 1;

    ll& ret = dp[open][closed];
    if(ret != -1)
        return ret;
    ret = 0;

    ret += fn(open - 1, closed);
    correct(ret);
    ret += fn(open, closed - 1);
    correct(ret);
    return ret;
}

void correct(ll& x)
{
    if(x >= mod)
        x = x - mod;
}
