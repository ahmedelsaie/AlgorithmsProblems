#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

int fn(int row, int col, bool taken);
int con(int i, int j);

int n_row, n_col, cases = 0;
int dp[100009][2];
int visited[100009][2];
const int inf = 999999;
int array[100009];

int main()
{
    memset(visited, -1, sizeof(visited));

    while(true)
    {
        scanf("%d %d", &n_row, &n_col);
        if(n_row == 0 && n_col == 0)
            break;
        for(int i = 0; i < n_row; i++)
            for(int j = 0; j < n_col; j++)
                scanf("%d", &array[con(i, j)]);
        printf("%d\n", fn(0, 0, 0));
        cases += 2;
    }

    return 0;
}

int fn(int row, int col, bool taken)
{
    if(row >= n_row)
        return 0;

    if(col >= n_col)
    {
        if(taken)
            return fn(row + 2, 0, 0);
        else
            return fn(row + 1, 0, 0);
    }

    int& ret = dp[con(row, col)][taken];
    int& flag = visited[con(row, col)][taken];
    if(flag == cases)
        return ret;

    ret = -1 * inf;
    flag = cases;

    ret = max(ret, fn(row, col + 1, taken));
    ret = max(ret, fn(row, col + 2, 1) + array[con(row, col)]);

    return ret;
}


int con(int i, int j)
{
    return j + i * n_col;
}
