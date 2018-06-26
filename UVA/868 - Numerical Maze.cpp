#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long
#define inf 9999999

void update(int col);
void fn(int row, int col, int prev, int series);
int get_nxt(int series, int prev);

bool visited[50][50];
int arr[50][50];
int max_row, max_col;

int starty, end1y;
int j;

int main()
{
    memset(visited, true, sizeof(visited));

    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%d %d", &max_row, &max_col);
        for(int j = 0; j < max_row; j++)
            for(int k = 0; k < max_col; k++)
                scanf("%d", &arr[j][k]);

        starty = inf;
        end1y = inf;

        for(j = 0; j < max_col; j++)
            fn(0, j, 0, 0);

        printf("%d %d\n", 1, starty + 1);
        printf("%d %d\n", max_row, end1y + 1);
        if(i < cases - 1)
            printf("\n");
    }
    return 0;
}

void fn(int row, int col, int prev, int series)
{
    if(!visited[row][col])
        return;

    if(row < 0 || row >= max_row)
        return ;

    if(col < 0 || col >= max_col)
        return ;

    if(row == max_row - 1 && arr[row][col] == get_nxt(series, prev) && series == get_nxt(series, prev))
    {
        update(col);
        return;
    }

    int new_prev, new_series = series;
    new_prev = get_nxt(series, prev);

    if(new_prev == 1)
        new_series++;

    if(arr[row][col] == new_prev)
    {
        visited[row][col] = false;
        fn(row + 1, col, new_prev, new_series);
        fn(row - 1, col, new_prev, new_series);
        fn(row, col + 1, new_prev, new_series);
        fn(row, col - 1, new_prev, new_series);
    }
    visited[row][col] = true;
    return;
}

int get_nxt(int series, int prev)
{
    if(prev < series)
        return prev + 1;
    else
        return 1;
}

void update(int col)
{
    if(j < starty)
    {
        starty = j;
        end1y = col;
        return ;
    }

    if(j == starty)
        if(col < end1y)
        {
            starty = j;
            end1y = col;
            return ;
        }
}


