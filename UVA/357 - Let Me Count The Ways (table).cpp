#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

unsigned long long int fn(int left);

long long dp[5][30001];
int coins[5] = {1, 5, 10, 25, 50};

int main()
{
    fn(30000);
    int input;
    unsigned long long int ans;

    while(scanf("%d", &input) != EOF)
    {
        ans = dp[0][input];
        if(ans == 1)
            printf("There is only 1 way to produce %d cents change.\n", input);
        else
            printf("There are %lld ways to produce %d cents change.\n", ans, input);
    }

    return 0;
}

unsigned long long int fn(int left)
{
    for(int i = 0; i < 5; i++)
        dp[i][0] = 1;

    for(int j = 1; j <= left; j++)
        for(int i = 4; i >= 0; i--)
        {
            if(i + 1 <= 4)
                dp[i][j] += dp[i + 1][j];

            if(j - coins[i] >= 0)
                dp[i][j] += dp[i][j - coins[i]];
        }

    return dp[0][left];
}


