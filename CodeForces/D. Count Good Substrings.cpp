#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 100009

ll fn(int i, int start, int parity);

ll dp[MAX][2][2], ans;
int even, n;
char array[MAX];

int main()
{
    scanf("%s", array);
    n = strlen(array);

    even = 1, ans = 0;
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= n; i++)
        ans += fn(i + 1, array[i] - 'a', 0);

    printf("%lld ", ans);

    even = 0, ans = 0;
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= n; i++)
        ans += fn(i + 1, array[i] - 'a', 0);
    printf("%lld\n", ans + (ll)n);

    return 0;
}

ll fn(int i, int start, int parity)
{
    if(i >= n)
        return 0;

    ll& ret = dp[i][start][parity];
    if(ret != -1)
        return ret;

    ret = 0;

    ///1 even
    ///0 odd

    ///end here && take me
    if(array[i] - 'a' == start)
    {
        int tmp = !parity;
        if(tmp && even)
            ret++;

        if(!tmp && !even)
            ret++;
    }

    ///proceed
    ret += fn(i + 1, start, !parity);

    return ret;
}
