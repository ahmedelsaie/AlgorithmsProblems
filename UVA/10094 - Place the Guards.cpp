#include <stdio.h>

void fn();
void fn2();
void fn3();
int check();

int n;
int main()
{
    int x;
    while(scanf("%d", &n) != EOF)
    {
        if(n < 4)
            printf("Impossible");
        else
        {
            x = check();
            if(x == 1)
                fn();
            else if(x == 2)
                fn2();
            else if(x == 3)
                fn3();
        }
        printf("\n");
    }

    return 0;
}

void fn()
{
    for(int i = 2; i <= n; i += 2)
        printf("%d ", i);

    for(int i = 1; i <= n; i += 2)
    {
        if(i > 1)
            printf(" ");
        printf("%d", i);
    }
    return ;
}

void fn2()
{
    //  20
    // 17 15 13 11 9 7 5 3 1 19  14 12 10 8 6 4 2 20 18 16
    for(int i = n - 3; i >= 1; i -= 2)
    {
        if(i != n - 3)
            printf(" ");
        printf("%d", i);
    }
    printf(" %d", n - 1);

    for(int i = n - 6; i >= 2; i -= 2)
        printf(" %d", i);

    for(int i = n; i >= n - 4; i -= 2)
        printf(" %d", i);
    return ;
}

void fn3()
{
    // 9
    // 6 4 2 8  5 3 1 9 7
    for(int i = n - 3; i >= 1; i -= 2)
    {
        if(i != n - 3)
            printf(" ");
        printf("%d", i);
    }
    printf(" %d", n - 1);

    for(int i = n - 4; i > 0; i -= 2)
        printf(" %d", i);

    printf(" %d %d", n, n - 2);

    return ;
}

int check()
{
    for(int i = 8; i <= n; i += 6)
    {
        if(n == i)
            return 2;
        if(n == i + 1)
            return 3;
    }
    return 1;
}
