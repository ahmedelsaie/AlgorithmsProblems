#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int n;
void fn();

int main()
{
    scanf("%d", &n);
    fn();
    return 0;
}

void fn()
{
    if(n == 1)
    {
        printf("1\n1") ;
        return;
    }

    if(n == 2)
    {
        printf("1\n1");
        return;
    }

    if(n == 3)
    {
        printf("2\n1 3");
        return;
    }


    printf("%d\n", n);

    int start = 1, end = n;
    if(n % 2 != 0)
        printf("%d", n / 2 + 1);
    else
        printf("%d", n / 2 + 1);

    while(start <= end)
    {
        if(start == end)
            break;
        if(end == start + 1)
        {
            printf(" %d", start);
            break;
        }
        printf(" %d %d", start, end);
        start++, end--;
    }
}
