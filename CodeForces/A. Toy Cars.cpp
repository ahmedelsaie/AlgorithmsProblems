#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int n, array[105][105], ans, accum[105];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &array[i][j]);

    ans = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp = 0;
        for(int j = 0; j < n; j++)
            if(array[i][j] == 3 || array[i][j] == 1)
                tmp++;

        if(tmp == 0)
            accum[ans] = i, ans++;
    }

    printf("%d\n", ans);

    for(int i = 0; i < ans; i++)
    {
        if(i)
            printf(" ");
        printf("%d", accum[i] + 1);
    }

    if(ans)
        printf("\n");
    return 0;
}
