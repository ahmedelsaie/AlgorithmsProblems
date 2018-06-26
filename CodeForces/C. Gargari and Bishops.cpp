#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 2005
#define ll long long

ll fn();
void pre_process();

ll array[MAX][MAX], accum1[MAX][MAX], accum2[MAX][MAX];
int n, x1, x2, z1, z2;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%lld", &array[i][j]);

    pre_process();
    printf("%lld\n", fn());
    printf("%d %d %d %d\n", x1, z1, x2, z2);

    return 0;
}

void pre_process()
{
    ///part1 down diagonal
    for(int j = 1; j <= n; j++)
    {
        int x = 1, y = j;
        ll accum = 0;
        while(x <= n && y <= n)
        {
            accum += array[x][y];
            x++, y++;
        }

        x = 1, y = j;
        while(x <= n && y <= n)
        {
            accum1[x][y] = accum;
            x++, y++;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        int x = i, y = 1;
        ll accum = 0;
        while(x <= n && y <= n)
        {
            accum += array[x][y];
            x++, y++;
        }

        x = i, y = 1;
        while(x <= n && y <= n)
        {
            accum1[x][y] = accum;
            x++, y++;
        }
    }

    ///part2 up diagonal
    for(int j = 1; j <= n; j++)
    {
        int x = 1, y = j;
        ll accum = 0;
        while(x <= n && y >= 1)
        {
            accum += array[x][y];
            x++, y--;
        }

        x = 1, y = j;
        while(x <= n && y >= 1)
        {
            accum2[x][y] = accum;
            x++, y--;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        int x = i, y = n;
        ll accum = 0;
        while(x <= n && y >= 1)
        {
            accum += array[x][y];
            x++, y--;
        }

        x = i, y = n;
        while(x <= n && y >= 1)
        {
            accum2[x][y] = accum;
            x++, y--;
        }
    }
}

ll fn()
{
    bool c = 1;
    ll m1 = 0, m2 = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = c; j <= n; j += 2)
            if(accum1[i][j] + accum2[i][j] - array[i][j] >= m1)
                m1 = accum1[i][j] + accum2[i][j] - array[i][j], x1 = i, z1 = j;
        c = !c;
    }

    c = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = c; j <= n; j += 2)
            if(accum1[i][j] + accum2[i][j] - array[i][j] >= m2)
                m2 = accum1[i][j] + accum2[i][j] - array[i][j], x2 = i, z2 = j;
        c = !c;
    }

    return m1 + m2;
}
