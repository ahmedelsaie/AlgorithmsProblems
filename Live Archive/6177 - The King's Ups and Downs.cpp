#include <stdio.h>
#include <cstring>
#define MAX 21
#define ull unsigned long long

ull  fn(int shorter, int taller, bool flag, int left);

bool visited[MAX][MAX][2];
ull dp[MAX][MAX][2];

int main()
{
    int cases, c, n;
    ull ans;
    memset(visited, false, sizeof(visited));
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &c, &n);
        if(n == 1)
            ans = 1;
        else
            ans = fn(0, n, 0, n) + fn(n, 0, 1, n);
        printf("%d %llu\n", c, ans);
        // printf("\n");
    }
    return 0;
}

ull  fn(int shorter, int taller, bool flag, int left)
{
    if(left == 0)
        return 1;

    bool& v = visited[shorter][taller][flag];
    ull& ret = dp[shorter][taller][flag];
    if(v)
        return ret;
    v = true;
    ret = 0;

    if(flag == 0)
    {
        for(int i = 1; i <= taller; i++)
            ret += fn(shorter + i - 1, taller - i, !flag, left - 1);
    }
    else
    {
        for(int i = 1; i <= shorter; i++)
            ret += fn(i - 1, taller + (shorter - i), !flag, left - 1);
    }

    return ret;
}
