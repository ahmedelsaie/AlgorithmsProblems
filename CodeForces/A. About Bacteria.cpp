#include <stdio.h>


int main()
{
    long long k, b, n, t;

    scanf("%lld %lld %lld %lld", &k, &b, &n, &t);

    long long x = 1;
    int sec = 0;

    while(x <= t)
    {
        x = k * x + b;
        sec++;
    }

    if(n - sec + 1 <= 0)
        printf("0");
    else
        printf("%lld", n - sec + 1);

    return 0;
}
