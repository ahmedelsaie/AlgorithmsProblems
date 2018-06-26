#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

unsigned long long fn(int left);

int coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

unsigned long long dp[11][30000 + 1];
unsigned long long fn(int left);

int main()
{
    int input = 10;
    int points;

    fn(30000);

    while(true)
    {
        scanf("%d.%d", &input, &points);
        if(input == 0 && points == 0)
            break;

        input = input * 100;
        input = input + points;
        printf("%6.2f%17lld\n", (float)input / 100, dp[0][input]);
    }

    return 0;
}

unsigned long long fn(int left)
{
    for(int i = 0; i < 11; i++)
        dp[i][0] = 1;

    for(int j = 1; j <= left; j++)
        for(int i = 11 - 1; i >= 0; i--)
        {
            if(i + 1 <= 10)
                dp[i][j] += dp[i + 1][j];

            if(j - coins[i] >= 0)
                dp[i][j] += dp[i][j - coins[i]];
        }

    return dp[0][left];
}



