#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

void fn();

int n, array[1009], cases = 1;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        printf("Case %d: ", cases++);
        fn();
        printf("\n");
    }

    return 0;
}

void fn()
{
    if(n % 2 == 0)
    {
        if((n / 2) % 2)
            printf("-1");
        else
        {
            int small = 1, big = n + 1, i = 0;
            while(big > small)
            {
                if(i == n / 2)
                    big--;
                array[i] = small, array[i + 1] = big;
                small++, big--, i += 2;
            }
            printf("1 ");
            for(int i = n - 1; i >= 1; i--)
                printf("%d ", array[i]);
        }
    }
    else
    {
        if((n / 2) % 2 == 0)
            printf("-1");
        else
        {
            int small = 1, big = n + 1, i = 0;
            while(big >= small)
            {
                if(big == small)
                {
                    array[i] = big;
                    break;
                }
                if(i == n / 2 + 1)
                    big--;
                array[i] = small, array[i + 1] = big;
                small++, big--, i += 2;
            }

            printf("1 ");
            for(int i = n - 1; i >= 1; i--)
                printf("%d ", array[i]);
        }
    }
}
