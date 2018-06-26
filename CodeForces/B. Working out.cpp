#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 1005

ll fn(int i, int j, int mode);

int r, c;
ll dp[MAX][MAX][4], array[1005][1005];
const ll inf = 9223372036847757;

int main()
{
    memset(dp, -1, sizeof(dp));

    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%lld", &array[i][j]);

    ll ans = -1 * inf, tmp;

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            tmp = fn(i - 1, j, 1) + fn(i + 1, j, 0) + fn(i, j - 1, 3) + fn(i, j + 1, 2);
            ans = max(ans, tmp);

            tmp = fn(i - 1, j, 2) + fn(i + 1, j, 3) + fn(i, j - 1, 1) + fn(i, j + 1, 0);
            ans = max(ans, tmp);
        }

    printf("%lld\n", ans);

    return 0;
}

ll fn(int i, int j, int mode)
{
    if(i < 0 || i >= r || j < 0 || j >= c )
        return -1 * inf;

    if(mode == 0 && i == r - 1 && j == c - 1)
        return array[i][j];

    if(mode == 1 && i == 0 && j == 0)
        return array[i][j];

    if(mode == 2 && i == 0 && j == c - 1)
        return array[i][j];

    if(mode == 3 && i == r - 1 && j == 0)
        return array[i][j];

    ll& ret = dp[i][j][mode];
    if(ret != -1)
        return ret;

    ret = -1 * inf;

    if(mode == 0)
        ret = max(fn(i + 1, j, mode), fn(i, j + 1, mode));
    else if(mode == 1)
        ret = max(fn(i - 1, j, mode), fn(i, j - 1, mode));
    else if(mode == 2)
        ret = max(fn(i - 1, j, mode), fn(i, j + 1, mode));
    else if(mode == 3)
        ret = max(fn(i + 1, j, mode), fn(i, j - 1, mode));

    ret += array[i][j];

    return ret;
}
