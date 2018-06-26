#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAX 250009

int fn();
int check(int x, int taken);
int bin_search(int x);

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
};

int array[MAX], n, v[MAX];
int help[MAX], accum[MAX], with[MAX];
int j = 0;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n * n; i++)
        scanf("%d", &array[i]), help[i] = array[i];

    sort(array, array + (n * n));
    sort(help, help + (n * n));

    int prev = help[0];

    int tmp = 0;
    int i = 0;
    while(i < n * n)
    {
        if(prev != help[i])
        {
            help[j] = prev, prev = help[i];
            accum[j] = tmp;
            tmp = 1;
            j++;
        }
        else
            tmp++;
        i++;
    }
    help[j] = prev;
    accum[j] = tmp;
    j++;

    fn();
   sort(with,with+n);
    for(int i = 0; i < n; i++)
        printf("%d ", with[i]);

    return 0;
}

int fn()
{
    int i = n * n - 1;
    int g = 0;

    while(g < n && i >= 0)
    {
        int tmp = bin_search(array[i]);
        if(accum[tmp]  && check(array[i], g))
            with[g] = array[i], g++;
        else
            accum[tmp]++;
        i--;
    }



}

int check(int x, int taken)
{
    int k=bin_search(x);
    accum[k]--;
    for(int i = 0; i < taken; i++)
    {
        int tmp = gcd(with[i], x);
        tmp = bin_search(tmp);
       // if(k==tmp && accum[tmp] <3)
         //   return 0;
        if(accum[tmp] < 2)
            return 0;
    }

    for(int i = 0; i < taken; i++)
    {
        int tmp = gcd(with[i], x);
        tmp = bin_search(tmp);
        accum[tmp] -= 2;
    }

    return 1;
}

int bin_search(int x)
{
    int small = 0, big = j - 1, mid;
    while(big >= small)
    {
        mid = (small + big) / 2;

        if(help[mid] == x)
            return mid;

        if(help[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return 0;
}
