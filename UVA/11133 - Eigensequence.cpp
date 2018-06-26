#include <stdio.h>
#include <cstring>

int fn(int last);

int dp[50];
int big, small;

int main()
{
    while(true)
    {
        scanf("%d %d", &small, &big);
        if(big == 0 && small == 0)
            break;

        memset(dp, -1, sizeof(dp));

        printf("%d %d %d\n", small, big, fn(big));

    }
    return 0;
}

int fn(int last)
{
    if(last == small)
        return 1;

    int &ret = dp[last];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i = last - 1; i >= small; i--)
        if(i % (last - i) == 0)
            ret += fn(i);

    return ret;
}
