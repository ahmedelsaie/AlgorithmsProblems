#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <list>
using namespace std;
#define ll long long
#define MAX 55

ll fn(int left);
void trace(int left, ll with_me, int nw);

ll dp[MAX + 5], k;
int n;

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d %lld", &n, &k);

    fn(n);
    k--;
    //printf("%lld\n", fn(3));
    trace(n, 0, 0);
    printf("\n");

    return 0;
}

void trace(int left, ll with_me, int nw)
{
    if(left == 0)
        return ;

    int d = 0;
    for(int i = 1; i <= left; i++)
    {
        if(with_me + fn(left - i) > k)
            break;
        else
            with_me += fn(left - i), d = i;
    }
    d++;
    //printf("state %d %lld %d ffdd %d\n", left, with_me, nw,d);
    bool g=0;
    if(left==n)
        g=1;

    for(int i = nw + d - 1; i >= nw; i--)
    {

        if(i != 0)
            printf(" ");
        printf("%d", i + 1);
    }

    trace(left - d, with_me, nw + d);
}

ll fn(int left)
{
    ll& ret = dp[left];
    if(ret != -1)
        return ret;

    ret = 0;

    if(left == 0)
    {
        ret = 1;
        return ret;
    }

    for(int i = 1; i <= left; i++)
        ret += fn(left - i);

    return ret;
}
