#include <stdio.h>

long long get_price(long long watt);
long long get_watt(long long price);
long long check(long long x);
long long fn();
long long abs(long long x);

long long total_watt;
long long A, B;

int main()
{
    long long ans;
    bool flag = true;

    while(true)
    {
        scanf("%lld %lld", &A, &B);

        if(A == 0 && B == 0)
            break;

        total_watt = get_watt(A);
        ans = fn();

        if(total_watt - ans > ans)
            printf("%lld\n", get_price(ans));
        else
        {
            ans = total_watt - fn();
            printf("%lld\n", get_price(ans));
        }
    }

    return 0;
}

long long fn()
{
    long long big, small, mid;
    small = 0;
    big = total_watt;

    while(big >= small)
    {
        mid = big - small;
        mid = small + .5 * mid;

        if(check(mid) == 0)
            return mid;

        if(check(mid) > 0)
            big = mid - 1;

        else
            small = mid + 1;
    }

    return mid;
}

long long check(long long x)
{
    long long y = total_watt - x;
    long long x_price = get_price(x);
    long long y_price = get_price(y);

    if(abs(x_price - y_price) == B)
        return 0;

    if(abs(x_price - y_price) > B)
        return 1;

    return -1;
}

long long get_price(long long watt)
{
    if(watt >= 1 && watt <= 100)
        return 2 * watt;

    if(watt >= 101 && watt <= 10000)
        return (2 * 100) + (3 * (watt - 100));

    if(watt >= 10001 && watt <= 1000000)
        return (2 * 100) + (3 * 9900) + (5 * (watt - 100 - 9900));

    if(watt > 1000000)
        return (2 * 100) + (3 * 9900) + (5 * 990000) + 7 * (watt - 100 - 9900 - 990000);
}

long long get_watt(long long price)
{
    if(price <= 200)
        return price / 2;

    if(price <= (2 * 100) + (3 * 9900))
        return (100) + ((price - 200) / 3);

    if(price <= (2 * 100) + (3 * 9900) + (5 * 990000))
        return (100) + (9900) + ((price - 200 - 29700) / 5);

    return (100) + (9900) + (990000) + ((price - 200 - 29700 - 4950000) / 7);

}

long long abs(long long x)
{
    if(x >= 0)
        return x;
    else
        return -1 * x;
}
