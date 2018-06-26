#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int fn(int level, int num, int start, int end, bool mode, int i);

int dp[18][1 << 17 + 1], array[1 << 17], n, m, change = -1, x, y;

int main()
{
    int op = 1;

    memset(dp, -1, sizeof(dp));

    scanf("%d %d", &n, &m);
    if(n % 2 == 0)
        op = 0;

    for(int i = 0; i < (1 << n); i++)
        scanf("%d", &array[i]);

    int t = n;
    n = (1 << n);
    fn(n, 0, 0, n, op, t);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        x--;
        array[x] = y;
        change = x;
        printf("%d\n", fn(n, 0, 0, n, op, t));
    }


    return 0;
}

int fn(int level, int num, int start, int end, bool mode, int i)
{
    if(end == start + 1)
        return array[start];

    int& ret = dp[i][num];
    if(ret != -1 && !(change >= start && change < end))
        return ret;

    ret = fn(level / 2, start / (level / 2), start, (start + end) / 2, !mode, i - 1);
    int tmp = fn(level / 2, (end - 1) / (level / 2), (start + end) / 2, end, !mode, i - 1);

    if(mode)
        ret = ret | tmp;
    else
        ret = ret ^ tmp;

    return ret;
}
