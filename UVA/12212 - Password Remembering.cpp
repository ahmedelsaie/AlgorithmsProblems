#include <bits/stdc++.h>
using namespace std;
#define MAX 105
#define ll unsigned long long

ll fn(int i, int i2, int s1, int b1, int s2, int b2, int f);
int check(int i, int f1, int j, int refr, int flag);
int check2(int i, int f1, int j, int refr, int flag);
int pre_process();
ll solve();

int n, small[MAX], big[MAX], tc, cases = 1;
ll x, y, dp[MAX][MAX][2][2][2][2][2];

int main()
{
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%llu %llu", &x, &y);
        n = pre_process();
        memset(dp, -1, sizeof(dp));
        ll ret = fn(0,  n - 1, 0, 0, 1, 1, 0);;
        printf("Case %d: %llu\n", cases++, ret);
    }

    return 0;
}

ll fn(int i, int i2, int s1, int b1, int s2, int b2, int f)
{
    if(i == n) return  ((s2 && b2) || (i2 != -1 && s2));

    ll& ret = dp[i][i2][s1][b1][s2][b2][f];
    if(ret != -1)return ret;
    ret = 0;

    if(f)
    {
        for(int j = 0; j < 10; j++)
        {
            int new_s1 = check(i, s1, j, small[i], 0);
            int new_b1 = check(i, b1, j, big[i], 1);

            int new_s2 = check2(i2, s2, j, small[i2], 0);
            int new_b2 = check2(i2, b2, j, big[i2], 1);

            if(new_s1 != -1 && new_s2 != -1 && new_b1 != -1 && new_b2 != -1)
                ret += fn(i + 1, i2 - 1, new_s1, new_b1, new_s2, new_b2, f);
        }
    }
    else
    {
        int new_s1 = check(i, s1, 0, small[i], 0);
        int new_b1 = check(i, b1, 0, big[i], 1);

        if(new_s1 != -1 && new_b1 != -1)
            ret += fn(i + 1, n - 1, new_s1, new_b1, 1, 1, 0);

        for(int j = 1; j < 10; j++)
        {
            int new_s1 = check(i, s1, j, small[i], 0);
            int new_b1 = check(i, b1, j, big[i], 1);

            int new_s2 = check2(i2, s2, j, small[i2], 0);
            int new_b2 = check2(i2, b2, j, big[i2], 1);

            if(new_s1 != -1 && new_s2 != -1 && new_b1 != -1 && new_b2 != -1)
                ret += fn(i + 1, n - 2, new_s1, new_b1, new_s2, new_b2, 1);
        }
    }

    return ret;
}

int check2(int i, int f1, int j, int refr, int flag)
{
    if(flag == 0)
    {
        if(j == refr) return f1;
        if(j > refr) return 1;
        if(j < refr) return 0;
        return -1;
    }
    else
    {
        if(j == refr) return f1;
        if(j < refr) return 1;
        if(j > refr) return 0;
        return -1;
    }
}

int check(int i, int f1, int j, int refr, int flag)
{
    if(flag == 1)
    {
        if(f1 == 1) return 1;
        if(j < refr)return 1;
        if(j == refr) return 0;

        return -1;
    }
    else
    {
        if(f1 == 1) return 1;
        if(j > refr)return 1;
        if(j == refr) return 0;

        return -1;
    }
}

int pre_process()
{
    ll tmp = y;
    int cnt = 0;

    while(tmp)
        cnt++, tmp = tmp / 10;

    memset(big, 0, sizeof(big));
    memset(small, 0, sizeof(small));

    for(int i = cnt - 1; i >= 0; i--)
        small[i] = x % 10, x = x / 10;

    for(int i = cnt - 1; i >= 0; i--)
        big[i] = y % 10, y = y / 10;

    return cnt;
}

