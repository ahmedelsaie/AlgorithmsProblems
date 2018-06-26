#include <stdio.h>
#include <cstring>
#include <stdlib.h>

long long max(long long x, long long y);
long long fn(int i);
long long check(int start, int end);

long long dp[201];
int n;
char array[202];
const int inf = 9999999;

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%s", array);
        n = strlen(array);
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", fn(0));
    }

    return 0;
}

long long fn(int i)
{
    if(i == n)
        return 0;

    long long &ret = dp[i];
    if(ret != -1)
        return ret;
    ret = -1 * inf;
    int j = i;

    while(j < n)
    {
        long long temp = check(i, j);
        if(temp == -1)
            break;
        long long r = temp + fn(j + 1);

        ret = max(ret, r);
        j++;
    }
    return ret;
}

long long max(long long x, long long y)
{
    if(x > y)
        return x;
    return y;
}

long long check(int start, int end)
{
    if(end - start + 1 > 10)
        return -1;

    char buffer[15];
    int j = 0;
    for(int i = start; i <= end; i++)
    {
        buffer[j] = array[i];
        j++;
    }
    buffer[j] = '\0';

    if(end - start + 1 < 10)
        return atol(buffer);


    char limit[] = "2147483647";

    for(int i = 0; i < 10; i++)
    {
        if(buffer[i] > limit[i])
            return -1;
        if(limit[i] > buffer[i])
            break;
    }

    return atol(buffer);
}
