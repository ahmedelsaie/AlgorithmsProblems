#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 3003

int array[MAX], indx[MAX], ans, n, x;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 1; i <= n; i++)
            scanf("%d", &array[i]);

        for(int i = 1; i <= n; i++)
            scanf("%d", &x), indx[x] = i;

        ans = 0;

        for(int i = 1; i <= n; i++)
        {
            int small = indx[array[i]], big = indx[array[i]];
            for(int j = i; j <= n; j++)
            {
                small = min(small, indx[array[j]]);
                big = max(big, indx[array[j]]);
                if(big - small == j - i && j - i > 0)
                    ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
