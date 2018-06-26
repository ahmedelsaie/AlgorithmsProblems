#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 1000009

struct rook
{
    int r1, c1, r2, c2, c_ans, r_ans, id;
};

int fn();

rook array[MAX];
int row[MAX], col[MAX], n;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d", &array[i].r1, &array[i].c1, &array[i].r2, &array[i].c2);
            array[i].id = i;
        }

        if(fn() == 0)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        for(int i = 0; i < n; i++)
            printf("%d %d\n", array[i].r_ans, array[i].c_ans);
    }

    return 0;
}

bool comp_c(rook x, rook y)
{
    return x.c2 < y.c2;
}

bool comp_r(rook x, rook y)
{
    return x.r2 < y.r2;
}

bool comp_id(rook x, rook y)
{
    return x.id < y.id;
}

int fn()
{
    sort(array, array + n, comp_c);
    memset(col, -1, sizeof(col));

    for(int i = 0; i < n; i++)
        for(int j = array[i].c1; j <= array[i].c2; j++)
        {
            if(col[j] == -1)
            {
                col[j] = array[i].id, array[i].c_ans = j;
                break;
            }
        }

    int cnt = 0;
    for(int i = 0; i <= n; i++)
        cnt += (col[i] != -1);

    if(cnt < n)
        return 0;

    sort(array, array + n, comp_r);
    memset(row, -1, sizeof(row));

    for(int i = 0; i < n; i++)
        for(int j = array[i].r1; j <= array[i].r2; j++)
        {
            if(row[j] == -1)
            {
                row[j] = array[i].id, array[i].r_ans = j;
                break;
            }
        }

    cnt = 0;
    for(int i = 0; i <= n; i++)
        cnt += (row[i] != -1);

    if(cnt < n)
        return 0;

    sort(array, array + n, comp_id);

    return 1;
}
