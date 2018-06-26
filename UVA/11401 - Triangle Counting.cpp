#include <stdio.h>
#include <cstring>

void fn();

unsigned long long array[1000009];

int main()
{
    int x;
    fn();

    while(true)
    {
        scanf("%d", &x);
        if(x < 3)
            break;
        printf("%llu\n", array[x]);
    }

    return 0;
}

void fn()
{
    unsigned long long prev = 3;
    unsigned long long x = 1, y = 2;
    bool flag = true;
    array[3] = 0;
    array[4] = 1;
    array[5] = 3;

    for(int i = 6; i <= 1000000; i++)
    {
        if(flag)
            x++;
        else
            y++;

        array[i] = prev + x * y;
        prev = array[i];

        flag = !flag;
    }

    return ;
}
