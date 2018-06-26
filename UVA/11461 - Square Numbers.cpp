#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 100009

int array[MAX];
void fn();

int main()
{
    int small, big;
    fn();
    while(true)
    {
        scanf("%d %d", &small, &big);
        if(big + small == 0)
            break;
        printf("%d\n", array[big] - array[small - 1]);
    }

    return 0;
}

void fn()
{
    memset(array, 0, sizeof(array));
    for(int i = 1; i * i < MAX && i > 0; i++)
        array[i * i]++;

    int accum = 0;
    for(int i = 0; i < MAX; i++)
        accum += (array[i] == 1), array[i] = accum;
}
