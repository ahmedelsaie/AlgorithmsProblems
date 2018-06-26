#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

unsigned long long nWays(int idx, int rem);
void clear1();

int COINS = 11;
int MAX_COIN = 30000 + 1;
int coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

unsigned long long mem[11][30000 + 1];
unsigned long long nWays(int idx, int rem);
int ans[9000];

int main()
{
    int counter;
    int input = 10;
    int points;
    float n;

    int noofinputs = 0;

    while(input != 0)
    {

        scanf("%d.%d", &input, &points);
        input = input * 100;
        input = input + points;
        ans[noofinputs] = input;
        noofinputs++;

    }

    clear1();

    for(counter = 0; counter < noofinputs - 1; counter++)
    {
        n = ans[counter];
        n = n / 100;

        printf("%6.2f%17lld", n, nWays(0, ans[counter]));

        if(counter < noofinputs - 1)
            printf("\n");
    }

    return 0;
}

void clear1()
{
    int counter, counter2;
    for(counter = 0; counter < 11; counter++)
    {
        for(counter2 = 0; counter2 < 30000 + 1; counter2++)
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

    if(ret != -1)
        return ret;

    ret = nWays(idx + 1, rem) + nWays(idx, rem - coins[idx]);
    mem[idx][rem] = ret;

    return ret;
}
