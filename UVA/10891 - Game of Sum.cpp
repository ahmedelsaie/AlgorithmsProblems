#include <stdio.h>

void reset();
int max(int x, int y);
int optimal(int p1, int p2);

int n;
int dp[105][105];
int accum[105];

int main()
{
    int sum, input;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        sum = 0;
        accum[0] = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &input);
            sum += input;
            accum[i + 1] = sum;
        }

        reset();
        printf("%d\n", optimal(0, n - 1));
    }

    return 0;
}

int optimal(int p1, int p2)
{
    if(p2 < p1)
        return 0;
    int &ret = dp[p1][p2];
    if(ret != -1)
        return ret;
    int ans = 0;
    int ans2 = 0;
    ret = -100000000;

    for(int i = p1; i <= p2; i++)
    {
        ans = (accum[i + 1] - accum[p1]) - optimal(i + 1, p2);
        ret = max(ret, ans);
        ans2 = (accum[p2 + 1] - accum[i]) - optimal(p1, i - 1);
        ret = max(ret, ans2);
    }

    return ret;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void reset()
{
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < n + 1; j++)
            dp[i][j] = -1;
}
