#include <stdio.h>
#include <cstring>

int min(int x, int y);
int fn(int start);
int is_palin(int start, int end);

char array[1005];
int dp[1005];
int dp2[1005][1005];
int n;
const int inf = 99999999;

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%s", array);
        n = strlen(array);
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        printf("%d\n", fn(0));
    }
    return 0;
}

int fn(int start)
{
    if(start == n)
        return 0;

    int &ret = dp[start];
    if(ret != -1)
        return ret;
    ret = inf;

    for(int i = start; i < n; i++)
        if(is_palin(start, i))
            ret = min(ret, fn(i + 1) + 1);

    return ret;
}

int is_palin(int start, int end)
{
    int &flag = dp2[start][end];
    if(flag != -1)
        return flag;

    while(start < end)
    {
        if(array[start] != array[end])
            return flag = 0;
        start++;
        end--;
    }

    return flag = 1;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
