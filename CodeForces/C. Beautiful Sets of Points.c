#include <stdio.h>
#include <stdlib.h>
int first[100];
int sec[100];
int flag = 0;
int main()
{
    int m, n, t, counter;
    scanf("%d%d", &m, &n);
    int     i;
    if(m > n)
    {
        t = m;
        m = n;
        n = t;
    }
    i = m;
    for(counter = 0; counter <= m; counter++)
        first[counter] = counter;

    for(counter = 0; counter <= m; counter++)
    {


        sec[counter] = i;
        i--;

    }


    printf("%d\n", m + 1);
    for(counter = 0; counter <= m; counter++)
    {
        printf("%d %d\n", first[counter], sec[counter]);
    }

    return 0;
}


