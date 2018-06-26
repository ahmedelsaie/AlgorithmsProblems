#include <stdio.h>
#include <cstring>
int fn(int day, int taken_before);
int min(int x, int y);
int max(int x, int y);
void reset();

const int inf = 9999999;
int total_days, max_prod;
int dp[1005][105];
int max_order[1005];
int prod[1005];
int cost[1005];

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        max_prod = 0;
        scanf("%d", &total_days);
        for(int i = 0; i < total_days; i++)
        {
            scanf("%d %d %d", &cost[i], &max_order[i], &prod[i]);
            max_prod = max(max_prod, prod[i]);
        }
        reset();
        printf("%d\n", fn(0, 0));
    }
    return 0;
}

int fn(int day, int taken_before)
{
    if(day > 0)
        if(taken_before > max_order[day - 1])
            return inf;

    if(day == total_days)
        return 0;

    int& ret = dp[day][taken_before];
    if(ret != -1)
        return ret;
    ret = inf;

    if(day == 0)
        ret = fn(day + 1, prod[day]) + prod[day] * cost[day];
    else
    {
        int limit = max_order[day - 1] - taken_before;

        for(int i = 0; i <= limit && i <= prod[day]; i++)
        {
            int left = prod[day] - i;
            int temp = fn(day + 1, left) + cost[day] * left + cost[day - 1] * i;
            ret = min(ret, temp);
        }
    }

    return ret;
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

void reset()
{
    for(int i = 0; i < total_days + 1; i++)
        for(int j = 0; j < max_prod + 1; j++)
            dp[i][j] = -1;
}
