#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
long long fn(int x);

int main()
{
    int cases, x;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &x);
        printf("%lld\n", fn(x));
    }
    return 0;
}

long long fn(int x)
{
    long long ret = 0;

    if(x % 2 == 0)
    {
        ret += (x / 2) * (x / 2 - 1) / 2;
        ret = 2 * ret;
    }
    else
    {
        ret += (x / 2) * (x / 2 - 1) / 2;
        ret += (x / 2 + 1) * (x / 2) / 2;
    }

    return ret;
}

