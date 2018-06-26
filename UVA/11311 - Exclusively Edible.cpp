#include <stdio.h>
#include <cstring>

int fn(int n_rows, int n_col, int row, int col);

int dp[50][50][50][50];
int max(int x, int y);
const int inf = 9999999;

int main()
{
    int ans, cases, all_row, all_col, row, col;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d %d %d", &all_row, &all_col, &row, &col);

        ans = fn(all_row, all_col, row, col);
        if(ans > 0)
            printf("Gretel");
        else
            printf("Hansel");
        printf("\n");
    }


    return 0;
}

int fn(int n_rows, int n_col, int row, int col)
{
    if(n_rows == 0 && n_col == 0)
        return -1 * inf;

    int &ret = dp[n_rows][n_col][row][col];
    if(ret != -1)
        return ret;
    ret = -1 * inf;
    int temp;

    for(int i = 0; i < n_rows; i++)
        if(i != row)
        {
            if(row > i)
                temp = -1 * fn(n_rows - i - 1, n_col, row - i - 1, col);
            else
                temp = -1 * fn(i, n_col, row, col);
            ret = max(ret, temp);
        }


    for(int i = 0; i < n_col; i++)
        if(i != col)
        {
            if(col > i)
                temp = -1 * fn(n_rows, n_col - i - 1, row, col - i - 1);
            else
                temp = -1 * fn(n_rows, i, row, col);
            ret = max(ret, temp);
        }

    return ret;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
