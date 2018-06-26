#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#define ll long long
using namespace std;

ll fn(int x, int y);
int gcd(int a, int b);
ll edges(int x, int y);

ll dp[1005][1005], ans;

int main()
{
    int x = 5, y = 5, cases = 1;
    for(int i = 2; i <= 1004; i++)
        for(int j = i; j <= 1004; j++)
            dp[i][j] = 2 * (gcd(i, j) - 1);

    while(true)
    {
        scanf("%d %d", &x, &y);
        if(x + y == 0)
            break;
        x++, y++;

        ans = x * y;
        ans = (ans * (ans - 1) * (ans - 2)) / 6;
        ans -= fn(x, y);
        printf("Case %d: %lld\n", cases++, ans);
    }

    return 0;
}

ll fn(int x, int y)
{
    ll ret = 0, tmp;
    ret += edges(x, y);
    for(int i = 2; i <= x; i++)
        for(int j = 2; j <= y; j++)
            tmp = dp[min(i, j)][max(i, j)] * (x - i) * (y - j), ret += tmp;
    return ret;
}

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

ll edges(int x, int y)
{
    ll x2 = x, y2 = y;
    x2 = (x2 * (x2 - 1) * (x2 - 2)) / 6;
    y2 = (y2 * (y2 - 1) * (y2 - 2)) / 6;
    return (x2 * y + y2 * x);
}
