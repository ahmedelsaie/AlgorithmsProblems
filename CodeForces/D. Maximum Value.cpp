#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define MAX 1000009

void pre_process();
int fn();

int array[MAX + 2];

int n, x;

int main()
{
    memset(array, 0, sizeof(array));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &x), array[x] = x;

    printf("%d\n", fn());

    return 0;
}

int fn()
{
    array[0] = array[1] = 1;
    for(int i = 2; i <= MAX; i++)
        if(array[i] != i)
            array[i] = array[i - 1];

    int ret = 0, j;
    for(int i = 1; i <= MAX; i++)
    {
        if(array[i] == i)
            for(j = i - 1; j <= MAX; j += i)
                if (i <= array[j] && ret < array[j] % i)
                    ret = array[j] % i;
                else if (i > array[j] && ret < i % array[j])
                    ret = i % array[j];

        if(array[MAX] != 0 && array[i] == i)
            if (i <= array[MAX] && ret < array[MAX] % i)
                ret = array[MAX] % i;
            else if (i > array[MAX] && ret < i % array[MAX])
                ret = i % array[MAX];
    }

    return ret;
}
