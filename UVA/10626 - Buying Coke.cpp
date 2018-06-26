#include <stdio.h>
#include <cstring>
int fn(int n1, int n5, int n10, int left);
int min(int x, int y);

int dp[800][202][52];
int inf = 2e9;
//500 100 50

int main()
{
    int coke, cases, first, sec, third, ans;
    scanf("%d", &cases);
    while(cases--)
    {
        ///1 5 10
        scanf("%d %d %d %d", &coke, &first, &sec, &third);
        memset(dp, -1, sizeof(dp));
        ans = fn(first, sec, third, coke);

        printf("%d", ans);
        printf("\n");
    }
    return 0;
}

int fn(int n1, int n5, int n10, int left)
{
    if(n1 < 0 || n5 < 0 || n10 < 0)
        return inf;

    if(left == 0)
        return 0;

    int &ret = dp[n1][n5][n10];
    if(ret != -1)
        return ret;
    ret = inf;
    int temp;

    ///all ones
    if(n1 >= 8)
    {
        temp = fn(n1 - 8, n5, n10, left - 1) + 8;
        ret = min(ret, temp);
    }

    ///all fives
    if(n5 >= 2)
    {
        temp = fn(n1 + 2, n5 - 2, n10, left - 1) + 2;
        ret = min(ret, temp);
    }

    ///all tens
    if(n10 >= 1)
    {
        temp = fn(n1 + 2, n5, n10 - 1, left - 1) + 1;
        ret = min(ret, temp);
    }

    ///5+3*1
    if(n5 >= 1 && n1 >= 3)
    {
        temp = fn(n1 - 3, n5 - 1, n10, left - 1) + 4;
        ret = min(ret, temp);
    }

    if (n10 >= 1 && n1 >= 3)
    {
        temp = fn(n1 - 3, n5 + 1, n10 - 1, left - 1) + 4;
        ret = min(ret, temp);
    }

    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
