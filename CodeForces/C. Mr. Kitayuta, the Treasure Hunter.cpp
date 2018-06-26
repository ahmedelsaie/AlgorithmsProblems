#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 30009

int fn(int i, int step);

int tres[MAX], dp[MAX][2000], n, x = 0, d, m = 0;
const int inf = 9999999999;
int correct = 1000;

int main()
{
    memset(dp, -1, sizeof(dp));
    memset(tres, 0, sizeof(tres));

    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++)
        scanf("%d", &x), tres[x]++, m = max(m, x);
    n = m;
    printf("%d\n", fn(d, 0));

    return 0;
}

int fn(int i, int step)
{
    // if(i==78)
    //printf("%d\n", i);
    if(i > n)
        return 0;

    int& ret = dp[i][step + correct];
    if(ret != -1)
        return ret;

    ret = 0;

    if(step+d > 0)
        ret = max(ret, fn(i + d + step, step));

    ret = max(ret, fn(i + d + step + 1, step + 1));

    if(d + step - 1 > 0)
        ret = max(ret, fn(d + i + step - 1, step - 1));

    ret += tres[i];

    return ret;
}





