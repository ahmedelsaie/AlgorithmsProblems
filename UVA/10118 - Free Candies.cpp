#include <stdio.h>
#include <cstring>
#define MAX 45

struct stack
{
    int arr[5];
    int l;
};

stack update(stack curr, int x);
int fn(int x1, int x2, int x3, int x4, stack can, int left, int accum_stack);
int max(int x, int y);

int n;
const int inf = 9999999;
int dp[MAX][MAX][MAX][MAX];
int arr1[MAX];
int arr2[MAX];
int arr3[MAX];
int arr4[MAX];

int main()
{
    int ans;
    stack temp;
    temp.l = 0;
    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d %d %d %d", &arr1[i], &arr2[i], &arr3[i], &arr4[i]);

        memset(dp, -1, sizeof(dp));
        ans = fn(0, 0, 0, 0, temp, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}

int fn(int x1, int x2, int x3, int x4, stack can, int left, int accum_stack)
{
    if(accum_stack == 5)
        return 0;

    if(left == 4 * n)
        return 0;

    int &ret = dp[x1][x2][x3][x4];
    if(ret != -1)
        return ret;

    ret = -1 * inf;
    stack new_can;
    int got;

    if(x1 < n)
    {
        got = 0;
        new_can = can;
        new_can = update(can, arr1[x1]);
        if(new_can.l < can.l)
            got = 1;
        ret = max(ret, fn(x1 + 1, x2, x3, x4, new_can, left + 1, new_can.l) + got);
    }

    if(x2 < n)
    {
        got = 0;
        new_can = can;
        new_can = update(can, arr2[x2]);
        if(new_can.l < can.l)
            got = 1;
        ret = max(ret, fn(x1, x2 + 1, x3, x4, new_can, left + 1, new_can.l) + got);
    }

    if(x3 < n)
    {
        got = 0;
        new_can = can;
        new_can = update(can, arr3[x3]);
        if(new_can.l < can.l)
            got = 1;
        ret = max(ret, fn(x1, x2, x3 + 1, x4, new_can, left + 1, new_can.l) + got);
    }

    if(x4 < n)
    {
        got = 0;
        new_can = can;
        new_can = update(can, arr4[x4]);
        if(new_can.l < can.l)
            got = 1;
        ret = max(ret, fn(x1, x2, x3, x4 + 1, new_can, left + 1, new_can.l) + got);
    }

    return ret;
}

stack update(stack curr, int x)
{
    bool flag = false;
    int j;

    for(int i = 0; i < curr.l; i++)
        if(curr.arr[i] == x)
        {
            flag = true;
            j = i;
            break;
        }

    if(flag)
    {
        for(int i = j; i < curr.l; i++)
            curr.arr[i] = curr.arr[i + 1];
        curr.l--;
    }
    else
    {
        curr.arr[curr.l] = x;
        curr.l++;
    }
    return curr;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
