#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 100009

int getbit(int mask, int bit);
int get_msk(int msk, int i);
int fn(int msk, int i, int val);

int arr[3][MAX];
int dp[10][MAX];
int rank1[MAX];
int n, cases = 1,x,y;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
                scanf("%d.%d", &x, &y), arr[j][i] = x * 100 + y;

        for(int i = 0; i < n; i++)
            scanf("%d", &rank1[i]), rank1[i]--;

        int ans = -1.0;
        int k = rank1[n - 1];
        bool flag = 0;

        for(int j = 0; j < 8; j++)
        {
            int tmp = get_msk(j, k);
            if(fn(j, n - 2, tmp))
                ans = tmp, flag = 1;
        }

        for(int j = 0; j < 8; j++)
        {
            int tmp = get_msk(j, k);
            if(fn(j, n - 2, tmp) && tmp >= ans)
                ans = tmp, flag = 1;
        }

        printf("Case %d: ", cases++);

        if(flag == 0)
            printf("No solution\n");
        else
            printf("%.2lf\n",(double) ans/100);

    }
    return 0;

}

int fn(int msk, int i, int val)
{
    // if(i == n - 2)
    // printf("%d\n", val);
    if(i < 0)
        return 1;

    int& ret = dp[msk][i];
    if(ret != -1)
        return ret;

    ret = 0;

    int k = rank1[i];

    for(int j = 0; j < 8; j++)
    {
        int tmp = get_msk(j, k);
        //   printf("%d %d\n",i,tmp);
        if(tmp > val || (tmp == val && k < rank1[i + 1]))
            ret = ret | fn(j, i - 1, tmp);
    }

    return ret;
}

int get_msk(int msk, int i)
{
    int ret = 0;
    for(int j = 0; j < 3; j++)
        if(getbit(msk, j) == 1)
            ret += arr[j][i];

    return ret;
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}
