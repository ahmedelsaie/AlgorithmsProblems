#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 30009
void fn();
int n;

int main()
{
    scanf("%d", &n);
    if(n < 4)
        printf("NO\n");
    else
        fn();
    return 0;
}

void fn()
{
    printf("YES\n");

    if(n == 4)
    {
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
        printf("24 * 1 = 24\n");
    }
    else if(n == 5)
    {
        printf("4 * 5 = 20\n");
        printf("2 - 1 = 1\n");
        printf("3 + 1 = 4\n");
        printf("4 + 20 = 24\n");
    }
    else
    {
        printf("5 - 6 = -1\n");
        printf("-1 + 1 = 0\n");
        printf("2 * 3 = 6\n");
        printf("4 * 6 = 24\n");
        int j = 4;
        for(int i = 7; i <= n; i++)
            printf("%d * 0 = 0\n", i), j++;

        for(j; j < n - 1; j++)
            printf("24 + 0 = 24\n");
    }
}
