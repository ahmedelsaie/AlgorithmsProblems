#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll  long long
#define MAX 100009

ll fn(ll accum, int h, char dir);

ll height, exit1;
ll sum[100];

int main()
{
    sum[0] = 1;
    for(int i = 1; i < 50; i++)
        sum[i] = sum[i - 1] + (1LL << i);

    scanf("%lld %lld", &height, &exit1);

    printf("%lld\n", fn(0, height, 'r'));

    return 0;
}

ll fn(ll accum, int h, char came)
{
    if(accum == exit1 || h <= 0)
        return 0;

    if(came == 'r')///go left
    {
        if(accum + (1LL << h - 1) < exit1)
            return 1 + sum[h - 1] + fn(accum + (1LL << h - 1), h - 1, 'r');
        else
            return 1 + fn(accum, h - 1, 'l');
    }
    else ///go right
    {
        if(accum + (1LL << h - 1) < exit1)
            return 1 + fn(accum + (1LL << h - 1), h - 1, 'r');
        else
            return  1 + sum[h - 1] + fn(accum, h - 1, 'l');
    }

}
