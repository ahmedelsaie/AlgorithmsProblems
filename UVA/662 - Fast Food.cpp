#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

void print(int lower, int upper, int curr, int left);
void trace(int curr, int left, int lower);
int fn(int curr, int left);
void pre_process();

int pre[205][205], visited[205][32], dp[205][32], dist[205];
int n, k, cases = 1, ans, val;
const int inf = 0x3f3f3f3f;

int main()
{
    memset(visited, -1, sizeof(visited));
    bool flag = 1;
    while(scanf("%d%d", &n, &k) && !(n == 0 && k == 0))
    {
        if(n + k == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d", &dist[i]);

        pre_process();
        ans = inf;

        for(int i = 0; i <= n; i++)
        {
            int tmp = 0;
            for(int j = 0; j < i; j++)
                tmp += abs(dist[i] - dist[j]);

            if(fn(i, k - 1) + tmp < ans)
                ans = fn(i, k - 1) + tmp, val = i;
        }

        printf("Chain %d\n", cases++);
        trace(val, k - 1, 0);
        printf("Total distance sum = %d\n\n", ans);
    }

    return 0;
}

void trace(int curr, int left, int lower)
{
    if(left == 0)
    {
        print(lower, n - 1, curr, left);
        return ;
    }

    int v;
    int ans1 = inf;
    for(int i = curr + 1; i < n; i++)
        if(dp[i][left - 1] + pre[curr][i] < ans1)
            ans1 = dp[i][left - 1] + pre[curr][i], v = i;

    int i;
    for(i = curr; i <= v; i++)
        if(abs(dist[curr] - dist[i]) > abs(dist[v] - dist[i]))
            break;

    print(lower, i - 1, curr, left);
    return trace(v, left - 1, i);
}

void print(int lower, int upper, int curr, int left)
{
    if(upper == lower)
        printf("Depot %d at restaurant %d serves restaurant %d\n", k - left, curr + 1, lower + 1);
    else
        printf("Depot %d at restaurant %d serves restaurants %d to %d\n", k - left, curr + 1, lower + 1, upper + 1);
}

void pre_process()
{
    int ans;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        {
            ans = 0;
            for(int h = i; h < j; h++)
                ans += min(abs(dist[h] - dist[i]), abs(dist[h] - dist[j]));
            pre[i][j] = ans;
        }
}

int fn(int curr, int left)
{
    int& flag = visited[curr][left];
    int& ret = dp[curr][left];
    if(flag == cases)
        return ret;
    flag = cases, ret = inf;

    if(left == 0)
    {
        int ans = 0;
        for(int i = curr; i < n; i++)
            ans += abs(dist[curr] - dist[i]);
        ret = ans;
        return ans;
    }

    for(int i = curr + 1; i < n; i++)
        ret = min(ret, fn(i, left - 1) + pre[curr][i]);

    return ret;
}
