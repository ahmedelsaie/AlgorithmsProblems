#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define ll long long
using namespace std;

int fn(int x);

vector<int>tree[3005];
int visited[3005];
int dp[3005];
int n, m, x, y, dest, cases = 0;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        tree[x].push_back(y);
    }
    memset(visited, -1, sizeof(visited));

    long long ans = 0;
    for(int i = 1; i <= n; i++)
        ans += fn(i);

    printf("%lld\n", ans);
    return 0;
}

int fn(int x)
{
    cases++;
    int ret = 0;
    for(int i = 0; i < tree[x].size(); i++)
    {
        int tmp = tree[x][i];
        for(int j = 0; j < tree[tmp].size(); j++)
        {
            int d = tree[tmp][j];
            if(d != x)
            {
                if(visited[d] == cases)
                {
                    ret += dp[d];
                    dp[d]++;
                }
                else
                    visited[d] = cases, dp[d] = 1;
            }

        }
    }

    return ret;
}


