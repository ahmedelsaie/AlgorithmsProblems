#include <stdio.h>

int abs(int x);
int fn();

int x1, x2, y1, y2;

int main()
{
    while(true)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
            break;
        printf("%d\n", fn());
    }
    return 0;
}

int fn()
{
    if(x1 == x2 && y1 == y2)
        return 0;

    if(x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))
        return 1;

    return 2;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
