#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int fn();

int n, k, indx[55], cases;
bool graph[55][55];
int get_lowest(int x);

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &n, &k);
        printf("%d\n", fn());
        int k = 1;

        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                if(graph[i][j])
                    printf("%d %d\n", i, j);
        printf("\n");
    }
    return 0;
}

int fn()
{
    int ret = 0, j, t;
    k++;
    memset(graph, 0, sizeof(graph));
    memset(indx, 0, sizeof(indx));

    for(int i = 1; i <= n; i++)
    {
        t = indx[i];
        while(t < k)
        {
            int tmp = get_lowest(i);
            graph[i][tmp] = graph[tmp][i] = 1, indx[i]++, t++, ret++, indx[tmp]++;
        }
    }

    if(n % 2 != 0 && k % 2 != 0)
    {
        for(int i = 1; i < n; i++)
            if(graph[n][i] == false)
            {
                graph[n][i] = graph[i][n] = 1;
                break;
            }
    }

    return ret;
}

int get_lowest(int x)
{
    int ret = 0, val = 99999;
    for(int i = 1; i <= n; i++)
        if(i != x && graph[x][i] == 0 && indx[i] < k)
        {
            if(indx[i] < val)
                ret = i, val = indx[i];
        }

    if(ret == -1)
    {
        for(int i = 1; i <= n; i++)
            if(i != x && graph[x][i] == 0 )
            {
                if(indx[i] < val)
                    ret = i, val = indx[i];
            }
    }

    return ret;
}
