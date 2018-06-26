#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long
#define MAX 1000006

int fn();

int arr[MAX], n, l, tc;

int main()
{
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d", &n, &l);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        sort(arr, arr + n);

        printf("%d\n", fn());
        if(tc)
            printf("\n");
    }

    return 0;
}

int fn()
{
    int ret = 0;

    int start = 0, end = n - 1;

    while(start <= end)
    {
        if(arr[start] + arr[end] <= l)
            start++, end--;
        else
            end--;
        ret++;
    }

    return ret;
}
