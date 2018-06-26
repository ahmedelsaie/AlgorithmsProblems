#include <stdio.h>
#include <stdlib.h>

void reset();
int min(int row, int col);

int map[15][1150];
int dp[15][1150];
int x;

int main()
{
    int counter, counter2, counter3;
    int cases;
    scanf("%d", &cases);

    for(counter3 = 0; counter3 < cases; counter3++)
    {

        scanf("%d", &x);
        x = x / 100;

        for(counter = 0; counter < 10; counter++)
        {
            for(counter2 = 0; counter2 < x; counter2++)
                scanf("%d", &map[counter][counter2]);
        }

        reset();

        printf("%d\n\n", min(9, 0));
    }

    return 0;
}

void reset()
{
    int counter, counter2;

    for(counter = 0; counter < 15; counter++)
    {
        for(counter2 = 0; counter2 < 1050; counter2++)
            dp[counter][counter2] = -1;
    }
}

int min(int row, int col)
{
    int y;

    if(row > 9 || row < 0)
    {
        return 100000000;
    }

    if(col == x)
    {
        if(row == 9)
            return 0;
        else
            return 100000000;
    }

    if(dp[row][col] != -1)
        return dp[row][col];

    int r1, r2, r3, max1;
    int current = map[row][col];


    r1 = 60 - current + min(row - 1, col + 1);
    r2 = 30 - current + min(row, col + 1);
    r3 = 20 - current + min(row + 1, col + 1);

    max1 = r1;

    if(r2 < max1)
        max1 = r2;

    if(r3 < max1)
        max1 = r3;

    dp[row][col] = max1;
    return max1;
}


