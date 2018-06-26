#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 100009

int bin_search(int x);

int array[MAX], n, x, y, l;

int main()
{
    scanf("%d %d %d %d", &n, &l, &x, &y);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    array[n] = l, n++;

    int f1 = 0, f2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(bin_search(array[i] + x) != -1 || bin_search(array[i] - x) != -1)
            f1 = 1;

        if(bin_search(array[i] + y) != -1 || bin_search(array[i] - y) != -1)
            f2 = 1;
    }

    if(f1 && f2)
        printf("0\n");
    else if(f1 || f2)
    {
        printf("1\n");
        if(f2)
            printf("%d\n", x);
        else
            printf("%d\n", y);
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(x + array[i] <= l)
            {
                int p = x + array[i];
                int tmp = bin_search(p + y);
                int tmp2 = bin_search(p - y);
                if(tmp != -1 || tmp2 != -1)
                {
                    printf("1\n%d\n", p);
                    return 0;
                }
            }

            if(array[i] - x > 0)
            {
                int p = array[i] - x;
                int tmp = bin_search(p + y);
                int tmp2 = bin_search(p - y);
                if(tmp != -1 || tmp2 != -1)
                {
                    printf("1\n%d\n", p);
                    return 0;
                }
            }
        }

        printf("2\n%d %d\n", x, y);
    }

    return 0;
}

int bin_search(int x)
{
    if(x < 0 || x > l)
        return -1;

    int small = 0, big = n - 1, mid;

    while(big >= small)
    {
        mid = (big + small) / 2;
        if(array[mid] == x)
            return mid;

        if(array[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return -1;
}
