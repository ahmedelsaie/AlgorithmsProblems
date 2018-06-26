#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 10005

void fn();

int n;
int main()
{
    while(scanf("%d", &n) != EOF)
        fn();
    return 0;
}

void fn()
{
    printf("%d %d %d\n", n, n, 2);

    for(int i = 0; i < n; i++)
    {
        ///the main
        for(int j = 0; j < n; j++)
            printf("%c", j <= 25 ? 'a' + j : 'A' + (j - 26));

        printf("\n");
        for(int j = 0; j < n; j++)
            printf("%c", i <= 25 ? 'a' + i : 'A' + (i - 26));

        printf("\n\n");
    }
}
