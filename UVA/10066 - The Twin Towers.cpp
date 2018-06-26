#include <stdio.h>
#include <cstring>

int fn(int x, int y);
int max(int x, int y);

int n, m;
int array1[105];
int array2[105];
int dp[105][105];

int main()
{
    int ans, cases = 1;
    while(true)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d", &array1[i]);

        for(int i = 0; i < m; i++)
            scanf("%d", &array2[i]);

        memset(dp, -1, sizeof(dp));
        ans = fn(0, 0);

        printf("Twin Towers #%d\n", cases++);
        printf("Number of Tiles : %d\n\n", ans);
    }

    return 0;
}

int fn(int x, int y)
{
    if(x == n || y == m)
        return 0;

    int &ret = dp[x][y];
    if(ret != -1)
        return ret;
    ret = 0;

    if(array1[x] == array2[y])
        ret = 1 + fn(x + 1, y + 1);
    else
    {
        ret = max(ret, fn(x + 1, y));
        ret = max(ret, fn(x, y + 1));
    }
    return ret;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

