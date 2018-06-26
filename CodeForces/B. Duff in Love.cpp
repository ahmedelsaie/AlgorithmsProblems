#include <bits/stdc++.h>
using namespace std;
#define MAX 10000009
#define ll long long

int sieve();
ll numPF(long long N) ;  // Count the number of prime factors of N

bool v[MAX];
ll primes[10000009], x;
int p, t = 0;
pair<ll, int> array[MAX];

int main()
{
    p = sieve();
    scanf("%lld", &x);
    numPF(x);

    int tmp;
    ll ans = 1;
    for(int i = 0; i < t; i++)
    {
        ans *= array[i].first;
    }

    printf("%lld\n", ans);

    return 0;
}

int sieve()
{
    memset(v, 0, sizeof(v));
    v[0] = v[1] = 1;
    long long i, j;

    // Sieve of Eratosthenes
    for (i = 2; i * i < 10000001; i++)
    {
        if (!v[i])
        {
            for (j = i * i; j < 10000001; j += i)
            {
                v[j] = 1;
            }
        }
    }

    int index = 0;
    for (i = 2; i < 10000001; i++)
    {
        if (!v[i])
        {
            primes[index++] = i;
        }
    }

    return index;
}

ll numPF(long long N)   // Count the number of prime factors of N
{
    if(N == 1)
        return 2;
    int indx = 0;
    ll counter = 0;
    ll ret = 0;
    int index = 0;
    ll tmp;
    long long pf = primes[index++];
    int fact = 0;

    while (N != 1 && index < p )//&& N > pf * pf) // && pf * pf <= N)
    {
        tmp = 1;
        counter = 0;
        while (N % pf == 0)
        {
            N /= pf;

            tmp *= pf;
            counter++;
        }

        if(counter)
        {
            ret += tmp, fact++;
            array[t].first = pf, array[t].second = counter, t++;
        }

        pf = primes[index++];
    }

    if (N != 1)
    {
        ret += N, fact++;
        array[t].first = N, array[t].second = 1, t++;

    }

    if (fact == 1)
        ret++;

    return ret;
}
