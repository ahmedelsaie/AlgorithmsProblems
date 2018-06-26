#include <stdio.h>
#include <cstring>
int fn(int level, int left);

int dp[103][103];
int mod = 1000000;

int main()
{
    int levels, num;
    memset(dp, -1, sizeof(dp));
    while(true)
    {
        scanf("%d %d", &num, &levels);
        if(levels == 0 && num == 0)
            break;

        printf("%d\n", fn(levels, num) % mod);
    }

    return 0;
}

int fn(int level, int left)
{
    if(left < 0 || level < 0)
        return 0;

    if(level == 0)
    {
        if(left == 0)
            return 1;
        return 0;
    }

    int &ret = dp[level][left];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i = 0; i <= left; i++)
        ret += fn(level - 1, left - i) % mod;

    return ret % mod;
}
