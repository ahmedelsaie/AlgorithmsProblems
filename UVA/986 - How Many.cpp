#include <stdio.h>
#include <cstring>

int fn(int x, int y, bool direct, int left);

int n_peaks, peak_height, n;
int dp[55][25][25][2];

int main()
{
    int ans;
    while(scanf("%d %d %d", &n, &n_peaks, &peak_height) != EOF)
    {
        memset(dp, -1, sizeof(dp));
        ans = fn(2 * n, 0, false, n_peaks);
        printf("%d\n", ans);
    }
    return 0;
}

int fn(int x, int y, bool direct, int left)
{
    if(y == x && !direct && x != 0)
        return 0;

    if(x < 0 || y < 0 || left < 0 || y > x)
        return 0;

    if(x == 0)
    {
        if(y == 0 && left == 0)
            return 1;
        return 0;
    }

    int &ret = dp[x][y][left][direct];
    if(ret != -1)
        return ret;
    ret = 0;

    if(direct)
    {
        int new_left = left;
        if(y == peak_height)
            new_left--;

        int i = 1;
        while(x - i >= 0 && y - i >= 0)
        {
            ret += fn(x - i, y - i, !direct, new_left);
            i++;
        }
    }
    else
    {
        int i = 1;
        while(x - i >= 0 && y + i <= n)
        {
            ret += fn(x - i, y + i, !direct, left);
            i++;
        }
    }
    return ret;
}

