#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 200009

int getbit(int mask, int bit);
int setbit(int mask, int bit, int value);
ll fn(int msk, int modi, int left, ll ten);

int array[20], n = 0, mod;
ll x, dp[262144 + 1][105];

int main()
{
    scanf("%lld %d", &x, &mod);
    memset(array, 0, sizeof(array));
    memset(dp, -1, sizeof(dp));

    ll y = x;

    while(y)
        n++, y /= 10;

    for(int j = n - 1; j >= 0; j--)
        array[j] = x % 10, x /= 10;

    ll ten = 1;
    for(int i = 0; i < n - 1; i++)
        ten = ten * 10;

    printf("%lld\n", fn(0, 0, n, ten));
    return 0;
}

ll fn(int msk, int modi, int left, ll ten)
{
    if(left == 0)
        return modi == 0;

    ll& ret = dp[msk][modi];
    if(ret != -1)
        return ret;

    ret = 0;
    bool visited[10] = {0};

    for(int i = 0; i < n; i++)
    {
        if(getbit(msk, i) == 0 && visited[array[i]] == 0)
        {
            if(left == n)
            {
                if(array[i])
                    visited[array[i]] = 1, ret += fn(setbit(msk, i, 1), (modi + (ten * array[i] % mod)) % mod, left - 1, ten / 10);
            }
            else
                visited[array[i]] = 1, ret += fn(setbit(msk, i, 1), (modi + (ten * array[i] % mod)) % mod, left - 1, ten / 10);
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
