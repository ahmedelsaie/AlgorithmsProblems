#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long

ll fn();
int array[35], m, n, x, cases;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        memset(array, 0, sizeof(array));
        scanf("%d %d", &m, &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &x), array[j] += (x == 1);
        printf("%lld\n", fn());
    }
    return 0;
}

ll fn()
{
    ll ret = 1;

    for(int i = 0; i < m; i++)
        if(array[i])
            ret *= array[i];

    return ret;
}
