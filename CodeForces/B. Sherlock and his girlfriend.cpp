#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009
#define ll long long
int sieve();
int numPF(ll x);

bool v[MAX];
int primes[MAX], arr_fac[100], n_primes;
int colors[MAX];
int fn();
int n;

int main()
{
    scanf("%d",&n);

    printf("%d\n", fn());
    for(int i = 2; i <= n+1; i++)
        printf("%d ", colors[i]);

    printf("\n");

    return 0;
}

int fn()
{
    memset(colors, -1, sizeof(colors));
    n_primes = sieve();
    int f1 = 0, f2 = 0;

    for(int i = 2; i <= n+1; i++)
    {
        if(v[i] == 0)
            colors[i] = 1, f1 = 1;
        else
            colors[i] = 2, f2 = 1;
    }

    return f1 + f2;
}

int sieve()
{
    memset(v, 0, sizeof(v));
    v[0] = v[1] = 1;
    long long i, j;

    // Sieve of Eratosthenes
    for (i = 2; i * i < 1000000; i++)
    {
        if (!v[i])
        {
            for (j = i * i; j < 1000000; j += i)
            {
                v[j] = 1;
            }
        }
    }

    int index = 0;
    for (i = 2; i < 1000000; i++)
    {
        if (!v[i])
        {
            primes[index++] = i;
        }
    }

    return index;
}

int numPF(ll x)   // Count the number of prime factors of N
{
    if(x == 1)
        return 1;

    int i = 0, ret = 0;

    ll pf = primes[i++];

    while (x != 1 && i < n_primes && x >= pf * pf) // && pf * pf <= N)
    {
        int cnt = 0;
        while (x % pf == 0)
        {
            x /= pf;
            cnt++;
        }

        if(cnt)
            arr_fac[ret++] = pf;

        pf = primes[i++];
    }

    if (x != 1)
        arr_fac[ret++] = x;

    return ret;
}
