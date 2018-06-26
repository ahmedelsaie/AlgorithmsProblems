#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 300009

void build(int i, int taken);
void fn();
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

ll array[MAX], input[MAX], tab[MAX], accum[50], inf = 99999999999999;
int c, t, n;

int main()
{
    while(true)
    {
        scanf("%d %d", &n, &t);

        if(n + t == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%lld", &input[i]);

        for(int i = 0; i < t; i++)
            scanf("%lld", &tab[i]);

        fn();
    }

    return 0;
}

void fn()
{
    ll big, small, tmp_big, tmp_small;
    c = 0;
    build(0, 0);

    for(int i = 0; i < t; i++)
    {
        small = 0, big = inf;
        for(int j = 0; j < c; j++)
        {
            tmp_small = (tab[i] / array[j]) * array[j];
            if(tmp_small <= tab[i])
                small = max(small, tmp_small);

            tmp_big = (tab[i] / array[j] + 1) * array[j];
            if(tmp_big >= tab[i])
                big = min(big, tmp_big);

            tmp_big = (tab[i] / array[j]) * array[j];
            if(tmp_big >= tab[i])
                big = min(big, tmp_big);

        }

        printf("%lld %lld\n", small, big);
    }
}

void build(int i, int taken)
{
    if(taken == 4)
    {
        ll ans = accum[0];
        for(int j = 1; j < 4; j++)
            ans = lcm(ans, accum[j]);

        array[c] = ans, c++;
        return;
    }

    if(i == n)
        return;

    accum[taken] = input[i];
    build(i + 1, taken + 1);

    build(i + 1, taken);

    return;
}

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b)
{
    return (a * (b / gcd(a, b)));
}

