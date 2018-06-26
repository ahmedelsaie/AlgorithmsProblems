#include <stdio.h>
#include <cstring>

int max(int x, int y);
int fn(int x, int y);
void reset();

int dp[1005][1005];
int l1, l2;
char array1[1005];
char array2[1005];

int main()
{
    while(gets(array1))
    {
        gets(array2);
        l1 = strlen(array1);
        l2 = strlen(array2);
        reset();
        printf("%d\n", fn(0, 0));
    }
    return 0;
}

int fn(int x, int y)
{
    if(x == l1 || y == l2)
        return 0;

    int &ret = dp[x][y];
    if(ret != -1)
        return ret;

    if(array1[x] == array2[y])
        return ret = fn(x + 1, y + 1) + 1;

    int choice1 = fn(x + 1, y);
    int choice2 = fn(x, y + 1);
    return ret = max(choice1, choice2);
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
    for(int i = 0; i < l1 + 2; i++)
        for(int j = 0; j < l2 + 2; j++)
            dp[i][j] = -1;
}
