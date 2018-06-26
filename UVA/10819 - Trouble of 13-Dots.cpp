#include <iostream>
#include <stdio.h>
using namespace std;

void reset();
int fn(int item, int money, int res);

int  m, n;
int dp[15000][105];
int value[105];
int price[105];


int main()
{
    while((scanf("%d", &m)) != EOF)
    {
        scanf("%d", &n);

        for(int counter = 0; counter < n; counter++)
        {
            scanf("%d", &price[counter]);
            scanf("%d", &value[counter]);

        }

        reset();

        printf("%d\n", fn(0, 0, 0));
    }

    return 0;
}

void reset()
{
    for(int counter = 0; counter < m + 300; counter++)
        for(int counter2 = 0; counter2 < n + 5; counter2++)
            dp[counter][counter2] = -1;
}

int fn(int item, int money, int res)
{
    if(money - res > m && res == 0)
        res = 200;

    if(money - res > m)
        return -10000000000;


    if(dp[money][item] != -1)
    {
        return dp[money][item];
    }

    if(money - res == m && res == 200)
    {

        if(res == 200)
        {
            if(money > 2000)
                return 0;
            else
                return -10000000000;
        }
        else
            return 0;
    }

    if(item == n)
    {

        if(res == 200)
        {
            if(money > 2000)
                return 0;
            else
                return -10000000000;
        }
        else
            return 0;
    }

    int r1, r2;
    r1 = fn(item + 1, money + price[item], res) + value[item];
    r2 = fn(item + 1, money, res);

    if(r2 > r1)
    {
        dp[money][item] = r2;
        return r2;
    }
    else
    {
        dp[money][item] = r1;
        return r1;
    }

}


