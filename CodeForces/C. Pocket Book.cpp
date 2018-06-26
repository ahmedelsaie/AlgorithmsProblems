#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MOD 1000000007

ll fn();

int m, n;
char array[105][105];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", array[i]);

    printf("%lld\n", fn());

    return 0;
}

ll fn()
{
    ll ret = 1;
    int check[30], tmp;
    memset(check, -1, sizeof(check));

    for(int i = 0; i < m; i++)
    {
        tmp = 0;
        for(int j = 0; j < n; j++)
            if(check[array[j][i] - 'A'] != i)
                check[array[j][i] - 'A'] = i, tmp++;

        ret = (ret * (tmp % MOD)) % MOD;
    }

    return ret;
}
