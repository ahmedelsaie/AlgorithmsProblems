#include <bits/stdc++.h>
using namespace std;
#define MAX 5005
#define ll long long


int main()
{
    ll x;
    scanf("%lld", &x);

    ll ans = x / 3 * 2;
    ans += (x % 3 != 0);

    printf("%lld\n", ans);

    return 0;
}
