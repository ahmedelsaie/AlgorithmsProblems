#include <stdio.h>
int array[6][1009];

int k, l, cases = 0;
int dp[1009];
int fn(int last);
int max(int x, int y);
bool check(int last, int current);

int main()
{
    array[0][0] = 0;
    array[1][0] = 0;
    array[2][0] = 0;
    array[3][0] = 0;
    array[4][0] = 0;
    array[5][0] = 0;


    int ans = 0,x;
    scanf("%d %d", &l, &k);
    for(int i = 0; i < k; i++)
    {
        for(int j = 1; j <= l; j++)
        {
            scanf("%d", &x);
            array[i][x] = j;
        }
    }

    for(int i = 0; i <= l + 1; i++)
        dp[i] = -1;


    printf("%d\n", fn(0));

    return 0;
}

int fn(int last)
{
    if(last > l)
        return 0;

    int& ret = dp[last];
    if(ret != -1)
        return ret;

    ret = 0;

    for(int i = 1; i <= l; i++)
    {
        if(i != last && check(last, i) == true)
            ret = max(ret, fn(i) + 1);
    }

    return ret ;
}

bool check(int last, int current)
{
    for(int i = 0; i < k; i++)
    {
        if(array[i][last] > array[i][current])
            return false;
    }
    return true;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
