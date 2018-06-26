#include <stdio.h>
#include <cstring>

int fn(int c1, int c2, int c3, int c4, int c5, int c6, int accum);
int min(int x, int y);
int pre_process();

const int inf = 99;
int dp[5][5][5][5][5][5][32];
char input[60];

int main()
{
    memset(dp, -1, sizeof(dp));
    while(gets(input))
    {
        printf("%s ", input);
        if(pre_process() == 1)
            printf("A");
        else
            printf("B");

        printf("\n");
    }

    return 0;
}

int pre_process()
{
    int l = strlen(input);
    int array[7];
    int accum = 0;
    memset(array, 0, sizeof(array));
    for(int i = 0; i < l; i++)
    {
        int temp = input[i] - '0';
        accum += temp;
        array[temp]++;
    }

    int ret = 0 - fn(4 - array[1], 4 - array[2], 4 - array[3], 4 - array[4], 4 - array[5], 4 - array[6], accum);
    if(l % 2 == 0)
    {
        if(ret > 0)
            return 1;
        else
            return 2;
    }
    else
    {
        if(ret < 0)
            return 1;
        else
            return 2;
    }

}

int fn(int c1, int c2, int c3, int c4, int c5, int c6, int accum)
{
    if(accum > 31)
        return -1 * inf;

    int &ret = dp[c1][c2][c3][c4][c5][c6][accum];
    if(ret != -1)
        return ret;
    ret = inf;
    int temp;


    if(c1 > 0)
    {
        temp = 0 - fn(c1 - 1, c2, c3, c4, c5, c6, accum + 1);
        ret = min(ret, temp);
    }

    if(c2 > 0)
    {
        temp = 0 - fn(c1, c2 - 1, c3, c4, c5, c6, accum + 2);
        ret = min(ret, temp);
    }

    if(c3 > 0)
    {
        temp = 0 - fn(c1, c2, c3 - 1, c4, c5, c6, accum + 3);
        ret = min(ret, temp);
    }

    if(c4 > 0)
    {
        temp = 0 - fn(c1, c2, c3, c4 - 1, c5, c6, accum + 4);
        ret = min(ret, temp);
    }

    if(c5 > 0)
    {
        temp = 0 - fn(c1, c2, c3, c4, c5 - 1, c6, accum + 5);
        ret = min(ret, temp);
    }

    if(c6 > 0)
    {
        temp = 0 - fn(c1, c2, c3, c4, c5, c6 - 1, accum + 6);
        ret = min(ret, temp);
    }

    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}
