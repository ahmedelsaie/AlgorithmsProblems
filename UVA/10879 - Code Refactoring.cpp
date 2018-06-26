#include <stdio.h>

void fn(int x);

int first, sec, third, fourth;

int main()
{
    int cases, x;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%d", &x);
        fn(x);
        printf("Case #%d: %d = %d * %d = %d * %d\n", i + 1, x, first, sec, third, fourth);
    }
    return 0;
}


void fn(int x)
{
    int r = 2;
    int flag = 0;
    while(flag < 2)
    {
        if(x % r == 0)
        {
            if(flag == 0)
            {
                first = r;
                sec = x / r;
            }
            else
            {
                third = r;
                fourth = x / r;
            }
            flag++;
        }
        r++;
    }

    return ;
}
