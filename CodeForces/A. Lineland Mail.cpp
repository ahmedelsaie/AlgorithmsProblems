#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 100009

int array[MAX];

int small[MAX], big[MAX], n;
const int inf = (1 << 31) - 1;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    for(int i = 0; i < n; i++)
    {
        small[i] = inf;
        big[i] = max(abs(array[i] - array[0]), abs(array[i] - array[n - 1]));

        if(i > 0)
            small[i] = min(small[i], abs(array[i] - array[i - 1]));

        if(i < n - 1)
            small[i] = min(small[i], abs(array[i] - array[i + 1]));
    }

    if(n == 1)
        printf("0 0\n");
    else
    {
        for(int i = 0; i < n; i++)
            printf("%d %d\n", small[i] == inf ? 0 : small[i], big[i]);
    }

    return 0;
}


