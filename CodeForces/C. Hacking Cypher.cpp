#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 1000009
#define ll long long

void fn();
int n;
char array[MAX];
ll a, b;

int main()
{
    scanf("%s", array);
    scanf("%lld %lld", &a, &b);
    n = strlen(array);
    fn();

    return 0;
}

void fn()
{
    bool check1[MAX], check2[MAX];
    memset(check1, 0, sizeof(check1)), memset(check2, 0, sizeof(check2));

    ll accum = 0, p = 1, tmp, h = 10 % b;

    for(int i = n - 1; i >= 0; i--)
    {
        if(i != n - 1)
            p = (h * p) % b;
        tmp = (((ll)array[i] - '0') % b * p) % b;
        accum = (tmp + accum) % b;
        if(accum == 0)
            check1[i] = 1;
    }

    h = 10 % a, accum = 0;
    for(int i = 0; i < n; i++)
    {
        tmp = (accum * h) % a;
        tmp = tmp + (((ll)array[i] - '0') % a);
        tmp = tmp % a;
        accum = tmp;

        if(accum == 0)
            check2[i] = 1;
    }

    for(int i = 0; i < n - 1; i++)
    {
        if(check2[i] && check1[i + 1] && (array[0] != '0') && array[i + 1] != '0')
        {
            printf("YES\n");
            for(int k = 0; k <= i; k++)
                printf("%c", array[k]);
            printf("\n");
            for(int k = i + 1; k < n; k++)
                printf("%c", array[k]);
            printf("\n");
            return;
        }
    }

    printf("NO\n");
}
