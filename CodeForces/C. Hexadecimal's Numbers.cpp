#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 10009

void fn(int i, int left, int one);

int array[MAX], x = 0, accum[15], y, ret = 0;

int main()
{
    for(int i = 1; i <= 10; i++)
        accum[0] = 1, fn(1, i - 1, 1);
    scanf("%d", &y);

    int i = 0;
    while(array[i] <= y && i < 10000)
        ret++, i++;

    printf("%d\n", ret);

    return 0;
}

void fn(int i, int left, int one)
{
    if(left == 0)
    {
        int ret = 0;
        if(one)
        {
            for(int j = 0; j < i; j++)
                ret = ret * 10 + accum[j];
            array[x] = ret, x++;
        }
        return;
    }

    accum[i] = 0;
    fn(i + 1, left - 1, one);

    accum[i] = 1;
    fn(i + 1, left - 1, 1);

    return;
}




