#include <stdio.h>
#include <stdlib.h>

unsigned long long nWays(int idx, int rem);
void clear();

int COINS = 5;
int MAX_COIN = 7500;
int coins[5] = {1, 5, 10, 25, 50};

unsigned long long mem[5][7500];
unsigned long long nWays(int idx, int rem);

int main()
{
    int input;

    clear();

    while(scanf("%d", &input) != EOF)
    {
        printf("%lld\n", nWays(0, input));
    }

    return 0;
}

void clear()
{
    int counter, counter2;
    for(counter = 0; counter < 5; counter++)
    {
        for(counter2 = 0; counter2 < 7500; counter2++)
            mem[counter][counter2] = -1;
    }
}

unsigned long long nWays(int idx, int rem)
{
    if(rem == 0)
        return 1;

    if(rem < coins[idx] || idx == COINS)
        return 0;

    unsigned long long ret = mem[idx][rem];
    int counter;

    if(ret != -1)
        return ret;

    ret = nWays(idx, rem - coins[idx]) + nWays(idx + 1, rem) ;
    mem[idx][rem] = ret;

    return ret;
}
