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
#define MAX 3000

void fn(ll players, ll max_size);

ll players, max_size;

int main()
{
    while(scanf("%lld %lld", &players, &max_size) != EOF)
        fn(players, max_size);

    return 0;
}

void fn(ll players, ll max_size)
{
    if(max_size >= players || players == 1)
    {
        cout << players << " persons/group, 1 day" << endl;
        return;
    }
    // players--, max_size--;
    int small = 2, big = max_size, mid, ret = -1, n_grp;

    for(ll i = small; i <= big; i++)
    {
        if(players % i == 0 && (players - 1) % (i - 1) == 0)
        {
            //    printf("%d\n", i);
            n_grp = players / i;
            // printf("%d %d %d %d\n", small, big, mid, n_grp);
            //if(mid == 1)
            //    break;

            if(n_grp >= i)
                ret = i;

        }
    }

    ll days;

    if(ret != -1)
        days = (players - 1) / (ret - 1);
    if(ret == -1)
        printf("No solution");
    else
        printf("%lld persons/group, %lld day%s", ret, days, days > 1 ? "s" : "");

    printf("\n");
}
