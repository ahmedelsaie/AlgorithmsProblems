#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 70

ll fn(int i, int left, int f1, int f2);
pair<int, int> check2(int f1, int f2, int place, int need);
ll bin();
ll check(ll x);

int visited[MAX][MAX][2][2], small[MAX], big[MAX], n, cases = 0, ones;
ll dp[MAX][MAX][2][2], num;

int main()
{
    memset(visited, -1, sizeof(visited));
    scanf("%lld %d", &num, &ones);
    printf("%lld\n", bin());
    //check(1);
    return 0;
}

ll bin()
{
    ll big = 1000000000000000001, small = 1, mid, ret = -1, tmp;

    while(big >= small)
    {
        mid = (big + small) / 2;

        tmp = check(mid);
    //    printf("%lld %lld\n", mid, tmp);

        if(tmp == num)
            return mid;

        if(tmp > num)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return ret;
}

ll check(ll x)
{
    ll ret = 0;
    int cnt1 = 0, j, cnt2 = 0;
    ll y = x;

    while(y)
        cnt1++, y /= 2;

    y = 2 * x;
    while(y)
        cnt2++, y /= 2;

    y = x, j = cnt2 - 1, small[0] = 0;
    while(y)
        small[j] = (y % 2), j--, y /= 2;

    y = 2 * x, j = cnt2 - 1;
    while(y)
        big[j] = (y % 2), j--, y /= 2;
    cases++;
    //  printf("%d\n", cnt);

    // for(int i = 0; i <= cnt; i++)
    //    printf("%d", small[i]);

    // printf("\n");
    // for(int i = 0; i <= cnt; i++)
    //     printf("%d", big[i]);

    n = cnt2;
    ret = fn(0, ones, 0, 0);
  // printf("%lld %lld\n", x, ret);
//   printf("%lld\n", ret);
    return ret;
}

ll fn(int i, int left, int f1, int f2)
{
    if(left < 0)
        return 0;

    if(i == n)
        return (left == 0 && f1);

    int& flag = visited[i][left][f1][f2];
    ll& ret = dp[i][left][f1][f2];
    if(flag == cases)
        return ret;

    ret = 0, flag = cases;

    pair<int, int> tmp = check2(f1, f2, i, 0);
    if(tmp.first != -1 && tmp.second != -1)
        ret += fn(i + 1, left, tmp.first, tmp.second);

    tmp = check2(f1, f2, i, 1);
    if(tmp.first != -1 && tmp.second != -1)
        ret += fn(i + 1, left - 1, tmp.first, tmp.second);

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


