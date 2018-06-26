#include <stdio.h>
#include <cstring>

int min(int x, int y);
int fn(int left);
void reset();

const int inf = 99999999;
int dp[1000005];
int n, left;
int array[15];

int main()
{
    int ans;
    while(scanf("%d", &left) != EOF)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);

        reset();

        for(int i = 0; i < left; i += 50000)
            fn(i);
        ans = fn(left);
        if(ans == -1 * inf)
            printf("Stan");
        else
            printf("Ollie");
        printf(" wins\n");
    }
    return 0;
}

int fn(int left)
{
    if(left == 0)
        return inf;

    int &ret = dp[left];
    if(ret != -1)
        return ret;
    ret = inf;

    for(int i = 0; i < n; i++)
        if(left >= array[i])
            ret = min(ret, -1 * fn(left - array[i]));
    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    return y;
}

void reset()
{
    for(int i = 0; i < left + 1; i++)
        dp[i] = -1;
}
