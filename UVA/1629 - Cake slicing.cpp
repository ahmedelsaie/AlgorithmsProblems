#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
#define MAX 32

void build_accum(int x, int y);
int get(int x0, int y0, int x1, int y1);
int fn(int x0, int y0, int x1, int y1);

int array[MAX][MAX], accum[MAX][MAX], visited[MAX][MAX][MAX][MAX], dp[MAX][MAX][MAX][MAX];
int x, y, tmp_x, tmp_y, n, cases = 1;
const int inf = 0x3f3f3f3f;

int main()
{
    memset(visited, -1, sizeof(visited)), memset(accum, 0, sizeof(accum));

    while(scanf("%d %d %d", &x, &y, &n) == 3)
    {
        memset(array, 0, sizeof(array));
        for(int i = 0; i < n; i++)
            scanf("%d %d", &tmp_x, &tmp_y), array[tmp_x][tmp_y] = 1;

        build_accum(x, y);
        printf("Case %d: %d\n", cases, fn(1, 1, x, y));
        cases++;
    }

    return 0;
}

int fn(int x0, int y0, int x1, int y1)
{
    if(get(x0, y0, x1, y1) < 2)
        return 0;

    int& ret = dp[x0][y0][x1][y1];
    int& flag = visited[x0][y0][x1][y1];
    if(flag == cases)
        return ret;
    flag = cases, ret = inf;

    for(int i = y0; i < y1; i++)
        if(get(x0, y0, x1, i) > 0 && get(x0, i + 1, x1, y1) > 0)
            ret = min(ret, fn(x0, y0, x1, i) + fn(x0, i + 1, x1, y1) + abs(x1 - x0) + 1);

    for(int i = x0; i < x1; i++)
        if(get(x0, y0, i, y1) > 0 && get(i + 1, y0, x1, y1) > 0)
            ret = min(ret, fn(x0, y0, i, y1) + fn(i + 1, y0, x1, y1) + abs(y1 - y0) + 1);

    return ret;
}

void build_accum(int x, int y)
{
    for(int i = 0; i <= x; i++)
        accum[i][0] = 0;

    for(int i = 0; i <= y; i++)
        accum[0][i] = 0;

    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
            accum[i][j] = accum[i - 1][j] + accum[i][j - 1] - accum[i - 1][j - 1] + array[i][j];
    return ;
}

int get(int x0, int y0, int x1, int y1)
{
    return accum[x1][y1] - accum[x0 - 1][y1] - accum[x1][y0 - 1] + accum[x0 - 1][y0 - 1];
}
