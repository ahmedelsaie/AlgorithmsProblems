#include <iostream>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
double dp[2005][2005][2], p;
bool visited[2005][2005][2];
int t, n;
double fn(int sec, int left, int mode);

int main()
{
    double ans = 0;
    ///n noof peaolple t---sec
    memset(visited, 0, sizeof(visited));
    scanf("%d %lf %d", &n, &p, &t);
    /*dp[1][1] = p;
        dp[1][0] = 1.0 - p;
        visited[1][1] = visited[1][0] = 1;
        */
    for(int i = 0; i <= n && i <= t ; i++)
    {
        if(i < n)
            ans += (double)i * fn(t, i, 1);
        else
            ans += (double)i * fn(t, i, 0);
        // printf("%d %lf\n", i, fn(t, i));
    }
    printf("%lf\n", ans);

///5 1.0 10

    return 0;
}

double fn(int sec, int left, int mode)
{
    if(sec == 0)
        return left == 0;
    // printf("%d %d\n",sec,left);

    if(left == 0)
    {
        if(mode == 0)
            return 1;
        else
            return (1 - p) * fn(sec - 1, left, mode);
    }


    bool& flag = visited[sec][left][mode];
    double& ret = dp[sec][left][mode];
    if(flag)
        return ret;
    ret = 0, flag = true;
    ///move
    ///  if(left)
    ret += p * fn(sec - 1, left - 1, mode);
    ret += (1 - p) * fn(sec - 1, left, mode);
    return ret;
}
