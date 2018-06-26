#include <stdio.h>

long long fn(int before, int left, int mask);
int setbit(int mask, int bit, int value);
void reset();

int base;
int m;
long long dp[13][103][1025];
long long mod = 1000000007;

int main()
{
    int cases;
    long long ans;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d", &base, &m);
        reset();
        ans = 0;

        for(int i = 1; i < base; i++)
            ans += fn(i, m - 1, setbit(0, i, 1)) % mod;

        printf("%lld\n", ans % mod);
    }
    return 0;
}

long long fn(int before, int left, int mask)
{
    if(left == 0)
    {
        if(mask == (1 << base) - 1)
            return 1;
        return 0;
    }

    long long &ret = dp[before][left][mask];
    if(ret != -1)
        return ret;
    ret = 0;

    if(mask == (1 << base) - 1)
        ret++;

    if(before - 1 >= 0)
        ret += fn(before - 1, left - 1, setbit(mask, before - 1, 1)) % mod;

    if(before + 1 < base)
        ret += fn(before + 1, left - 1, setbit(mask, before + 1, 1)) % mod;

    return ret % mod;
}

void reset()
{
    for(int i = 0; i < base + 1; i++)
        for(int j = 0; j < m + 1; j++)
            for(int k = 0; k < (1 << base); k++)
                dp[i][j][k] = -1;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}
