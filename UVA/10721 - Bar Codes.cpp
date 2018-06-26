#include <stdio.h>

long long fn(int i, int group);
void reset();

long long dp[55][55];
int n, k, m;

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        scanf("%d%d", &k, &m);
        reset();
        printf("%lld\n", fn(0, 0));
    }

    return 0;
}

long long fn(int i, int group)
{
    if(i > n || group > k)
        return 0;

    if(i == n)
    {
        if(group < k)
            return 0;
        else
            return 1;
    }

    long long &ret = dp[i][group];
    if(ret != -1)
        return ret;

    long long result = 0;

    for(int j = 1; j <= m; j++)
        result += fn(i + j, group + 1);

    return ret = result;
}

void reset()
{
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < k + 1; j++)
            dp[i][j] = -1;
}
