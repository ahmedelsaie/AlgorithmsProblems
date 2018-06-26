#include <stdio.h>
#include <cstring>

int fn(int x);

int dp[12];

int main()
{
    bool flag = true;
    int x;
    memset(dp, -1, sizeof(dp));

    while(scanf("%d", &x) != EOF)
    {
        if(flag)
            flag = false;
        else
            printf("\n");

        printf("%d\n", fn(x));
    }

    return 0;
}

int fn(int x)
{
    if(x == 0)
        return 1;

    int &ret = dp[x];
    if(ret != -1)
        return ret;

    ret = 0;
    int p1 = 0, p2 = x - 1;

    while(p1 < x)
    {
        ret += (fn(p1) * fn(p2));
        p1++;
        p2--;
    }
    return ret;
}
