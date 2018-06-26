#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define MAX 50009

int fn(int n);

int ans[1005];

int main()
{
    int n, cases;

    scanf("%d", &cases);

    while(cases--)
    {

        scanf("%d", &n);

        fn(n);
        printf("\n");
        if(cases)
            printf("\n");
    }

    return 0;
}

int fn(int n)
{
    if(n == 4)
    {
        printf("2 2");
        return 1;
    }
    int last = 2, accum = 0, j = 0;

    while(accum < n)
    {
        accum += last;
        ans[j++] = last;
        last++;
    }

    int x = accum - n;

    int p = 0;
    int s = 0;

    if(x == 1)
    {
        if(ans[j - 1] == x)
            ans[j - 2]++;
        else
            ans[j - 1]++;
        s = 1;
    }

    int sum = 0;
    for(int i = s; i < j; i++)
    {
        if(ans[i] != x)
        {
            if(p++)
                printf(" ");
            printf("%d", ans[i]), sum += ans[i];
        }
    }
    return 1;

}
