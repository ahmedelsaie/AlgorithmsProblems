#include <stdio.h>
#include <cstring>
#define MAX 38

long long fn(int curr, int before);
void trace(int with_me, int curr, int before);
int get_start();

long long dp[MAX + 5][2];

int x, cases, first;;

int main()
{
    memset(dp, -1, sizeof(dp));
    fn(MAX, 0);
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &x);
        x++;
        first = get_start();
        trace(0, first, 0);
        printf("\n");
    }

    return 0;
}

int get_start()
{
    for(int i = 0; i <= MAX; i++)
        if(dp[i][0] >= x)
            return i;
    return -1;
}

void trace(int with_me, int curr, int before)
{
    if(curr == 0)
        return;

    if(before == 1)
        printf("0"), trace(with_me, curr - 1, 0);
    else
    {
        long long zero = dp[curr - 1][0];
        if(zero + with_me >= x)
            printf("0"), trace(with_me, curr - 1, 0);
        else
            printf("1"), trace(with_me + zero, curr - 1, 1);
    }
}

long long fn(int curr, int before)
{
    long long& ret = dp[curr][before];
    if(ret != -1)
        return ret;

    if(curr == 0)
        return ret = 1;

    ret = 0;

    ret += fn(curr - 1, 0);

    if(before != 1)
        ret += fn(curr - 1, 1);

    return ret;
}
