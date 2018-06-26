#include <stdio.h>
#include <cstring>

int fn(int i, int left);
int min(int x, int y);

int dp[105][10009];
const int inf = 99999999;

int main()
{
    int cases, n;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &n);
        printf("%d\n", fn(0, n));
    }

    return 0;
}

int fn(int i, int left)
{
    if(left == 0)
        return 0;

    if(left < 0 || i == 101)
        return inf;

    int &ret = dp[i][left];
    if(ret != -1)
        return ret;
    ret = inf;

    ret = min(ret, fn(i + 1, left));
    ret = min(ret, fn(i + 1, left - i * i) + 1);
    ret = min(ret, fn(i, left - i * i) + 1);

    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

