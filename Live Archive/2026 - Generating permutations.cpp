#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gen(int i);

int n;
int array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int accum[12];
bool check[12];

int main()
{
    for(int j = 0; j < 12; j++)
        check[j] = true;
    int run = 1;

    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        if(run > 1)
            printf("\n");

        printf("Run %d n=%d\n", run, n);
        gen(0);
        run++;
    }

    return 0;
}

void gen(int i)
{
    if(i == n)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d", accum[i]);
            if(i < n - 1)
                printf(" ");
        }
        printf("\n");
        return;
    }

    for(int j = 0; j < n; j++)
    {
        if(check[j] == true)
        {
            accum[i] = array[j];
            check[j] = false;
            gen(i + 1);
            check[j] = true;
        }
    }
    return;
}
