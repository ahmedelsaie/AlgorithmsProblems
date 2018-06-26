#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define MAX 50009

ll n;
int tc, cases = 1;
ll fn(ll n);

int main()
{
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%lld", &n);

        //if(n > 0)
        //       n = (ll)floor(log((double)n) / log(2.0));
        //else
        //   n = -1;
        printf("Case %d: %lld", cases++, fn(n));
        printf("\n");

    }
    return 0;
}

ll fn(ll n)
{
    if(n == 0)
        return 0;

    ll accum = 1;
    ll ret = 1;
    while(true)
    {
        if((ll)2 * accum <= n)
            ret++, accum = accum * 2;
        else
            break;
    }

    return ret;
}
