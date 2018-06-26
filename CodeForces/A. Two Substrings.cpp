#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 100009
int fn(int i, int t0, int t1);

int dp[MAX][2][2], n;
char array[MAX];

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%s", array);
    n = strlen(array);

    int ans = fn(0, 0, 0);
    if(ans)
        printf("YES");
    else
        printf("NO");
    printf("\n");

    return 0;
}

int fn(int i, int t0, int t1)
{
    if(t1 && t0)
        return 1;

    if(i == n - 1)
        return 0;

    int& ret = dp[i][t0][t1];
    if(ret != -1)
        return ret;

    ret = 0;

    ret = ret | fn(i + 1, t0, t1);

    if(array[i] == 'A' && array[i+1] == 'B')
        ret = ret | fn(i + 2, 1, t1);

    if(array[i] == 'B' && array[i+1] == 'A')
        ret = ret | fn(i + 2, t0, 1);

    return ret;
}
