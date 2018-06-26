#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAX 20009

pair<int, int> array[MAX];
int v[MAX], n;
int v2[MAX];

int main()
{
    for(int i=0;i<MAX;i++)
        v[i]=0,v2[i];
    scanf("%d", &n);
    for(int i = 0; i < n * n; i++)
        scanf("%d %d", &array[i].first, &array[i].second);

    int t= 0;
    for(int i = 0; i < n * n; i++)
    {
        int f = array[i].first, s = array[i].second;
        if(v[f] == 0 && v2[s] == 0)
        {
            v[f] = v2[s] = 1;
            if(t > 0)
                printf(" ");
            else
            t++;

            printf("%d", i + 1);
        }

    }
    printf("\n");

    return 0;
}
