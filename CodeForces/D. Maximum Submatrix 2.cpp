#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 5005

int fn();

int array[MAX][MAX], sorted[MAX][MAX], n, m;
char input[MAX];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", input);
        for(int j = 0; j < m; j++)
            array[i][j] = input[j] - '0';
    }


    memset(sorted, 0, sizeof(sorted));
    printf("%d\n", fn());

    return 0;
}

int fn()
{
    int ret = 0, big = 0, with = 0;

    ///pre_process
    for(int i = 0; i < n; i++)
    {
        array[i][m] = 0;
        for(int j = m - 1; j >= 0; j--)
        {
            if(array[i][j])
                array[i][j] = array[i][j + 1] + 1, big = max(big, array[i][j]);
            else
                array[i][j] = 0;

            sorted[j][array[i][j]]++;
        }
    }

    ///search
    for(int j = 0; j < m; j++)
    {
        with = 0;
        for(int i = big; i >= 1; i--)
        {
            ret = max(ret, sorted[j][i] * i);
            with += sorted[j][i];
            ret = max(ret, with * i);
        }
    }

    return ret;
}
