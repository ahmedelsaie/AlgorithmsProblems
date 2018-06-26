#include <stdio.h>
int fn(int x);

int main()
{
    int x;
    while(scanf("%d", &x) != EOF)
    {
        printf("%d\n", fn(x));
    }
    return 0;
}

int fn(int x)
{
    int ans = x;
    int borrow = 0;
    while(x >= 2)
    {
        if(x % 3 != 0)
        {
            if(x > 2)
            {
                borrow = 3 - (x % 3);
                x = x + borrow;
            }
            else
            {
                borrow = 1;
                x = x + 1;
            }
        }
        ans = ans + x / 3;
        x = x / 3 - borrow;
        borrow = 0;
    }
    return ans;
}



