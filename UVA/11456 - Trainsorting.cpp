#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 2005

int fn();

int dp1[MAX], dp2[MAX], array[MAX], n, cases;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        printf("%d\n", fn());
    }

    return 0;
}

int fn()
{
    int ret = 0;
    ///lis
    for(int i = n - 1; i >= 0; i--)
    {
        dp1[i] = 1;
        for(int j = i + 1; j < n; j++)
            if(array[j] > array[i])
                dp1[i] = max(dp1[i], dp1[j] + 1);
    }

    ///lds
    for(int i = n - 1; i >= 0; i--)
    {
        dp2[i] = 1;
        for(int j = i + 1; j < n; j++)
            if(array[j] < array[i])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        ret = max(ret, dp1[i] + dp2[i] - 1);
    }

    return ret;
}
