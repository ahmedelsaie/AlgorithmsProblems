#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll  long long
#define MAX 5005

ll fn(int i, int curr_k);

ll const inf = (1LL << 32);
ll dp[MAX][MAX], array[MAX], sum[MAX];
int n, m, k;

int main()
{
    memset(dp, -1, sizeof(dp));
    sum[0] = 0;

    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &array[i]), sum[i] = sum[i - 1] + array[i];

    printf("%lld\n", fn(1, k));

    return 0;
}

ll fn(int i, int curr_k)
{
    if(curr_k == 0)
        return 0;

    if(i > n || curr_k * m > n - i + 1)
        return -1 * inf;

    ll& ret = dp[i][curr_k];
    if(ret != -1)
        return ret;

    ret = 0;

    ret = max(ret, fn(i + 1, curr_k));
    ret = max(ret, fn(i + m, curr_k - 1) + sum[i + m - 1] - sum[i - 1]);

    return ret;
}
