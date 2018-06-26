#include <stdio.h>
#include <math.h>
bool fn();
long long x;

int main()
{
    while(true)
    {
        scanf("%lld", &x);
        if(x == 0)
            break;

        if(fn())
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

bool fn()
{
    long long y = x;
    y = sqrt(y);
    if(y * y == x)
        return true;
    else
        return false;
}
