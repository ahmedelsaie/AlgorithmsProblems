#include <bits/stdc++.h>
using namespace std;
#define MAX 20000000
#define ll long long

ll fn();

ll start, end1, k;

int main()
{
    int cases = 1;

    while(true)
    {
        scanf("%lld %lld %lld", &start, &end1, &k);
        if(start + end1 + k == 0)
            break;

        printf("Case %d: %lld\n", cases++, fn());
    }

    return 0;
}

ll fn()
{
    ll total_len = end1- start + 1;
    ll ret = 0;
    ll con = (k * (k - 1)) / 2;

    for(ll s = 2; s * (k - 1) <= total_len; s += 2)
    {
        int length = s * (k - 1);
        ret += total_len - length;
    }

    ll k2 = k * k;
    for(ll s = 1; s * (k - 1) <= total_len; s += 2)
    {
        if(s * k2 & 1 && s * k & 1)
        {
            int length = s * (k - 1);
            ret += total_len - length;
        }
    }

    return ret;
}
