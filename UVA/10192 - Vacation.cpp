#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

void reset();
int fn(int p1, int p2);

char arr[110];
char arr2[110];
const int inf = 1000000;
int dp[120][120];
int x;
int x2;
int result;

int main()
{
    int cases = 1;

    while(true)
    {
        gets(arr);

        x = strlen(arr);
        if(arr[0] == '#')
        {
            break;
        }

        gets(arr2);
        x2 = strlen(arr2);
        reset();
        result = fn(0, 0);
        printf("Case #%d: you can visit at most %d cities.\n", cases, result);
        cases++;
    }

    return 0;
}

int fn(int p1, int p2)
{
    if(dp[p1][p2] != -1)
        return dp[p1][p2];

    if(p1 >= x || p2 >= x2)
        return 0;

    int r1 = 0;
    int r2 = 0;

    if(arr[p1] == arr2[p2])
    {
        int g = fn(p1 + 1, p2 + 1) + 1;
        dp[p1][p2] = g;
        return g;
    }
    else
    {
        r1 = fn(p1 + 1, p2);
        r2 = fn(p1, p2 + 1);

        if(r1 > r2)
        {
            dp[p1][p2] = r1;
            return r1;
        }
        else
        {
            dp[p1][p2] = r2;
            return r2;
        }

    }

}

void reset()
{
    int r = x;
    if(x2 > x)
        r = x2;
    for(int counter = 0; counter < r + 5; counter++)
        for(int counter2 = 0; counter2 < r + 5; counter2++)
            dp[counter][counter2] = -1;

}
