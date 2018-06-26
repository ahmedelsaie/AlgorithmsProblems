#include <stdio.h>
#include <cstring>

int fn(int last, int left, int length);

int dp[30][10000][30];
int l, s;

int main()
{
    int ans;
    int p = 1;
    memset(dp, -1, sizeof(dp));
    while(true)
    {
        scanf("%d %d", &l, &s);
        if(l == 0 && s == 0)
            break;

        ans = 0;
        for(int i = 1; i < 27; i++)
            ans += fn(i, s - i, l - 1);

        printf("Case %d: %d\n", p, ans);
        p++;
    }
    return 0;
}

int fn(int last, int left, int length)
{
    if(left < 0)
        return 0;

    if(length == 0)
    {
        if(left == 0)
            return 1;
        return 0;
    }

    int &ret = dp[last][left][length];
    if(ret != -1)
        return ret;

    ret = 0;
    for(int i = last + 1; i < 27; i++)
        ret += fn(i, left - i, length - 1);

    return ret;
}
