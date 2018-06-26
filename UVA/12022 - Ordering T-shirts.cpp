#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ull int

ull comb(int m, int n);
ull fn(int left);
ull dp[50];
ull fac[12];

int main()
{
    int cases, x;
    memset(dp, -1, sizeof(dp));
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 11; i++)
        fac[i] = i * fac[i - 1];

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &x);
        printf("%d\n", fn(x));
    }

    return 0;
}

ull fn(int left)
{
    if(left == 0)
        return 1;

    ull& ret = dp[left];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i = 1; i <= left; i++)
        ret += comb(left, i) * fn(left - i);
    return ret;
}

ull comb(int m, int n)
{
    ull x = fac[m];
    x = x / fac[n];
    x = x / fac[m - n];
    return x;
}
