#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int fn(int curr, int left);
void trace(int curr, int left);
int v1, v2, t, d, dp[5005][300];
const int inf = 999999;
void trace(int curr, int left);
int correct = 150;
int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &v1, &v2);
    scanf("%d %d", &t, &d);
    int ans = -1 * inf;

    printf("%d\n", fn(v1, t));
    // trace(v1, t - 1);
    /* int ret = -1 * inf;
     int c = 0;
     int curr = v1, left = t;
     for(int i = 0; i <= d; i++)
     {
         ret = max(ret, curr + fn(curr + i, left - 1));
         if(ret == curr + fn(curr + i, left - 1))
             c = i;
         if(curr - i >= 0)
             ret = max(ret, curr + fn(curr - i, left - 1));
         if(ret == curr + fn(curr - i, left - 1))
             c = -1 * i;
     }
     printf("%d\n", c);
     */
    return 0;
}

int fn(int curr, int left)
{
    int& ret = dp[curr][left];
    if(ret != -1)
        return ret;
    ret = -1 * inf;

    if(left == 1)
    {
        if(curr == v2)
            ret = v2;
        //ret = curr;
        return ret;
    }

    for(int i = 0; i <= d; i++)
    {
        ret = max(ret, curr + fn(curr + i, left - 1));

        if(curr - i >= 0)
        ret = max(ret, curr + fn(curr - i, left - 1));
    }

    return ret;
}


void trace(int curr, int left)
{
    if(left == 0)
        return;

    int& ret = dp[curr][left];
    int s;
    for(int i = 0; i <= d; i++)
    {
        if(ret == curr + fn(curr + i, left - 1))
            s = curr + i;

        if(curr - i >= 0)
            if(ret == curr + fn(curr - i, left - 1))
                s = curr - i;
    }
    printf("%d ", s);
    trace(s, left - 1);

}
