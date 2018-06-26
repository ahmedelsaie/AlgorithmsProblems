#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 100009

int fn(int i, int before);

int dp[MAX][2], n;
pair<ll, ll> array[MAX];

int main()
{
    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld %lld", &array[i].first, &array[i].second);
    printf("%d\n", fn(0, 0));

    return 0;
}

int fn(int i, int before)
{
    if(i == n)
        return 0;

    int& ret = dp[i][before];
    if(ret != -1)
        return ret;

    ret = 0;

    if(i == 0)
        ret = fn(i + 1, 0) + 1;
    else if(i == n - 1)
        ret = fn(i + 1, 0) + 1;
    else
    {
        if(before == 0)
        {
            ///nothing before

            ///drop before
            if(array[i].first - array[i - 1].first > array[i].second)
                ret = max(ret, fn(i + 1, 0) + 1);

            ///drop after
            if(array[i + 1].first - array[i].first > array[i].second)
                ret = max(ret, fn(i + 1, 1) + 1);

            ret = max(ret, fn(i + 1, 0));
        }
        else
        {
            ///before is dropped

            ///drop before
            if((array[i].first - array[i - 1].first) - array[i - 1].second > array[i].second)
                ret = max(ret, fn(i + 1, 0) + 1);

            ///drop after
            if(array[i + 1].first - array[i].first > array[i].second)
                ret = max(ret, fn(i + 1, 1) + 1);

            ret = max(ret, fn(i + 1, 0));

        }

    }

    return ret;
}
