#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b);


int main()
{
    ll r,l;
    scanf("%lld %lld", &l, &r);
    for(ll a = l; a <= r; a++)
        for(ll b = a + 1; b <= r; b++)
            if(gcd(a, b) == 1)
                for(ll c = b + 1; c <= r; c++)
                {
                    if(gcd(b, c) == 1 && gcd(a, c) != 1)
                    {
                        printf("%lld %lld %lld\n", a, b, c);
                        return 0;
                    }
                }
                printf("-1\n");
    return 0;
}

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
