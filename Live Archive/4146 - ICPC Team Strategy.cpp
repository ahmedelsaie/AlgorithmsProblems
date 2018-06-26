#include <stdio.h>

void reset();
int fn(int last_player, int time_left, int mask, int n);
int getbit(int mask, int bit);
int setbit(int mask, int bit, int value);
int cntbit(int mask);
int max(int x, int y);

int dp[4][285][4150];
const int inf = 9999999;
int first[15];
int sec[15];
int third[15];
int no;

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%d", &no);

        for(int j = 0; j < no; j++)
            scanf("%d", &first[j]);

        for(int j = 0; j < no; j++)
            scanf("%d", &sec[j]);

        for(int j = 0; j < no; j++)
            scanf("%d", &third[j]);

        reset();
        int ans = fn(3, 280, 0, 0);
        printf("%d\n", ans);
    }

    return 0;
}

int fn(int last_player, int time_left, int mask, int n)
{
    if(time_left < 0)
        return -1 * inf;
    if(time_left == 0 || n == no)
        return 0;
    int &ret = dp[last_player][time_left][mask];
    if(ret != -1)
        return ret;

    int ans = 0;
    int temp = 0;

    for(int i = 0; i < no; i++)
    {
        if(getbit(mask, i) == 0)
        {
            if(last_player != 0)
            {
                temp = fn(0, time_left - first[i], setbit(mask, i, 1), n + 1) + 1;
                ans = max(ans, temp);
            }


            if(last_player != 1)
            {
                temp = fn(1, time_left - sec[i], setbit(mask, i, 1), n + 1) + 1;
                ans = max(ans, temp);
            }


            if(last_player != 2)
            {
                temp = fn(2, time_left - third[i], setbit(mask, i, 1), n + 1) + 1;
                ans = max(ans, temp);
            }

        }
    }
    return ret = ans;
}

void reset()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 285; j++)
            for(int k = 0; k < (1 << no) + 1; k++)
                dp[i][j][k] = -1;
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

int cntbit(int mask)
{
    int ret = 0;
    while(mask)
    {
        if(mask % 2)
            ret++;
        mask = mask / 2;
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
