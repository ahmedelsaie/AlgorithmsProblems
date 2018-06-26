#include <stdio.h>
#include <stdlib.h>

int max_gold(int trea, int seconds_left);
void reset();

int no_trea;
int dist[35];
int values[35];
int w;
int t;
int dp[31][1200];

int main()
{
    int counter, counter2;
    int value1;
    int r;
    int global_taken;
    int inputs = 0;

    while(scanf("%d", &t) != EOF)
    {
        scanf("%d", &w);
        if(inputs > 0)
            printf("\n");
        scanf("%d", &no_trea);
        for(counter = 0; counter < no_trea; counter++)
            scanf("%d %d", &dist[counter], &values[counter]);

        reset();

        value1 = max_gold(0, t);
        printf("%d\n", value1);
        int s = t;
        global_taken = 0;

        for(counter = 1; counter <= no_trea; counter++)
        {
            r = 3 * w * dist[counter - 1];
            if(s - r < 0)
            {
                continue;
            }
            if(dp[counter][s - r] + values[counter - 1] > dp[counter][s])
            {
                global_taken++;
                s = s - r;
            }

        }
        printf("%d", global_taken);

        int taken2 = 0;
        printf("\n");
        if(global_taken != 0)
        {
            for(counter = 1; counter <= no_trea; counter++)
            {
                r = 3 * w * dist[counter - 1];
                if(t - r < 0)
                {
                    continue;
                }
                if(dp[counter][t - r] + values[counter - 1] >= dp[counter][t])
                {
                    printf("%d %d", dist[counter - 1], values[counter - 1]);
                    taken2++;

                    if(taken2 < global_taken + 1)
                        printf("\n");
                    t = t - r;
                }

            }
        }

        inputs++;
    }


    return 0;
}

void reset()
{
    int counter, counter2;
    for(counter = 0; counter < 31; counter++)
    {
        for(counter2 = 0; counter2 < 1001; counter2++)
            dp[counter][counter2] = -1;
    }
}

int max_gold(int trea, int seconds_left)
{
    if(seconds_left < 0)
        return -10000000000;

    if(dp[trea][seconds_left] != -1)
        return dp[trea][seconds_left];

    if(seconds_left == 0 || trea == no_trea)
        return 0;

    int v1;
    int v2;
    int max1;

    int r = w * dist[trea] * 3;


    v1 = values[trea] + max_gold(trea + 1, seconds_left - r);
    v2 = max_gold(trea + 1, seconds_left);

    if(v1 >= v2)
        max1 = v1;
    else
        max1 = v2;

    dp[trea][seconds_left] = max1;
    return max1;

}

