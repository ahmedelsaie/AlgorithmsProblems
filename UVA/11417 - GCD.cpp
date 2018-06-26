#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 500

int gcd(int a, int b);

int ans[MAX + 5], x;

int main()
{
    for(int i = 1; i <= MAX; i++)
    {
        for(int j = 1; j < i; j++)
            ans[i] += gcd(i, j);
        ans[i] += ans[i - 1];
    }

    while(true)
    {
        scanf("%d", &x);
        if(x == 0)
            break;
        printf("%d\n", ans[x]);
    }

    return 0;
}

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
