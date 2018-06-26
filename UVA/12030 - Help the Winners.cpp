#include <stdio.h>
#include <cstring>
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
long long fn(int i, int mask, bool super, bool bad);
void reset();

int n;
int arr[16][16];
long long dp[(1 << 15) + 5][2][2];

int main()
{
    int cases, p = 1;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &arr[i][j]);

        reset();

        printf("Case %d: %lld\n", p, fn(0, 0, 0, 0));
        p++;
    }

    return 0;
}

long long fn(int i, int mask, bool super, bool bad)
{
    if(i == n)
    {
        if(super)
            return 1;

        if(bad)
            return 0;
        return 1;
    }

    long long &ret = dp[mask][super][bad];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int j = 0; j < n; j++)
    {
        if(!getbit(mask, j))
        {
            if(arr[i][j] == 1)
                ret += fn(i + 1, setbit(mask, j, 1), super, bad);

            if(arr[i][j] == 2)
                ret += fn(i + 1, setbit(mask, j, 1), true, bad);

            if(arr[i][j] == 0)
                ret += fn(i + 1, setbit(mask, j, 1), super, true);
        }
    }

    return ret;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}

void reset()
{
    for(int i = 0; i < (1 << n) + 1; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = -1;
}
