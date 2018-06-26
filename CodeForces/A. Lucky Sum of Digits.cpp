#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long

void fn();
int x;

int main()
{
    scanf("%d", &x);
    fn();
    printf("\n");

    return 0;
}

void fn()
{
    int tmp;
    for(int i = x; i >= 0; i--)
    {
        if(7 * i <= x && (x - (7 * i)) % 4 == 0)
        {
            tmp = x - (7 * i);
            tmp = tmp / 4;
            for(int j = 0; j < tmp; j++)
                printf("4");

            for(int j = 0; j < i; j++)
                printf("7");

            return;
        }
    }

    printf("-1");
}


