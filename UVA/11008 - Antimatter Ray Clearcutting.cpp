#include <stdio.h>

int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int cntbit(int mask);
int fn(int mask);
int min(int x, int y);
void reprocess();
void reset();

int m, n;
int x[20];
int y[20];
int missed_points[20][20];
int dp[131072];
const int inf = 100000000;

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int j = 0; j < cases; j++)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &x[i], &y[i]);

        reprocess();
        reset();
        printf("Case #%d:\n", j + 1);
        printf("%d\n", fn((1 << n) - 1));

        if(j < cases - 1)
            printf("\n");
    }

    return 0;
}

int fn(int mask)
{
    if(n - cntbit(mask) >= m)
        return 0;

    int &ret = dp[mask];
    if(ret != -1)
        return ret;

    int mini = inf, ans;
    bool flag = true;

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            if(getbit(mask, i) && getbit(mask, j))
            {
                flag = false;
                ans = fn(mask & missed_points[i][j]) + 1;
                mini = min(ans, mini);
            }
        }

    if(flag)
        return ret = 1;
    else
        return ret = mini;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

void reprocess()
{
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            int tempmask = (1 << n) - 1;
            tempmask = setbit(tempmask, i, 0);
            tempmask = setbit(tempmask, j, 0);
            for(int k = 0; k < n; k++)
                if(k != i && k != j)
                {
                    int x1 = x[j] - x[i];
                    int y1 = y[j] - y[i];

                    int x2 = x[k] - x[i];
                    int y2 = y[k] - y[i];

                    if(x1 * y2 - y1 * x2 == 0)
                        tempmask = setbit(tempmask, k, 0);
                }
            missed_points[i][j] = tempmask;
        }
    return ;
}

void reset()
{
    for(int i = 0; i < (1 << n) + 10; i++)
        dp[i] = -1;
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
