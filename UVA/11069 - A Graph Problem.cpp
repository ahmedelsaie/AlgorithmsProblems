#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 80

int fn(int left);

int dp[MAX];

int main()
{
    int n;
    memset(dp, -1, sizeof(dp));

    while(scanf("%d", &n) != EOF)
        printf("%d\n", fn(n) + fn(n - 1));

    return 0;
}

int fn(int left)
{
    if(left < 0)
        return 0;

    if(left == 1 || left == 2)
        return 1;

    int& ret = dp[left];
    if(ret != -1)
        return ret;
    ret = 0;

    ret += fn(left - 2);
    ret += fn(left - 3);

    return ret;
}
