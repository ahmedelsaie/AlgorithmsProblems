#include <stdio.h>
#include <cstring>
#define ll long long
#define mod 1000000007

ll dp[2009][2009];
int n, h;
int array[2009];

ll fn(int i, int h);

int main()
{
    bool flag = true;
    int x;
    scanf("%d %d", &n, &h);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if(x > h)
            flag = false;
        else
            array[i] = h - x;
    }
    if(flag == false)
        printf("%d\n", 0);
    else
        memset(dp, -1, sizeof(dp)), printf("%lld\n", fn(0, 0) % mod);


    return 0;
}

ll fn(int i, int h)
{
    // printf("%d %d\n", i, h);
    if(i == n)
    {
        if(h == 0)
            return 1;
        return 0;
    }

    if(h > array[i] || h + 1 < array[i] || h < 0)
        return 0;

    ll& ret = dp[i][h];
    if(ret != -1)
        return ret % mod;
    ret = 0;
    ll tmp;
    if(array[i] == h)
    {
        ret +=  fn(i + 1, h) % mod;
        tmp = fn(i + 1, h - 1);
        if(h != 0)
            tmp = tmp * h;
        ret += tmp  % mod;
    }
    else
    {
        ret += fn(i + 1, h + 1) % mod;
        tmp = fn(i + 1, h);
        if(h != 0)
            tmp = tmp * (h + 1);
        ret += tmp  % mod;
        //ret += h * fn(i + 1, h-1) % mod;
    }


    return ret % mod;
}
