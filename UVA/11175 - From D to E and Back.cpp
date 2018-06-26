#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long
#define MAX 309

int name(int flag, int val, int node);
void build_orig();
int fn();
void build_last();
int get_indx(int x, int y);

int n, m, v[MAX][2], x, y, graph[MAX][MAX], graph2[MAX][MAX], graph3[MAX][MAX];;
pair<int, int>arr[MAX];
int cnt = 0;
int tmp = 0, cases = 1, tc;

int main()
{
    scanf("%d", &tc);

    while(tc--)
    {
        memset(v, 0, sizeof(v));
        memset(graph, 0, sizeof(graph));
        memset(graph2, 0, sizeof(graph2));
        memset(graph3, 0, sizeof(graph3));

        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            //if(x != y)
            graph[x][y] = 1;
        }

        printf("Case #%d: ", cases++);
        printf("%s\n", fn() == 1 ? "Yes" : "No");
    }

    return 0;
}

int fn()
{
    cnt = tmp = 0;
    ///naming the give graph
    for(int i = 0; i <= n; i++)
        arr[i].first = arr[i].second = -1;

    int i = 0;
    while(i < n)
    {
        if(arr[i].first == -1)
            arr[i].first = cnt, name(1, cnt, i), cnt++;

        if(arr[i].second == -1)
            arr[i].second = cnt, name(0, cnt, i), cnt++;

        i++;
    }

    ///get_max node
    for(int i = 0; i < n; i++)
        tmp = max(tmp, arr[i].first), tmp = max(tmp, arr[i].second);
    tmp++;

    build_orig();
    build_last();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(!graph[i][j] && graph3[i][j])
                return 0;
        }

    return 1;
}

void build_last()
{
    for(int i = 0; i < tmp; i++)
        for(int j = 0; j < tmp; j++)
            for(int k = 0; k < tmp; k++)
            {
                //   if(i != j && j != k && i != k)
                {
                    if(graph2[i][j] && graph2[j][k])
                    {
                        int tmp1 = get_indx(i, j);
                        int tmp2 = get_indx(j, k);
                        graph3[tmp1][tmp2] = 1;
                    }


                }
            }
}

int get_indx(int x, int y)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i].first == x && arr[i].second == y)
            return i;
    }
}

void build_orig()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(graph[i][j])
            {
                int x = arr[i].first;
                int y = arr[i].second;

                graph2[x][y] = 1;

                x = arr[i].second;
                y = arr[j].second;

                graph2[x][y] = 1;
            }
        }
}

int name(int flag, int val, int node)
{
    if(v[node][flag] == 1)
        return 0;

    v[node][flag] = 1;

    if(flag == 0)
    {
        arr[node].second = val;
        for(int i = 0; i < n; i++)
            if(graph[node][i])
                name(!flag, val, i);
    }
    else
    {
        arr[node].first = val;
        for(int i = 0; i < n; i++)
            if(graph[i][node])
                name(!flag, val, i);
    }
}
