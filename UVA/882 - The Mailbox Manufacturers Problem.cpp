#include <stdio.h>
#include <cstring>
int fn(int start, int end, int box);
int max(int x, int y);
int min(int x, int y);
int dp[101][101][11];
int n, box;
const int inf = 999999999;

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &box, &n);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", fn(0, n, box));
    }

    return 0;
}

int fn(int start, int end, int box)
{
    if(start < 0 || end > n || start > end)
        return 0;

    if(box == 0)
        return inf;

    if(start == end)
        return start;

    int &ret = dp[start][end][box];
    if(ret != -1)
        return ret;
    ret = inf;
    int temp;

    for(int i = start; i <= end; i++)
    {

        temp = i + max(fn(start, i - 1, box - 1), fn(i + 1, end, box));
        ret = min(ret, temp);
    }

    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    return y;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    return y;
}

