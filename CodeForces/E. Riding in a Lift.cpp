#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <stdlib.h>

using namespace std;
#define ll int
int fn(int left, int floor, int mode);
int n, b, a, leftc;
ll dp[5005][5005];
ll mod = 1000000007 ;
void correct(int& x);
ll tabular();
bool check(int start, int end);

int main()
{
    scanf("%d %d %d %d", &n, &a, &b, &leftc);
    //memset(dp, -1, sizeof(dp));
    printf("%d\n", tabular());
    return 0;
}

ll tabular()
{
    ll with = 0;
    int  lower, upper;
    dp[0][0] = 0;
    ///left floor
    for(int i = 1; i <= n; i++)
    {
        if(i != b)
            with = 1;
        else
            with = 0;

        dp[0][i] = with + dp[0][i - 1];
    }
    //  printf("%lld\n",dp[0][5]);

    for(int left = 1; left <= leftc; left++)
    {
        //printf("left= %d\n", left);
        dp[left][0] = 0;
        for(int floor = 1; floor <= n; floor++)
        {
            //printf("floor = %d\n", floor);
            with = 0;
            lower = min(floor + 1, n), upper = min(floor + abs(floor - b) - 1, n);
            //printf("%d %d\n", lower, upper);
            if(upper != floor && lower != floor)
                with =  (dp[left - 1][upper] - dp[left - 1][lower - 1]+mod) % mod;
           // printf("%lld\n", with);
            lower = max(floor - abs(floor - b) + 1, 1), upper = max(floor - 1, 1);
            if(upper != floor && lower != floor)
                with = (with % mod + (dp[left - 1][upper] - dp[left - 1][lower - 1]+mod) % mod) % mod;

            //printf("%d %d\n", lower, upper);

            if(floor == b)
                with = 0;
            dp[left][floor] = ((dp[left][floor - 1] % mod) + with % mod) % mod;
            // printf("%lld\n",dp[left][floor]);
        }
    }


    return (dp[leftc][a] - dp[leftc][a - 1]+mod) % mod;
}

bool check(int start, int end)
{
    if(start < 1 || end < 1)
        return false;

    if(start > n || end > n)
        return false;

    if(start == b || end == b)
        return false;

    return true;
}
/*
int fn(int left, int floor, int mode)
{
    if(floor <= 0 || floor > n)
        return 0;

    if(left == 0)
        return 1;

    int& ret = dp[left][floor][mode];
    if(ret != -1)
        return ret;

    ret = 0;
    ///stop and cnt one
    ret += fn(left - 1, floor + abs(floor - b) + 1, 0), correct(ret);
    ret += fn(left - 1, floor - abs(floor - b) - 1, 1), correct(ret);

    if(!(floor == a && left == leftc))
    {

        ///go up && go down
        if(mode == 0)
            ret += fn(left, floor + 1, 0), correct(ret);
        else
            ret += fn(left , floor - 1, 1), correct(ret);
    }

    correct(ret);
    return ret;
}
*/
void correct(int& x)
{
    if(x >= mod)
        x = x - mod;
}
