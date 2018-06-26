#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 1000

pair<int, int> check2(int f1, int f2, int place, int need);
ll fn(int i, int mod, int sum, int f1, int f2);
void reset();
int cnt(int x);

int  dp[32][10001][280][2][2], n, big[35], small[35];
int a, b, cases, k;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d %d", &a, &b, &k);
        reset();
        int ans = fn(0, 0, 0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}

void reset()
{
    memset(big, 0, sizeof(big));
    memset(small, 0, sizeof(small));

    n = cnt(b);
    int tmp = b;

    for(int i = n - 1; i >= 0; i--)
        big[i] = tmp % 10, tmp /= 10;

    tmp = a;
    for(int i = n - 1; i >= 0 && tmp; i--)
        small[i] = tmp % 10, tmp /= 10;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
            for(int c = 0; c <= 9 * n; c++)
                dp[i][j][c][0][0] = dp[i][j][c][1][0] = dp[i][j][c][0][1] = dp[i][j][c][1][1] = -1;
    return ;
}

int cnt(int x)
{
    int ret = 0;
    if(x == 0)
        return 1;

    while(x)
        ret++, x /= 10;

    return ret;
}

ll fn(int i, int mod, int sum, int f1, int f2)
{
    if(i == n)
        return (mod % k == 0 && sum % k == 0);// && f1 && f2);

    int& ret = dp[i][mod][sum][f1][f2];
    if(ret != -1)
        return ret;

    ret = 0;

    for(int j = 0; j <= 9; j++)
    {
        pair<int, int> tmp = check2(f1, f2, i, j);
        if(tmp.first != -1 && tmp.second != -1)
            ret += fn(i + 1, (mod * 10 + j) % k, (sum + j) % k, tmp.first, tmp.second);
    }

    return ret;
}

pair<int, int> check2(int f1, int f2, int place, int need)
{
    pair<int, int> ret;
    ret.first = f1, ret.second = f2;
    if(f1 == 0)
    {
        if(need > small[place])
            ret.first = 1;
        else if(need < small[place])
            ret.first = -1;
    }

    if(f2 == 0)
    {
        if(need > big[place])
            ret.second = -1;
        else if(need < big[place])
            ret.second = 1;
    }

    return ret;
}
