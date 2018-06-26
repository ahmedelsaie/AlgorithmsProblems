#include <stdio.h>
#include <cstring>

int fn(int start, int end);
int max(int x, int y);

int dp[1005][1005];
char array[1005];

int main()
{
    int cases, n;
    scanf("%d", &cases);
    gets(array);
    while(cases--)
    {
        gets(array);
        n = strlen(array);
        memset(dp, -1, sizeof(dp));
        printf("%d", fn(0, n - 1));
        printf("\n");
    }
    return 0;
}

int fn(int start, int end)
{
    if(start == end)
        return 1;

    if(end < start)
        return 0;

    int &ret = dp[start][end];
    if(ret != -1)
        return ret;

    ret = -9999999;

    if(array[start] == array[end])
        ret = 2 + fn(start + 1, end - 1);
    else
    {
        ret = max(ret, fn(start + 1, end));
        ret = max(ret, fn(start, end - 1));
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
