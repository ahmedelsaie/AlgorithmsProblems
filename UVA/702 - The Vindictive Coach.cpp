#include <stdio.h>
#include <cstring>
#define ll unsigned long long
ll fn(int shorter, int taller, bool state);

ll dp[30][30][2];
int visited[30][30][2];

int cases = 0, n, coach;
ll ans;

int main()
{
    memset(visited, -1, sizeof(visited));

    while(scanf("%d %d", &n, &coach) != EOF)
    {

        if(n == 1 && coach == 1)
        {
            printf("1\n");
            cases++;
            continue;
        }

        if(coach != 1)
            ans = fn(coach - 1, n - coach, true);
        else
        {
            ans = 0;
            for(int i = 2; i <= n && ans == 0; i++)
                ans = fn(i - 2, n - i, true);
        }

        printf("%llu\n", ans);
        cases++;
    }
    return 0;
}

ll fn(int shorter, int taller, bool state)
{
    if(shorter == 0 && taller == 0)
        return 1;

    int& flag = visited[shorter][taller][state];
    ll& ret = dp[shorter][taller][state];

    if(flag == cases)
        return ret;
    ret = 0;
    flag = cases;

    if(state)
    {
        for(int i = 1; i <= shorter; i++)
            ret += fn(i - 1, taller + (shorter - i), !state);
    }
    else
    {
        for(int i = 1; i <= taller; i++)
            ret += fn(shorter + i - 1, taller - i, !state);
    }
    return ret;
}
