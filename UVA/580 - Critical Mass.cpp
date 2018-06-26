#include <stdio.h>
#include <cstring>

int fn(int left, bool before2, bool before1, bool expl);

int dp[1000][2][2][2];

int main()
{
    memset(dp, -1, sizeof(dp));
    int x;
    while(true)
    {
        scanf("%d", &x);
        if(x == 0)
            break;
        printf("%d\n", fn(x, false, false, false));
    }
    return 0;
}

int fn(int left, bool before2, bool before1, bool expl)
{
    if(left == 0)
    {
        if(expl)
            return 1;
        return 0;
    }

    int &ret = dp[left][before2][before1][expl];
    if(ret != -1)
        return ret;
    ret = 0;

    if(before1 && before2)
    {
        ret += fn(left - 1, before1, true, true);
        ret += fn(left - 1, before1, false, expl);
    }
    else
    {
        ret += fn(left - 1, before1, true, expl);
        ret += fn(left - 1, before1, false, expl);
    }
    return ret;
}


