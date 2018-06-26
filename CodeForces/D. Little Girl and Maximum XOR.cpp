#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 70

const ll inf = 99999999999;
ll fn(int place, int f1, int f2, int f3, int f4);
pair<int, int> check(int f1, int f2, int place, int need);
void to_binary(ll r, int array[]);

int n, big[MAX], small[MAX];
ll dp[MAX][2][2][2][2], x, y;

int main()
{
    memset(dp, -1, sizeof(dp));

    scanf("%lld %lld", &x, &y);

    to_binary(y, big);
    to_binary(x, small);

    printf("%lld\n", fn(0, 0, 0, 0, 0));
    return 0;
}

void to_binary(ll r, int array[])
{
    int tmp[MAX], j = 0;
    ll k = r;
    while(r)
    {
        if(r % 2 == 0)
            tmp[j] = 0;
        else
            tmp[j] = 1;
        j++;
        r = r / 2;
    }

    if(k == y)
    {
        n = j;
        int k = j - 1;
        for(int i = 0; i < j; i++)
            array[k] = tmp[i], k--;
    }
    else
    {
        memset(small, 0, sizeof(small));

        int k = n - 1;
        for(int i = 0; i < j; i++)
            array[k] = tmp[i], k--;
    }
}

ll fn(int place, int f1, int f2, int f3, int f4)
{
    if(place == n)
        return 0;

    ll& ret = dp[place][f1][f2][f3][f4];
    if(ret != -1)
        return ret;

    ret = -1 * inf;
    pair<int, int> tmp10 = check(f1, f2, place, 0);
    pair<int, int> tmp11 = check(f1, f2, place, 1);

    pair<int, int> tmp20 = check(f3, f4, place, 0);
    pair<int, int> tmp21 = check(f3, f4, place, 1);

    ll a = 1;
    for(int i = 0; i < n - place - 1; i++)
        a = 2 * a;

    ///1 1
    if(tmp11.first != -1 && tmp11.second != -1 && tmp21.first != -1 && tmp21.second != -1)
        ret = max(ret, fn(place + 1, tmp11.first, tmp11.second, tmp21.first, tmp21.second));

    ///0 0
    if(tmp10.first != -1 && tmp10.second != -1 && tmp20.first != -1 && tmp20.second != -1)
        ret = max(ret, fn(place + 1, tmp10.first, tmp10.second, tmp20.first, tmp20.second));

    ///1 0
    if(tmp11.first != -1 && tmp11.second != -1 && tmp20.first != -1 && tmp20.second != -1)
        ret = max(ret, fn(place + 1, tmp11.first, tmp11.second, tmp20.first, tmp20.second) + a);

    ///0 1
    if(tmp10.first != -1 && tmp10.second != -1 && tmp21.first != -1 && tmp21.second != -1)
        ret = max(ret, fn(place + 1, tmp10.first, tmp10.second, tmp21.first, tmp21.second) + a);

    return ret;
}

pair<int, int> check(int f1, int f2, int place, int need)
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
