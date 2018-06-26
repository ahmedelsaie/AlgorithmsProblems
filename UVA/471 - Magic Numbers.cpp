#include <stdio.h>

bool check(long long x, long long y);
void fn();

long long n;

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%lld", &n);
        if(i > 0)
            printf("\n");
        fn();
    }
    return 0;
}

void fn()
{
    bool flag = true;
    long long max_n = 9876543210;
    long long temp = n;

    for(int i = 1; temp <= max_n ; i++)
    {
        temp = i * n;
        if(check(i, temp))
            printf("%lld / %d = %lld\n", temp, i, n);
    }
}

bool check(long long x, long long y)
{
    int help;
    bool ref[10];
    for(int i = 0; i < 10; i++)
        ref[i] = true;
    while(x)
    {
        help = x % 10;
        if(ref[help])
            ref[help] = false;
        else
            return false;
        x = x / 10;
    }

    for(int i = 0; i < 10; i++)
        ref[i] = true;
    while(y)
    {
        help = y % 10;
        if(ref[help])
            ref[help] = false;
        else
            return false;
        y = y / 10;
    }
    return true;
}
