#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 200009;
void fn();

int n;
long long f[200009], sum, a;

int main()
{
    scanf("%d %lld", &n, &a);
    sum = 0;
    for(int i = 1; i <= n; i++)
        scanf("%lld", &f[i]), sum += f[i];

    fn();
    return 0;
}

void fn()
{
    ll tmp, s, sum1, need;

    for(int i = 1; i <= n; i++)
    {
        tmp = 0;
        sum1 = sum - f[i];

        if(sum1 < a)
            tmp = a - sum1 - 1;

        need = a - (n - 1);
        if(f[i] - need > 0)
            tmp += f[i] - need;
        if(i > 1)
            printf(" ");
        printf("%lld", tmp);
    }
}
