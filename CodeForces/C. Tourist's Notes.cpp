#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 1000009

ll fn();
ll get(ll start, ll end, ll level);

int n, max_days;
ll h[MAX], d[MAX];

int main()
{
    scanf("%d %d", &max_days, &n);
    for(int i = 0; i < n; i++)
        scanf("%lld %lld", &d[i], &h[i]);

    ll ans = fn();

    if(ans == -1)
        printf("IMPOSSIBLE");
    else
        printf("%lld", ans);

    printf("\n");

    return 0;
}

ll fn()
{
    if(n == 1 && d[0] == 1)
        return h[0] + max_days - 1;
    ll ret = -1;
    if(d[0] != 1)
        ret = h[0] + d[0] - 1;

    int i = 1;

    while(i < n)
    {
        if(h[i] == h[i - 1])
            ret = max(ret, get(d[i - 1], d[i], h[i]));
        else
        {
            if(d[i] - d[i - 1] < abs(h[i - 1] - h[i]) )
                return -1;
            else
                ret = max(ret, get(d[i - 1] + abs(h[i - 1] - h[i]), d[i], max(h[i], h[i - 1]) ) );
        }
        i++;
    }

    if(d[n - 1] != max_days)
        ret = max(ret, h[n - 1] + (max_days - d[n - 1]));

    return ret;
}

ll get(ll start, ll end, ll level)
{
    return ((end - start) / 2) + level;
}
