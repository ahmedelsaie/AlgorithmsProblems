#include <stdio.h>

int abs(int x);
int cnt_digit(int x);
void print();
void fn();
int min(int x, int y);
int gcd(int x, int y);

int a, b, c;
bool neg;

int main()
{
    int x;
    int cases = 1;
    while(true)
    {
        b = 0;
        scanf("%d", &c);

        if(c == 0)
            break;

        for(int i = 0; i < c; i++)
        {
            scanf("%d", &x);
            b = b + x;
        }
        printf("Case %d:\n", cases);
        fn();
        printf("\n");

        cases++;

    }
    return 0;
}

void fn()
{
    if(b < 0)
        neg = true;
    else
        neg = false;

    b = abs(b);

    a = b / c;
    b = b % c;


    int t = gcd(c, b);

    if(t != -1)
    {
        b = b / t;
        c = c / t;
    }

    print();
}

void print()
{
    if(b == 0)
    {
        if(neg)
            printf("- ");
        printf("%d", a);
        return;
    }

    int a_n = cnt_digit(a);
    int b_n = cnt_digit(b);
    int c_n = cnt_digit(c);

    if(a > 0)
    {
        int spaces = 0;
        spaces = spaces + a_n;
        if(neg)
            spaces += 2;
        spaces += c_n;
        spaces -= b_n;

        for(int i = 0; i < spaces; i++)
            printf(" ");
        printf("%d\n", b);

        if(neg)
            printf("- ");
        printf("%d", a);

        for(int i = 0; i < c_n; i++)
            printf("-");
        printf("\n");

        spaces = a_n;
        if(neg)
            spaces += 2;

        for(int i = 0; i < spaces; i++)
            printf(" ");
        printf("%d", c);
        return ;
    }
    else
    {
        int spaces = 0;
        if(neg)
            spaces += 2;
        spaces += c_n;
        spaces -= b_n;

        for(int i = 0; i < spaces; i++)
            printf(" ");
        printf("%d\n", b);

        if(neg)
            printf("- ");


        for(int i = 0; i < c_n; i++)
            printf("-");
        printf("\n");

        spaces = 0;
        if(neg)
            spaces += 2;

        for(int i = 0; i < spaces; i++)
            printf(" ");
        printf("%d", c);
        return ;
    }
}

int gcd(int x, int y)
{
    int s = min(x, y);

    for(int i = s; i >= 1; i--)
        if(x % i == 0 && y % i == 0)
            return i;
    return -1;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int cnt_digit(int x)
{
    int n = 0;
    while(x != 0)
    {
        x = x / 10;
        n++;
    }
    return n;
}


int abs(int x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
