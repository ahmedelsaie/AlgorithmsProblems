#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 1000

int main()
{
    int cases, x, y;

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &x, &y);
        if(y % x != 0)
            printf("%d", -1);
        else
            printf("%d %d", x, y);
        printf("\n");
    }

    return 0;
}
