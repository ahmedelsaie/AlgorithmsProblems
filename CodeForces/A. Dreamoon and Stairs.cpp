#include <iostream>
#include <stdio.h>
using namespace std;

int fn();
int num, steps;

int main()
{
    scanf("%d %d", &steps, &num);
    printf("%d\n", fn());
    return 0;
}

int fn()
{
    ///10 2
    int small, big;
    big = steps / 2, small = steps % 2;
    int tmp = (big + small) % num;

    while(big >= 0)
    {
        if((big + small) % num == 0)
            return big + small;
        big--;
        small += 2;
    }

    return -1;
}
