#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

double fn(int left, int left_win);

double dp[50][50];
int visited[50][50], cases = 1, n;
double p, ans;

int main()
{
    memset(visited, -1, sizeof(visited));

    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %lf", &n, &p);
        ans = 0;
        for(int i = n; i <= 2 * n - 1; i++)
            ans += fn(2 * n - 1, i);
        printf("%.2lf\n", ans);
    }

    return 0;
}

double fn(int left, int left_win)
{
    if(left == 0)
        return left_win == 0;

    double& ret = dp[left][left_win];
    int& flag = visited[left][left_win];
    if(flag == cases)
        return ret;

    ret = 0, flag = cases;

    ret += (1 - p) * fn(left - 1, left_win);
    if(left_win)
        ret += p * fn(left - 1, left_win - 1);
    return ret;
}
