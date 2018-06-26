#include <stdio.h>
#include <cstring>
long long fn(int mode, int left_first, int left_sec, int curr, int first, int left);

long long dp[35][34][34][2][2];
bool visited [35][34][34][2][2];
int d, g;

int main()
{
    long long ans;
    int cases = 1;
    memset(visited, false, sizeof(visited));
    while(true)
    {
        scanf("%d %d", &d, &g);

        if(d == -1 && g == -1)
            break;

        ans = fn(g, d, d, 1, 1, 2 * d) + fn(g, d, d, 0, 0, 2 * d);
        printf("Case %d: %lld\n", cases, ans);
        cases++;
    }
    return 0;
}

long long fn(int mode, int left_first, int left_sec, int curr, int first, int left)
{
    if(left_first < 0 || left_sec < 0 || left < 0)
        return 0;

    if(left_first == 0 && left_sec > 0 && first == 0)
        return 1;

    if(left_first > 0 && left_sec == 0 && first == 1)
        return 1;

    if(left == 0)
    {
        if(curr == first)
            return 1;
        return 0;
    }

    long long &ret = dp[mode][left_first][left_sec][curr][first];
    bool &flag = visited[mode][left_first][left_sec][curr][first];
    if(flag)
        return ret;

    flag = true;
    ret = 0;

    if(curr)
        for(int i = 1; i <= g; i++)
            ret += fn(mode, left_first, left_sec - i, !curr, first, left - i);
    else
        for(int i = 1; i <= g; i++)
            ret += fn(mode, left_first - i, left_sec, !curr, first, left - i);
    return ret;
}
