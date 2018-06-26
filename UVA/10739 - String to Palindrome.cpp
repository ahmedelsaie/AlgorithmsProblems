#include <stdio.h>
#include <cstring>

int fn(int left, int right);
void reset();

char arr[1005];
int dp[1005][1005];
int length;

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        scanf("%s", arr);
        length = strlen(arr);
        reset();
        printf("Case %d: %d\n", i + 1, fn(0, length - 1));
    }

    return 0;
}

void reset()
{
    for(int i = 0; i < length; i++)
        for(int j = 0; j < length; j++)
            dp[i][j] = -1;
}

int fn(int left, int right)
{
    if(right <= left)
        return 0;

    int &ret = dp[left][right];
    if(ret != -1)
        return ret;

    int x1, x2, x3, max;
    x1 = fn(left + 1, right - 1) + (arr[left] != arr[right]);
    x2 = fn(left + 1, right) + 1;
    x3 = fn(left, right - 1) + 1;
    max = x1;

    if(x2 < max)
        max = x2;

    if(x3 < max)
        max = x3;

    return ret = max;
}

