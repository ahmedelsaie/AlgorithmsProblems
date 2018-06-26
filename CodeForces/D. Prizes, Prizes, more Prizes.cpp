#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll unsigned long long
#define MAX 55

int choose(ll left);
ll fn();

ll costs[5], got[5], array[MAX];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    for(int i = 0; i < 5; i++)
        scanf("%llu", &costs[i]);

    ll left = fn();

    for(int i = 0; i < 5; i++)
    {
        if(i)
            printf(" ");
        printf("%llu", got[i]);
    }

    printf("\n%llu\n", left);

    return 0;
}

ll fn()
{
    memset(got, 0, sizeof(got));

    int tmp;
    ll left = 0, r;

    for(int i = 0; i < n; i++)
    {
        left += array[i];
        while(true)
        {
            tmp = choose(left);
            if(tmp == -1)
                break;

            r = left / costs[tmp];
            left -= (r * costs[tmp]);
            got[tmp] += r;
        }
    }

    while(true)
    {
        tmp = choose(left);
        if(tmp == -1)
            break;

        r = left / costs[tmp];
        left -= (r * costs[tmp]);
        got[tmp] += r;
    }
    return left;
}

int choose(ll left)
{
    int ret = -1;
    ll val = 0;
    for(int i = 0; i < 5; i++)
    {
        if(costs[i] <= left && costs[i] > val)
            ret = i, val = costs[i];
    }

    return ret;
}
