#include <stdio.h>

int getbit(int mask, int bit);
int setbit(int mask, int bit, int value);
int min(int x, int y);
int max(int x, int y);
int abs(int x);
void reset();
void cnt_nut();
int dist(int first, int sec);
int fn(int current, int mask, int num);

int max_row, max_col;
int nuts;
int dp[20][(1 << 15) + 10];
char board[25][25];
int array_x[20];
int array_y[20];
int last_x, last_y;
const int inf = 99999999;

int main()
{
    bool line = true;
    int temp = inf;
    int ans = inf;
    while(scanf("%d %d", &max_row, &max_col) != EOF)
    {
        temp = inf;
        ans = inf;
        for(int i = 0; i < max_row; i++)
            scanf("%s", board[i]);
        cnt_nut();
        reset();
        if(nuts > 0)
            for(int i = 0; i < nuts; i++)
            {
                temp = fn(i, setbit(0, i, 1), 1) + dist(i, nuts);
                ans = min(ans, temp);
            }
        else
            ans = 0;
        printf("%d", ans);
        printf("\n");

    }

    return 0;
}

int fn(int current, int mask, int num)
{
    if(num == nuts)
        return dist(current, nuts);
    int &ret = dp[current][mask];
    if(ret != -1)
        return ret;
    ret = inf;
    int ans = inf;
    int temp = inf;
    for(int i = 0; i < nuts; i++)
    {
        if(!getbit(mask, i))
        {
            temp = fn(i, setbit(mask, i, 1), num + 1) + dist(current, i);
            ans = min(ans, temp);
        }
    }
    return ret = ans;
}

int dist(int first, int sec)
{
    return max(abs(array_y[first] - array_y[sec]), abs(array_x[first] - array_x[sec]));
}

void cnt_nut()
{
    nuts = 0;
    for(int i = 0; i < max_row; i++)
        for(int j = 0; j < max_col; j++)
            if(board[i][j] == '#')
            {
                array_x[nuts] = i;
                array_y[nuts] = j;
                nuts++;
            }


    for(int i = 0; i < max_row; i++)
        for(int j = 0; j < max_col; j++)
            if(board[i][j] == 'L')
            {
                array_x[nuts] = i;
                array_y[nuts] = j;
                return;
            }
}

void reset()
{
    for(int i = 0; i < nuts + 1; i++)
        for(int j = 0; j < (1 << nuts) + 5; j++)
            dp[i][j] = -1;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}
