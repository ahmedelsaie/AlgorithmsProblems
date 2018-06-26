#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 105

int get_min(int x);
int fn();

int deg[MAX], n, graph[MAX][MAX], ans;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        if(n % 2 || n<=2)
        {
            printf("Impossible\n");
            continue;
        }

        ans = 0;
        fn();

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                ans += graph[i][j];

        printf("%d\n", ans);
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                if(graph[i][j])
                    printf("%d %d\n", i + 1, j + 1);
            }
    }

    return 0;
}

int fn()
{
    memset(deg, 0, sizeof(deg));
    memset(graph, 0, sizeof(graph));

    for(int i = 0; i < n; i++)
    {
        while(deg[i] < 3)
        {
            int tmp = get_min(i);
            deg[tmp]++, deg[i]++;
            graph[tmp][i] = graph[i][tmp] = 1;
        }
    }
}

int get_min(int x)
{
    int ret = -1, val = 10;
    for(int i = 0; i < n; i++)
    {
        if(i != x)
        {
            if(deg[i] < val)
                val = deg[i], ret = i;
        }
    }

    return ret;
}

