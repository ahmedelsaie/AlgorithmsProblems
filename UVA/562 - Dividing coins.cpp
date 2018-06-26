#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

int all_zeros();
void clear2();
void clear();
void get_total();
int min(int i, int taken);

int coins[130];
int noofcoins;
int total = 0;
int noofcases;
int dp[130][25050];
int x[2505000];
int y[2505000];
int n = 0;
int end1 = 0;

int main()
{
    int counter;
    scanf("%d", &noofcases);
    int counter2;

    for(counter2 = 0; counter2 < noofcases; counter2++)
    {

        scanf("%d", &noofcoins);
        for(counter = 0; counter < noofcoins; counter++)
        {
            scanf("%d", &coins[counter]);
        }

        get_total();

        if(counter2 != 0)
            clear2();
        else
            clear();
        n = 0;
        end1 = 0;
        if(all_zeros() == 1)
            printf("0");
        else

            printf("%d", min(0, 0));
        printf("\n");
    }


    return 0;
}

int all_zeros()
{
    int counter;
    for(counter = 0; counter < noofcoins; counter++)
        if(coins[counter] != 0)
            return 0;

    return 1;
}

void clear2()
{
    int counter;
    for(counter = 0; counter < n; counter++)
    {
        dp[x[counter]][y[counter]] = -1;
    }
}

void clear()
{
    int counter, counter2;
    for(counter = 0; counter < 120; counter++)
        for(counter2 = 0; counter2 < 25050; counter2++)
            dp[counter][counter2] = -1;
}

void get_total()
{
    int counter;
    total = 0;
    for(counter = 0; counter < noofcoins; counter++)
    {
        total = total + coins[counter];
    }
}

int min(int i, int taken)
{
    if(end1 == 1)
        return 0;

    if(dp[i][taken] != -1)
        return dp[i][taken];

    if(taken == total)
    {
        dp[i][taken] = 2147483647;
        x[n] = i;
        y[n] = taken;
        n++;
        return 2147483647;
    }

    int choice1, choice2;
    int remind;

    if(i == noofcoins  || taken >= .5 * total)
    {
        remind = total - taken;
        if(remind == taken)
        {

            dp[i][taken] = taken - remind;
            x[n] = i;
            y[n] = taken;
            n++;
            end1 = 1;
            return taken - remind;
        }
        if(remind < taken)
        {
            dp[i][taken] = taken - remind;
            x[n] = i;
            y[n] = taken;
            n++;
            return taken - remind;
        }

        else
        {
            dp[i][taken] = remind - taken;
            x[n] = i;
            y[n] = taken;
            n++;
            return remind - taken;

        }
    }

    choice1 = min(i + 1, taken + coins[i]);
    choice2 = min(i + 1, taken);

    if(choice1 < choice2)
    {
        dp[i][taken] = choice1;
        x[n] = i;
        y[n] = taken;
        n++;
        return choice1;
    }
    else
    {
        dp[i][taken] = choice2;
        x[n] = i;
        y[n] = taken;
        n++;
        return choice2;
    }

}


