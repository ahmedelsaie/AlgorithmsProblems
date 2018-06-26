#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 5009
#define MAX2 450

struct node
{
    char arra[MAX2];
};

bool comp(node x, node y);

node array[MAX];
int n;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%s", array[i].arra);

        sort(array, array + n, comp);

        for(int i = 0; i < n; i++)
            printf("%s", array[i].arra);
        printf("\n");
    }

    return 0;
}

bool comp(node x, node y)
{
    char xy[MAX2], yx[MAX2];
    int j = 0;
    for(int i = 0; i < strlen(x.arra); i++)
        xy[j++] = x.arra[i];

    for(int i = 0; i < strlen(y.arra); i++)
        xy[j++] = y.arra[i];

    xy[j] = '\0';

    j = 0;
    for(int i = 0; i < strlen(y.arra); i++)
        yx[j++] = y.arra[i];

    for(int i = 0; i < strlen(x.arra); i++)
        yx[j++] = x.arra[i];

    yx[j] = '\0';

    if(strcmp(xy, yx) < 0)
        return 0;
    return 1;
}

