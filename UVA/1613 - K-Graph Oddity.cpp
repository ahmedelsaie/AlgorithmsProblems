#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define MAX 10000

void fn();

vector<int> graph[MAX];
set<int> work[MAX];
int val[MAX], color[MAX], deg[MAX];
int n, m, x, y, ret = 0, start, TC = 0;
int big;

int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        big = 0;
        ret = 0, start = 0;
        for(int i = 0; i <= n; i++)
            graph[i].clear();

        for(int i = 0; i <= n; i++)
            work[i].clear();
        memset(deg, 0, sizeof(deg));

        for(int i = 0; i < m; i++)
        {

            scanf("%d %d", &x, &y);
            graph[x].push_back(y), graph[y].push_back(x);
            deg[x]++, deg[y]++;

            if(deg[x] > ret)
                ret = deg[x], start = x;

            if(deg[y] > ret)
                ret = deg[y], start = y;
        }

        if(ret%2==0)
            ret++;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < ret; j++)
                work[i].insert(j);

        fn();

        if(TC++)
            printf("\n");
        printf("%d\n", ret);
        for(int i = 1; i <= n; i++)
            printf("%d\n", color[i] + 1);

    }


    return 0;
}

void fn()
{
    memset(val, 0, sizeof(val));
    memset(color, -1, sizeof(color));

    int curr = start, j = 0;
    pair<int, int> tmp2;
    priority_queue<pair<int, int> >heap;


    while(j < n)
    {
        int tmp = *(work[curr].upper_bound(-1));

        color[curr] = tmp;
        big = max(big, tmp);

        for(int i = 0; i < graph[curr].size(); i++)
            if(color[graph[curr][i]] == -1 && *(work[graph[curr][i]].upper_bound(tmp - 1)) == tmp)
            {
                int nw = graph[curr][i];

                work[nw].erase(work[nw].upper_bound(tmp - 1));
                val[nw]++;

                tmp2.first = nw, tmp2.second = val[nw];
                heap.push(tmp2);
            }


        if(heap.empty() == 0)
            tmp2 = heap.top(), heap.pop();

        while(heap.empty() == 0 && val[tmp2.first] != tmp2.second)
            tmp2 = heap.top(), heap.pop();
        curr = tmp2.first;

        j++;
    }

}
