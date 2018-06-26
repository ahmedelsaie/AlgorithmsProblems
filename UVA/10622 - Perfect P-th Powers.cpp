#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 10000005

int numPF(long long N);
int sieve();
ll gcd(ll a, ll b);

bool v[MAX];
ll primes[MAX], array[MAX], x;
int n_primes;
const ll inf = 9999999999999;

int main()
{
    n_primes = sieve();

    while(true)
    {
        bool f = 0;
        scanf("%lld", &x);
        if(x == 0)
            break;

        if(x < 0)
            x = -1 * x, f = 1;

        int tmp = numPF(x);
        ll g = array[0];
        for(int i = 0; i < tmp; i++)
            g = gcd(g, array[i]);

        if(f == 1 && g % 2 == 0)
        {
            while(g)
            {
                g = g / 2;
                if(g % 2 != 0)
                    break;
            }
            printf("%lld\n", g);

        }
        else
            printf("%lld\n", g);
    }

    return 0;
}

int sieve()
{
    memset(v, 0, sizeof(v));
    v[0] = v[1] = 1;
    long long i, j;

    // Sieve of Eratosthenes
    for (i = 2; i * i < MAX - 5; i++)
    {
        if (!v[i])
        {
            for (j = i * i; j < MAX - 5; j += i)
                v[j] = 1;
        }
    }

    int index = 0;
    for (i = 2; i < MAX - 5; i++)
    {
        if (!v[i])
            primes[index++] = i;
    }

    return index;
}

int numPF(long long N)   // Count the number of prime factors of N
{
    int counter = 0;
    int c2 = 0;
    int index = 0;
    long long pf = primes[index++];
    while (N != 1 && pf * pf <= N && index < n_primes)
    {
        counter = 0;
        while (N % pf == 0)
        {
            N /= pf;
            counter++;
        }

        array[c2] = counter, c2++;
        pf = primes[index++];
    }
    if (N != 1)
        array[c2] = 1, c2++;
    return c2;
}

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
