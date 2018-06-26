#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <list>
using namespace std;
#define ll long long
#define MAX 1000
#define mod 1000000007

void pre_comb(ll MOD);
ll fn(int place, int finished, int vac);

ll dp_comb[MAX + 5][MAX + 5];
ll dp[MAX + 5][MAX + 5];
int array[MAX + 5], n, total = 0;

int main()
{
    pre_comb(mod);
    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]), total += array[i];

    printf("%lld\n", fn(0, 0, 0) % mod);

    return 0;
}

ll fn(int place, int finished, int vac)
{
    if(finished == n)
        return 1;

    if(place == total)
        return 0;

    ll& ret = dp[place][finished];
    if(ret != -1)
        return ret;
    ret = 0;

    ret += fn(place + 1, finished, vac + 1) % mod;

    if(vac >= array[finished] - 1)
        ret += dp_comb[vac][array[finished] - 1] * fn(place + 1, finished + 1, vac - (array[finished] - 1) % mod);

    ret = ret % mod;

    return ret;
}

void pre_comb(ll MOD)
{
    for(int left = 0; left <= MAX; left++)
        for(int p = 0; p <= MAX; p++)
        {
            ll& ret = dp_comb[left][p];
            if(left == 0)
                ret = (p == 0);
            else
            {
                ret = (ret % MOD + dp_comb[left - 1][p] % MOD) % MOD;
                if(p > 0)
                    ret = (ret % MOD + dp_comb[left - 1][p - 1] % MOD) % MOD;
            }
        }
}
