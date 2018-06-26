#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int fn();
int remove(int x);

int array[105], array2[105], n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("%d\n", fn());
    return 0;
}

int fn()
{
    int ret = 999999;
    for(int i = 1; i < n - 1; i++)
        ret = min(ret, remove(i));
    return ret;
}

int remove(int x)
{
    int ret = 0;
    int j = 0;
    for(int i = 0; i < n; i++)
        if(i != x)
            array2[j] = array[i], j++;

    for(int i = 1; i < j; i++)
        ret = max(ret, abs(array2[i] - array2[i - 1]));
    return ret;
}
