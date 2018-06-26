#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll unsigned long long

ll fn(ll r, ll c);

ll pre[1000006];

int main()
{
    pre[0] = 0;
    for(ll i = 1; i <= 1000005; i++)
        pre[i] = pre[i - 1] + i * (i - 1);

    ll x, y;

    while(true)
    {
        scanf("%llu %llu", &x, &y);
        if(x + y == 0)
            break;
        printf("%llu\n", fn(max(x, y), min(x, y)));
    }
    return 0;
}

ll fn(ll r, ll c)
{
    ll ret = 0;

    ret += 2 * pre[c - 1];

    ret += (r - c + 1) * c * (c - 1);
    ret = 2 * ret;

    ret += r * (c * (c - 1));
    ret += c * (r * (r - 1));

    return ret;
}
