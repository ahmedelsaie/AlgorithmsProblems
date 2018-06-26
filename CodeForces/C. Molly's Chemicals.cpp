#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

ll fn(ll x);
ll bin_search(ll x, ll b);
ll compress();
void decrease(ll x);

ll n, arr[MAX], cnt[MAX], val[MAX], k, n_val;

int main()
{
    scanf("%lld %lld", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    ll ret = 0;

    if(k >= 0)
    {
        ll m = 100000000000000, curr = 1;

        while(curr <= m)
        {
            ret += fn(curr);
            curr *= k;

            if(curr * k == curr)
                break;
        }
    }
    else
    {
        ll m = 100000000000009, curr = 1;

        while(curr <= m)
        {
            ret += fn(curr);

            curr *= k * k;
            if(curr == 1)
                break;
        }

        m = -100000000000009, curr = k;

        while(curr >= m)
        {
            ret += fn(curr);
            curr *= k * k;
            if(curr == -1)
                break;
        }
    }

    printf("%lld\n", ret);

    return 0;
}

ll fn(ll x)
{
    ll accum = 0;
    for(int i = 0; i < n; i++)
    {
        accum += arr[i];
        val[i] = accum;
    }

    n_val = compress();

    ll ret = 0;

    accum = 0;

    for(int i = 0; i < n; i++)
    {
        ret += bin_search(x + accum, n_val);

        accum += arr[i];
        decrease(accum);
    }

    return ret;
}

void decrease(ll x)
{
    ll s = 0, b = n_val;

    while(b >= s)
    {
        ll mid = (b + s) / 2;

        if(val[mid] == x)
        {
            cnt[mid]--;
            return;
        }

        if(val[mid] > x)
            b = mid - 1;
        else
            s = mid + 1;
    }
}

ll bin_search(ll x, ll b)
{
    ll s = 0;

    while(b >= s)
    {
        ll mid = (b + s) / 2;

        if(val[mid] == x)
            return cnt[mid];

        if(val[mid] > x)
            b = mid - 1;
        else
            s = mid + 1;
    }

    return 0;
}

ll compress()
{
    sort(val, val + n);

    memset(cnt, 0, sizeof(cnt));

    ll i = 0, prev = val[0], c = 0, j = 0;

    while(i < n)
    {
        if(prev == val[i])
            c++;
        else
        {
            val[j] = prev;
            cnt[j++] = c;
            prev = val[i];
            c = 1;
        }

        i++;
    }

    val[j] = prev;
    cnt[j++] = c;

    return j;
}


