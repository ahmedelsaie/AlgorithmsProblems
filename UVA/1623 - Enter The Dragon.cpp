#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define ll long long
#define MAX 1000009

int fn();

set<int> y;
int arr[MAX], drink[MAX], prev1[MAX], n, m, cases, f;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        f = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
            scanf("%d", &arr[i]);
        if(fn())
        {
            printf("YES\n");
            for(int i = 1; i <= m; i++)
            {
                if(arr[i] == 0)
                {
                    if(f)
                        printf(" ");
                    else
                        f = 1;
                    printf("%d", drink[i]);
                }
            }
            printf("\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}

int fn()
{
    y.clear();
    memset(prev1, 0, sizeof(prev1));
    memset(drink, 0, sizeof(drink));
    set<int>::iterator p;

    for(int i = 1; i <= m; i++)
    {
        if(arr[i] == 0)
            y.insert(i);
        else
        {
            int lake = arr[i];
            int tmp = prev1[lake];
            p = y.upper_bound(tmp);
            if(p == y.end())
                return 0;
            int r = *(p);

            y.erase(p);
            prev1[lake] = i;

            drink[r] = lake;
        }

    }

    return 1;

}


