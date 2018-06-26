#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 105

int pigeon();
int pigeon2(int msk);

int array[MAX][MAX], help[MAX][MAX], row, col, k;

int main()
{
    scanf("%d %d %d", &row, &col, &k);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            scanf("%d", &array[i][j]);

    ///rotate
    if(col > row)
    {
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                help[col - j - 1][i] = array[i][j];

        swap(row, col);

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                array[i][j] = help[i][j];
    }

    int ans = 9999999;

    if(row <= k)
    {
        for(int i = 0; i < (1 << col); i++)
            ans = min(ans, pigeon2(i));//, printf("dds %d )%d\n", i,pigeon2(i));
    }
    else
        ans = pigeon();

    printf("%d\n", ans <= k ? ans : -1);

    return 0;
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}

int pigeon2(int msk)
{
    int ret = 0, tmp, tmp2;

    for(int i = 0; i < row; i++)
    {
        tmp = 0;
        for(int k = 0; k < col; k++)
            if(getbit(msk, k) != array[i][k])
                tmp++;

        tmp2 = tmp;
        tmp = 0;
        for(int k = 0; k < col; k++)
            if(getbit(msk, k) == array[i][k])
                tmp++;

        tmp2 = min(tmp2, tmp);
        ret += tmp2;
    }

    return ret;
}

int pigeon()
{
    int tmp = 0, ret = 9999999, ans, tmp2;

    for(int i = 0; i < row; i++)
    {
        ans = 0;
        for(int j = 0; j < row; j++)
        {
            tmp = 0;
            for(int k = 0; k < col; k++)
                if(array[j][k] != array[i][k])
                    tmp++;

            tmp2 = tmp;

            tmp = 0;
            for(int k = 0; k < col; k++)
                if(array[j][k] == array[i][k])
                    tmp++;

            tmp2 = min(tmp2, tmp);
            ans += tmp2;
        }

        ret = min(ret, ans);
    }

    return ret;
}

