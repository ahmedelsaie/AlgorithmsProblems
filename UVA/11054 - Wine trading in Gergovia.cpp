#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 100009

ll fn();

ll array[MAX];
int n;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%lld", &array[i]);

        printf("%lld\n", fn());
    }

    return 0;
}

ll fn()
{
    ll ret = 0;
    ll with = 0;

    for(int i = 0; i < n; i++)
    {
        ret += abs(with);
        with += array[i];
    }

    return ret;
}
