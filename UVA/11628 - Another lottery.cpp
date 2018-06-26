#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int gcd(int a, int b);
void fn();

int array[10005][35], cases = 0, n, m,tickets[35];

int main()
{

    while(true)
    {
        scanf("%d %d", &n, &m);
        if(n + m == 0)
            break;

        memset(tickets, 0, sizeof(tickets));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &array[i][j]), tickets[j] += array[i][j];
        fn();
    }

    return 0;
}

void fn()
{
    int g;
    for(int i = m; i >= 1; i--)
    {
        if(tickets[i])
        {
            for(int j = 1; j <= n; j++)
                g = gcd(tickets[i], array[j][i]), printf("%d / %d\n", array[j][i] / g, tickets[i] / g);
            return ;
        }
    }

}

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
