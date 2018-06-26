#include <stdio.h>
#include <cstring>

unsigned long long fn(int curr, int locked, int before);

unsigned long long dp[2][67][67];
bool visited [2][67][67];
int n, s;

int main()
{
    memset(visited, false, sizeof(visited));
    fn(65, 65, 0);
    while(true)
    {
        scanf("%d %d", &n, &s);

        if(n < 0 && s < 0)
            break;

        unsigned long long ans = fn(n, s, 0);
        printf("%llu\n", ans);
    }
    return 0;
}

unsigned long long fn(int curr, int locked, int before)
{
    if(locked < 0)
        return 0;

    if(curr < 0)
        return 0;

    if(curr == 0)
    {
        if(locked == 0)
            return 1;
        return 0;
    }
    unsigned long long &ret = dp[before][curr][locked];
    bool &flag = visited[before][curr][locked];
    if(flag)
        return ret;
    flag = true;
    ret = 0;

    if(before == 0)
        ret += fn(curr - 1, locked - 1, 0);
    else
        ret += fn(curr - 1, locked, 0);

    ret += fn(curr - 1, locked, 1);
    return ret;
}
