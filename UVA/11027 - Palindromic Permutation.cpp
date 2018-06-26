#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long

void fn(int j, ll accum);
ll calc(int j);

ll fac[20], desired;
int letters[30], ans[30], n, flag, ok, p = 1, odd = 0;
char input[100];

int main()
{
    int cases;
    fac[0] = fac[1] = 1;
    fac[2] = 2;
    for(int i = 3; i <= 15; i++)
        fac[i] = i * fac[i - 1];

    scanf("%d", &cases);
    while(cases--)
    {
        ok = odd = 0;
        scanf("%s %lld", input, &desired);
        memset(letters, 0, sizeof(letters));
        n = strlen(input) / 2;
        //desired--;
        for(int i = 0; i < strlen(input); i++)
            letters[input[i] - 'a']++;
        flag = -1;
        for(int i = 0; i < 30; i++)
        {
            if(letters[i] % 2)
                flag = i, letters[i]--, odd++;
            letters[i] /= 2;
        }

        printf("Case %d: ", p++);
        //printf("%d\n",calc(-1));
        if(desired <= calc(-1) && odd < 2)
            fn(0, 0);
        if(!ok)
            printf("XXX");
        printf("\n");
    }

    return 0;
}

void fn(int j, ll accum)
{
    if(j == n)
    {
        ok = 1;
        for(int i = 0; i < j; i++)
            printf("%c", ans[i] + 'a');

        if(flag != -1)
            printf("%c", flag + 'a');

        for(int i = j - 1; i >= 0; i--)
            printf("%c", ans[i] + 'a');
        return;
    }

    ll x;
    for(int i = 0; i < 30; i++)
        if(letters[i])
        {
            letters[i]--;
            x = calc(j);
            ans[j] = i;
            if(x + accum >= desired)
                return fn(j + 1, accum);
            else
                accum += x, letters[i]++;
        }
}

ll calc(int j)
{
    ll ret;
    j = n - j - 1;
    ret = fac[j];
    for(int i = 0; i < 30; i++)
        if(letters[i])
            ret = ret / fac[letters[i]];
    return ret;
}
