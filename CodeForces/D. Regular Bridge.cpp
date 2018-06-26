#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 1005

int get_min(int x, int j);
int build(int x, int v);

int graph[MAX][MAX], deg[MAX], k;
int edges = 0, cases = 0;

int main()
{
    memset(graph, -1, sizeof(graph));
    scanf("%d", &k);
    if(k == 1)
    {
        printf("YES\n2 1\n1 2\n");
        return 0;
    }

    if(k % 2)
        for(int i = k; i <= 3 * k; i++)
        {
            cases++;
            int ans = build(k, i);

            if(ans)
            {
                printf("YES\n");
                printf("%d %d\n", 2 * i, edges * 2 + 1);
                for(int j = 0; j < i; j++)
                {
                    for(int k = j + 1; k < i; k++)
                        if(graph[j][k] == cases)
                            printf("%d %d\n", j + 1, k + 1);

                    if(j == 0)
                        printf("%d %d\n", j + 1, i + 1);
                }


                for(int j = 0; j < i; j++)
                    for(int k = j + 1; k < i; k++)
                        if(graph[j][k] == cases)
                            printf("%d %d\n", j + 1 + i, k + 1 + i);

                return 0;
            }
        }

    printf("NO\n");
    return 0;
}

int build(int x, int v)
{
    memset(deg, 0, sizeof(deg));
    deg[0] = 1;
    edges = 0;
    for(int i = 0; i < v; i++)
    {
        // printf("ffffffff %d %d\n", i, deg[i]);

        while(deg[i] < x)
        {
            int tmp = get_min(v, i);
            //   printf("jbij %d\n",tmp);
            if(tmp == -1 || deg[tmp] >= x)
                return 0;

            graph[i][tmp] = graph[tmp][i] = cases;
            deg[tmp]++, deg[i]++, edges++;
        }

        //  printf("%d\n", deg[i]);
    }
    //printf("%d %d\n", 0, deg[3]);
    return 1;
}

int get_min(int x, int j)
{
    int ret = -1, val = 99999;

    for(int i = 0; i < x; i++)
    {
        if(deg[i] < val && graph[i][j] != cases && i != j)
            val = deg[i], ret = i;
    }

    return ret;
}




