#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 10009

int fn(int i, int left, int mask, int p_msk, int taken);
int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
int greedy_fn();

int array[5][MAX], visited[MAX][6][33][6][2], dp[MAX][6][33][6][2];
int n, k, cases = 0, ans;
const int inf = 9999099;

int main()
{
    memset(visited, -1, sizeof(visited));
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 5; j++)
                scanf("%d", &array[j][i]);

        if(k >= 5 || n == k)
            ans = greedy_fn();
        else
            ans = fn(0, k, 0, 0, 0);
        printf("%d", ans);

        printf("\n");
    }

    return 0;
}

int fn(int i, int left, int mask, int p_msk, int taken)
{
    if(mask == 31)
        return 0;

    if(i == n || left < 0)
        return -1 * inf;

    int& flag = visited[i][left][mask][p_msk][taken];
    int& ret = dp[i][left][mask][p_msk][taken];
    if(flag == cases)
        return ret;
    flag = cases, ret = -1 * inf;

    if(p_msk == 5)
        ret = fn(i + 1, left, mask, 0, 0);// printf("hhhh %d\n", i);
    else
    {
        ///Don't take
        ret = max(ret, fn(i, left, mask, p_msk + 1, taken));

        ///take
        int left_f = 1;//taken == 1 ? 0 : 1;
        if(taken == 1)
            left_f = 0;
        if(left - left_f >= 0 && !getbit(mask, p_msk)) ///nxt place in msk
            ret = max(ret, array[p_msk][i] + fn(i, left - left_f, setbit(mask, p_msk, 1), p_msk + 1, 1));
    }

    return ret;
}

int greedy_fn()
{
    int tmp[5], ret = 0;
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 5; j++)
            tmp[j] = max(tmp[j], array[j][i]);

    for(int i = 0; i < 5; i++)
        ret += tmp[i];
    return ret;
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}
