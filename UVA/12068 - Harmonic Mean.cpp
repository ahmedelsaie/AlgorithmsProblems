#include <stdio.h>

void fn();
long long min(long long x, long long y);
long long GCD(long long a, long long b);

int array[150];
long long n, num, den;

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++)
    {
        scanf("%lld", &n);
        for(int j = 0; j < n; j++)
            scanf("%d", &array[j]);
        fn();
        long long r = GCD(num, den);

        if(r != -1)
        {
            num = num / r;
            den = den / r;
        }

        printf("Case %d: %lld/%lld\n", i + 1, num, den);
    }

    return 0;
}

long long GCD(long long a, long long b)
{
    return !b ? a : GCD(b, a % b);
}

long long min(long long x, long long y)
{
    if(x < y)
        return x;
    else
        return y;
}

void fn()
{
    num = n;
    den = 0;
    long long accum = 1;

    for(int i = 0; i < n; i++)
        accum = accum * array[i];

    num = num * accum;

    for(int i = 0; i < n; i++)
        den = den + accum / array[i];
    return;
}
