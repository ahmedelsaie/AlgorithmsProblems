#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define MAX 1000009

char array[MAX];
ll dp[MAX][5];
int n;
ll mod = 1000000007;
ll fn(int i, int before);

int main()
{
    scanf("%s", array);
    n = strlen(array);
    memset(dp, -1, sizeof(dp));

    ll ret = 0;
    if(array[0] == '?')
    {
        ret += fn(1, 3), ret = ret % mod;
        ret += fn(1, 1), ret = ret % mod;
        ret += fn(1, 4), ret = ret % mod;
    }
    else if(array[0] == '*')
        ret += fn(1, 3), ret = ret % mod;
    else if(array[0] == '1')
        ret += fn(1, 1), ret = ret % mod;
    else if(array[0] == '0')
        ret += fn(1, 4), ret = ret % mod;
    printf("%lld\n", ret);

    return 0;
}

ll fn(int i, int before)
{
    //  printf("%d %d\n",i,before);
    if(i == n)
    {
        if(before == 2 || before == 1)
            return 0;
        return 1;
    }

    ll& ret = dp[i][before];
    if(ret != -1)
        return ret;
    ret = 0;

    if(before == 0)
    {
        if(array[i] == '1' || array[i] == '?')
            ret += fn(i + 1, 1), ret = ret % mod;
        if(array[i] == '0' || array[i] == '?')
            ret += fn(i + 1, 4), ret = ret % mod;
    }
    else if(before == 1 || before == 2)
    {
        if(array[i] == '*' || array[i] == '?')
            ret += fn(i + 1, 3), ret = ret % mod;
    }
    else if(before == 3)
    {
        if(array[i] == '*' || array[i] == '?')
            ret += fn(i + 1, 3), ret = ret % mod;

        if(array[i] == '2' || array[i] == '?')
            ret += fn(i + 1, 2), ret = ret % mod;

        if(array[i] == '1' || array[i] == '?')
            ret += fn(i + 1, 0), ret = ret % mod;
    }
    else if(before == 4)
    {
        // if(array[i] == '2' || array[i] == '?')
        //   ret += fn(i + 1, 2), ret = ret % mod;

        if(array[i] == '1' || array[i] == '?')
            ret += fn(i + 1, 1), ret = ret % mod;

        if(array[i] == '0' || array[i] == '?')
            ret += fn(i + 1, 4), ret = ret % mod;
    }

    return ret;
}
