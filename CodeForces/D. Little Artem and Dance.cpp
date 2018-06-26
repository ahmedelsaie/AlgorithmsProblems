#include <bits/stdc++.h>
using namespace std;
#define MAX 2000009
#define ll long long

void fn();

ll q[2][MAX], arr[MAX], n, m, arr2[MAX];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%lld", &q[0][i]);
        if(q[0][i] == 1)
            scanf("%lld", &q[1][i]);
    }

    fn();

    for(int i = 0; i < n; i++)
        printf("%lld ", arr2[i]);

    return 0;
}

void fn()
{
    ll steps = 0, odd = 0, total = 0;

    for(ll i = 0; i < m; i++)
    {
        if(q[0][i] == 1)
        {
            total += q[1][i];

            if(total < 0)
                total = (total + n) % n;
            else
                total = total % n;

            if(q[1][i] % 2 != 0)
                odd = (!odd);
        }
        else
        {
            if(odd == 0)
                steps++;
            else
                steps--;

            if(steps < 0)
                steps = (steps + n) % n;
            else
                steps = steps % n;

            odd = (!odd);
        }
    }

    for(ll i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            ll tmp = steps + i;
            if(tmp < 0)
                tmp = (tmp + n) % n;
            else
                tmp = tmp % n;

            arr[tmp] = i + 1;
        }
        else
        {
            ll tmp = -steps + i;
            if(tmp < 0)
                tmp = (tmp + n) % n;
            else
                tmp = tmp % n;

            arr[tmp] = i + 1;
        }
    }

    for(ll i = 0; i < n; i++)
    {
        ll tmp = total + i;
        if(tmp < 0)
            tmp = (tmp + n) % n;
        else
            tmp = tmp % n;

        arr2[tmp] = arr[i];
    }
}
