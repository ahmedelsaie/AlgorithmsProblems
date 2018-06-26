#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 3005

ll fn(int i, int state);

ll dp[MAX][3], first[MAX], sec[MAX], third[MAX];
int n;

int main()
{
    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", &first[i]);

    for(int i = 0; i < n; i++)
        scanf("%lld", &sec[i]);

    for(int i = 0; i < n; i++)
        scanf("%lld", &third[i]);

    printf("%lld\n", fn(0, 0));

    return 0;
}

ll fn(int i, int state)
{
    if(i == n)
        return 0;

    ll& ret = dp[i][state];
    if(ret != -1)
        return ret;

    ret = 0;

    ///1?
    if(state)
    {
        ret = max(ret, fn(i + 1, 1) + sec[i]);
        if(i + 1 < n)
            ret = max(ret, fn(i + 1, 0) + third[i]);
    }
    else
    {
        ///0?
        ret = max(ret, fn(i + 1, 1) + first[i]);
        if(i + 1 < n)
            ret = max(ret, fn(i + 1, 0) + sec[i]);
    }

    return ret;
}

