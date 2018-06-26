#include <stdio.h>
#include <stdlib.h>

int fn(int row, int col);
void reset();

int dp[105][105];
int board[105][105];
int row_max;
int col_max;

int main()
{
    int counter, counter2, counter3, nw, maxim, cases;
    char name[100];

    scanf("%d", &cases);

    for(counter3 = 0; counter3 < cases; counter3++)
    {
        scanf("%s", name);
        scanf("%d %d", &row_max, &col_max);

        for(counter = 0; counter < row_max; counter++)
        {
            for(counter2 = 0; counter2 < col_max; counter2++)
                scanf("%d", &board[counter][counter2]);
        }

        reset();
        maxim = 0;

        for(counter = 0; counter < row_max; counter++)
        {
            for(counter2 = 0; counter2 < col_max; counter2++)
            {
                nw = fn(counter, counter2);
                if(nw > maxim)
                    maxim = nw;
            }

        }

        printf("%s: %d\n", name, maxim);

    }

    return 0;
}

void reset()
{
    int counter, counter2;
    for(counter = 0; counter < row_max + 5; counter++)
    {
        for(counter2 = 0; counter2 < col_max + 5; counter2++)
            dp[counter][counter2] = -1;
    }

}

int fn(int row, int col)
{
    if(dp[row][col] != -1)
        return dp[row][col];

    int current = board[row][col];
    int max = 0;
    int r;

    if(row + 1 < row_max && board[row + 1][col] < current)
    {
        r = fn(row + 1, col);
        if(r > max)
            max = r;
    }

    if(row - 1 >= 0 && board[row - 1][col] < current)
    {
        r = fn(row - 1, col);
        if(r > max)
            max = r;
    }


    if(col + 1 < col_max && board[row][col + 1] < current)
    {
        r = fn(row, col + 1);
        if(r > max)
            max = r;
    }


    if(col - 1 >= 0 && board[row][col - 1] < current)
    {
        r = fn(row, col - 1);
        if(r > max)
            max = r;
    }

    dp[row][col] = max + 1;
    return max + 1;
}
