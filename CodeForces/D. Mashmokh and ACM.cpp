#include <stdio.h>
#include <cstring>
#define correct 1000000007
long long fn(int last, int step);
int length, max_value;
long long dp[2050][2050];

int main()
{
    scanf("%d %d", &max_value, &length);
    memset(dp, -1, sizeof(dp));
    long long ans = 0;

    ans = fn(1, length) % correct;
    printf("%lld", ans);

    return 0;
}

long long fn(int last, int step)
{
    if(step == 0)
        return 1;

    long long &ret = dp[last][step];
    if(ret != -1)
        return ret;

    ret = 0;
    for(int i = last; i <= max_value; i += last)
        ret += fn(i, step - 1) % correct;
    return ret;
}
