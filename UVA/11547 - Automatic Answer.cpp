#include <stdio.h>

int abs(int x);

int main()
{
    int cases, x;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%d", &x);
        x = x * 567;
        x = x / 9;
        x = x + 7492;
        x = x * 235;
        x = x / 47;
        x = x - 498;
        x = x / 10;
        x = x % 10;
        x = abs(x);
        printf("%d\n", x);

    }
    return 0;
}

int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
