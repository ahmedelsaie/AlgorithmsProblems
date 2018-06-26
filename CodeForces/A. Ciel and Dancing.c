#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    int counter;

    scanf("%d %d", &n, &m);
    printf("%d\n", (n + m - 1));

    for(counter = 1; counter <= m; counter++)
    {
        printf("1 %d\n", counter);
    }

    for(counter = 2; counter <= n; counter++)
    {
        printf("%d 1 \n", counter);
    }

    return 0;
}
