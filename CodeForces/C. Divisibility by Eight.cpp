#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 105

void trace(int i, int mod, int taken);
int fn(int i, int mod, int taken);

char input[MAX];
int array[MAX], dp[MAX][10][2],n;

int main()
{
    scanf("%s", input);
    n = strlen(input);

    for(int i = 0; i < n; i++)
        array[i] = input[i] - '0';


    for(int i = 0; i < n; i++)
        if(array[i] == 0)
        {
            printf("YES\n0\n");
            return 0;

        }

    memset(dp, -1, sizeof(dp));
int    ans = fn(0, 0, 0);
    if(ans)
        printf("YES\n"), trace(0, 0, 0), printf("\n");
    else
        printf("NO\n");

    return 0;
}

void trace(int i, int mod, int taken)
{
    if(i == n)
        return ;

    if(dp[i + 1][mod][taken] == 1)
        trace(i + 1, mod, taken);

    else if(taken && dp[i + 1][((mod * 10) + array[i]) % 8][taken])
    printf("%d", array[i]), trace(i + 1, ((mod * 10) + array[i]) % 8, taken);

    else if(taken == 0 && array[i] != 0 && dp[i + 1][((mod * 10) + array[i]) % 8][1])
        printf("%d", array[i]), trace(i + 1, ((mod * 10) + array[i]) % 8, 1);

    return ;
}

int fn(int i, int mod, int taken)
{
    int& ret = dp[i][mod][taken];
    if(ret != -1)
        return ret;
    ret = 0;

    if(i == n)
    {
        ret = mod == 0 && taken == 1;
        return ret;
    }

    ret = ret | fn(i + 1, mod, taken);

    if(taken)
        ret = ret | fn(i + 1, ((mod * 10) + array[i]) % 8, taken);

    if(taken == 0 && array[i] != 0)
        ret = ret | fn(i + 1, ((mod * 10) + array[i]) % 8, 1);

    return ret;
}
