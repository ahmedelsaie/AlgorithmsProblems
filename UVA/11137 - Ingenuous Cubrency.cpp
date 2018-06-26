#include <stdio.h>

unsigned long long int fn(int left);

int coins[25]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
unsigned long long int  dp[22][10000];
unsigned long long int money;

int main()
{
    fn(10000);
    while(scanf("%llu",&money)!=EOF)
    {
        printf("%llu\n",dp[0][money]);
    }
    return 0;
}

unsigned long long int fn(int left)
{
    for(int i=0;i<22;i++)
    dp[i][0]=1;

    for(int j=1;j<=left;j++)
    for(int i=21;i>=0;i--)
    {
        if(i+1<=21)
        dp[i][j]+=dp[i+1][j];

        if(j-coins[i]>=0)
        dp[i][j]+=dp[i][j-coins[i]];
    }

    return dp[0][left];
}
