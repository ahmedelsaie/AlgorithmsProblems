#include <stdio.h>
#include <cstring>

int min(int x, int y);
int abs(int x);
bool check(int row, int col);
int fn(int row, int col, int value);

int n;
int dp[60][60][6000];
int visited [60][60][6000];
int array[100][100];
const int inf = 999999;
int correct = 3000;
int cases = 0;

int main()
{
    memset(visited, -1, sizeof(visited));
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++)
                scanf("%d", &array[i][j]);

        for(int i = n; i < 2 * n - 1; i++)
            for(int j = 0; j + i < 2 * n - 1; j++)
                scanf("%d", &array[i][j]);


        printf("%d\n", fn(0, 0, 3000));
        cases++;
    }
    return 0;
}

int fn(int row, int col, int value)
{
    if(row == 2 * n - 1)
        return abs(value - correct);

    if(!check(row, col))
        return inf;

    int &ret = dp[row][col][value];
    int &flag = visited[row][col][value];

    if(flag == cases)
        return ret;
    flag = cases;
    ret = inf;

    if(row >= n - 1)
    {
        ret = min(ret, fn(row + 1, col - 1, value + array[row][col]));
        ret = min(ret, fn(row + 1, col, value + array[row][col]));

        ret = min(ret, fn(row + 1, col - 1, value - array[row][col]));
        ret = min(ret, fn(row + 1, col, value - array[row][col]));
    }
    else
    {
        ret = min(ret, fn(row + 1, col + 1, value + array[row][col]));
        ret = min(ret, fn(row + 1, col, value + array[row][col]));

        ret = min(ret, fn(row + 1, col + 1, value - array[row][col]));
        ret = min(ret, fn(row + 1, col, value - array[row][col]));
    }

    return ret;
}

bool check(int row, int col)
{
    if(col > n - 1 || col < 0)
        return false;

    if(row <= n - 1)
    {
        if(col > row)
            return false;
        return true;
    }
    else
    {
        if(row + col < 2 * n - 1)
            return true;
        return false;
    }
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
