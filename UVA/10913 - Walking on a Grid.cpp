#include <stdio.h>

int fn(int dirct, int neg, int row, int col);
void reset();
int max(int x, int y);
const int inf = 9999999;

int grid[80][80];
int dp[3][6][80][80];
int is_visited[3][6][80][80];
int max_col, max_row, k;

int main()
{
    int negative_value;
    int cases = 1;
    int ans;
    while(true)
    {
        negative_value = 0;
        scanf("%d %d", &max_col, &k);
        if(max_col == 0 && k == 0)
            break;
        max_row = max_col;

        for(int i = 0; i < max_row; i++)
            for(int j = 0; j < max_row; j++)
                scanf("%d", &grid[i][j]);
        reset();
        ans = fn(0, 0, 0, 0);
        printf("Case %d: ", cases);
        if(ans == -1 * inf)
            printf("impossible\n");
        else
            printf("%d\n", ans);
        cases++;
    }
    return 0;
}

int fn(int dirct, int neg, int row, int col)
{
    int new_neg = neg;
    if(grid[row][col] < 0)
        new_neg++;

    if(row >= max_row || col >= max_col || neg > k || row < 0 || col < 0)
        return -1 * inf;

    if(row == max_row - 1 && col == max_col - 1)
    {
        if(new_neg > k)
            return -1 * inf;
        return grid[row][col];
    }

    int &ret = dp[dirct][neg][row][col];
    if(is_visited[dirct][neg][row][col])
        return ret;
    else
        is_visited[dirct][neg][row][col] = true;
    int ans = -1 * inf;
    int temp = -1 * inf;
    ret = 0;


    if(dirct != 2)
        temp = fn(1, new_neg, row, col + 1);
    ans = max(ans, temp);

    if(dirct != 1)
        temp = fn(2, new_neg, row, col - 1);
    ans = max(ans, temp);

    temp = fn(0, new_neg, row + 1, col);
    ans = max(ans, temp);


    if(ans == -1 * inf)
        return ret = -1 * inf;
    return ret = ans + grid[row][col];
}

void reset()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < k + 1; j++)
            for(int r = 0; r < max_row + 1; r++)
                for(int c = 0; c < max_col + 1; c++)
                    is_visited[i][j][r][c] = false;
    return ;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
