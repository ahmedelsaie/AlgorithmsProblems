#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

void fn();

int n;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        fn();
        printf("\n");
    }

    return 0;
}

void fn()
{
    if(n % 2)
    {
        for(int i = n - 1; i >= 2; i -= 2)
            printf("%d %d ", i, i + 1);
        printf("1");
    }
    else
    {
        printf("%d %d %d ", n - 1, 1, n);
        for(int i = n - 3; i >= 3; i -= 2)
            printf("%d %d ", i, i + 1);
        printf("2");
    }
}
