#include <stdio.h>

void print();
void fn();
void add_me(int i);

int dp[1030][1030];

int x[20009];
int y[20009];
int pop[20009];

int d, num;

int main()
{
    int cases;

    for(int i = 0; i < 1030; i++)
        for(int j = 0; j < 1030; j++)
            dp[i][j] = 0;

    scanf("%d", &cases);
    for(int c = 0; c < cases; c++)
    {
        scanf("%d", &d);
        scanf("%d", &num);

        for(int i = 0; i < num; i++)
            scanf("%d %d %d", &x[i], &y[i], &pop[i]);

        fn();
        print();
    }

    return 0;
}

void print()
{
    int ans_x, ans_y;
    int ans_num = 0;
    for(int i = 0; i < 1024; i++)
        for(int j = 0; j < 1024; j++)
        {
            if(dp[i][j] > ans_num)
            {
                ans_num = dp[i][j];
                ans_x = i;
                ans_y = j;
            }
            dp[i][j] = 0;
        }

    printf("%d %d %d\n", ans_x, ans_y, ans_num);
    return ;
}

void fn()
{
    for(int i = 0; i < num; i++)
        add_me(i);
    return;
}

void add_me(int i)
{
    for(int m = x[i] - d; m <= d + x[i]; m++)
    {
        if(m >= 0 && m < 1024)
            for(int n = y[i] - d; n <= d + y[i]; n++)
            {
                if(n >= 0 && n < 1024)
                    dp[m][n] += pop[i];
            }
    }

    return;
}
