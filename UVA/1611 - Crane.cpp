#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 2000009

void swap(int start, int end);
void fn(int x);

int arr[MAX], tmp[MAX], n, c, place[MAX], ans[MAX], ans2[MAX], cases;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]), place[arr[i]] = i;

        c = 0;
        for(int i = 1; i <= n; i++)
            fn(i);

        printf("%d\n", c);
        for(int i = 0; i < c; i++)
            printf("%d %d\n", ans[i] + 1, ans2[i]);
    }

    return 0;
}

void fn(int x)
{
    int small = x - 1, big = place[x] + 1;

    while(place[x] != x - 1)
    {
        small = x - 1, big = place[x] + 1;
        if((big - small) % 2 == 0)
        {
            swap(small, big);
            ans[c] = small, ans2[c++] = big;
        }
        else
        {
            swap(small + 1 , big);
            ans[c] = small + 1, ans2[c++] = big;
        }
    }


    return ;
}

void swap(int start, int end)
{
    int mid = (start + end) / 2;
    int j = 0;
    for(int i = mid; i < end; i++)
        tmp[j++] = arr[i];

    j = start;
    for(int i = mid; i < end; i++)
        arr[i] = arr[j], place[arr[i]] = i, j++;

    j = 0;
    for(int i = start; i < mid; i++)
        arr[i] = tmp[j], place[arr[i]] = i, j++;

}
