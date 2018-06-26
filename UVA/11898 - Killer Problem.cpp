#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX1 200009
#define MAX2 10000

int get(int start, int end);

int visited[MAX2 + 50], flag = 0, n, array[MAX1], m, x, y, cases;
const int inf = (1 << 30);

int main()
{
    memset(visited, -1, sizeof(visited));

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);

        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);

            printf("%d\n", get(x - 1, y));
            flag++;
        }
    }

    return 0;
}

int get(int start, int end)
{
    int first = inf, last = 0, ret = inf;

    for(int i = start; i < end; i++)
    {
        if(visited[array[i]] == flag)
            return 0;

        visited[array[i]] = flag;
        first = min(first, array[i]);
        last = max(last, array[i]);
    }

    int before = first;
    for(int i = first + 1; i <= last; i++)
    {
        if(visited[i] == flag)
            ret = min(ret, abs(before - i)), before = i;

        if(ret == 1)
            break;
    }

    return ret;
}
