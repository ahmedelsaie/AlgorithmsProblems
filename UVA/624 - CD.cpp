#include <stdio.h>
#include <stdlib.h>

int fn(int i, int value, int taken);
void reset();

int total;
int nooftracks;
int tracks[22];
int m = 0;
int global_i = 0;
int global_value = 0;
int global_taken = 0;
int work[22];
int last[22];
int dp[100000][21];

int main()
{
    int counter;

    while(scanf("%d", &total) != EOF)
    {
        scanf("%d", &nooftracks);
        for(counter = 0; counter < nooftracks; counter++)
            scanf("%d", &tracks[counter]);
        m = 0;
        global_i = 0;
        global_value = 0;
        global_taken = 0;

        reset();

        fn(0, 0, 0);
        for(counter = 0; counter < global_taken; counter++)
            printf("%d ", last[counter]);
        printf("sum:%d\n", global_value);
    }


    return 0;
}

void reset()
{
    int ans = 0;
    int counter, counter2;
    for(counter = 0; counter < 20; counter++)
        ans = ans + tracks[counter];

    for(counter = 0; counter < ans + 1; counter++)
        for(counter2 = 0; counter2 < 21; counter2++)
            dp[counter][counter2] = -1;
}

int fn(int i, int value, int taken)
{
    int x = 0, y = 0;
    if(dp[value][i] != -1)
        return dp[value][i];

    int counter, counter2;
    if(i == nooftracks || value == total)
    {
        if(value > global_value)
        {
            for( counter = 0; counter < taken; counter++)
            {
                last[counter] = work[counter];
            }
            global_value = value;
            global_taken = taken;
            dp[value][i] = value;
            return value;

        }
        else
        {
            dp[value][i] = -1000000000;
            return -1000000000;
        }
    }
    else
    {
        for(counter = i; counter < nooftracks; counter++)
        {
            if((value + tracks[counter]) <= total)
            {
                work[taken] = tracks[counter];
                x = fn(counter + 1, (value + tracks[counter]), taken + 1);
                if(x < 0)
                    x = -1000000000;
            }
            y = fn(counter + 1, value, taken);
            if(y < 0)
                y = -1000000000;
            if(x > y)
            {
                dp[value][i] = x;
                return x;
            }
            else
            {
                if(y > x)
                {
                    dp[value][i] = y;
                    return y;
                }
                else
                    return -1000000000;
            }
        }
    }
}
