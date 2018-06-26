#include <bits/stdc++.h>
using namespace std;
#define MAX1 3000009
#define MAX2 1000000
#define ll long long

int get_rem(int x);
ll numPF(long long N);
int sieve();
void fn();

bool v[MAX1 + 5];
ll primes[MAX1 + 5];
int ans[MAX1 + 5], taken[MAX1 + 5], n = 1000001, p;
int powr(int base, int p, int mod);

int main()
{
    p = sieve();
    memset(ans, 0, sizeof(ans));
    memset(taken, 0, sizeof(taken));
    fn();
    int tc, x;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &x);
        printf("%d\n", ans[x] - 1);

    }

    return 0;
}

void fn()
{
    int i = 0, last = 0, rem;

    while(i < n)
    {
        for(int j = last + 1; j <= 3 * i + 6; j++)
            numPF(j);
        last = 3 * i + 6;
        rem = get_rem(3 * i + 7);
        rem = rem % (3 * i + 7);

        rem = (rem + 1) / (3 * i + 7);
        //printf("%d %d\n", i, rem);
        ans[i] = ans[i - 1] + rem;
        //  printf("%d\n",i);
        i++;
    }
}

int get_rem(int x)
{
    //  printf("x==== %d\n", x);
    ll N = (ll)x;
    int ret = 1;

    ///not prime
    if(v[x])
    {
        return 0;
        pair<int, int> tmp[20];
        int k = 0;

        int counter = 0;
        int index = 0;
        long long pf = primes[index++];

        while (N != 1 && index < p && N > pf * pf && pf * pf <= N)
        {
            counter = 0;
            while (N % pf == 0)
                N /= pf, counter++;

            if(counter)
                tmp[k].first = pf, tmp[k].second = counter, k++;

            pf = primes[index++];
        }

        if (N != 1)
            tmp[k].first = N, tmp[k].second = 1, k++;

        //  printf("k=  %d\n", k);
        for(int i = 0; i < k; i++)
        {
            int j = tmp[i].first;
            //   printf("in loop %d %d\n", j, taken[j]);
            if(taken[j] < tmp[i].second)
            {
                ret = (ret * powr(j, tmp[i].second - taken[j], x)) % x;
                // for(int h = 0; h < ; h++)
                //  ret = ret * j;
            }

        }
    }
    else
    {
        return x - 1;
        //  for(int i = 1; i <= x; i++)
        //    ret = (ret * i) % x;
        for(int i = 0; i <= p && taken[primes[i]]; i++)
        {
            //ret = (ret * mul_mod(primes[i], taken[primes[i]], x)) % x;
            //   powr(primes[i], taken[primes[i]], x)) % x;
        }

        // printf("%d %d\n", x, ret);
    }


    //  printf("ret = %d\n", ret);
    return ret == 1 ? 0 : ret;

}


int powr(int base, int p, int mod)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return base % mod;

    if(p % 2)
        return (powr(base, p - 1, mod) * base % mod) % mod;

    int tmp = powr(base, p / 2, mod);

    tmp = tmp * tmp;

    return tmp % mod;
}

int sieve()
{
    memset(v, 0, sizeof(v));
    v[0] = v[1] = 1;
    long long i, j;

    // Sieve of Eratosthenes
    for (i = 2; i * i <= MAX1; i++)
    {
        if (!v[i])
        {
            for (j = i * i; j <= MAX1; j += i)
            {
                v[j] = 1;
            }
        }
    }

    int index = 0;
    for (i = 2; i <= MAX1; i++)
    {
        if (!v[i])
        {
            primes[index++] = i;
        }
    }

    return index;
}

ll numPF(long long N) // Count the number of prime factors of N
{
    int c = 0;
    if(N == 1)
        return 2;

    if(!v[N])
        return N;
    int indx = 0;
    ll counter = 0;
    ll ret = 0;
    int index = 0;
    ll tmp;
    long long pf = primes[index++];
    int fact = 0;

    while (N != 1 && index < p && N > pf * pf && pf * pf <= N)
    {
        tmp = 1;
        counter = 0;
        while (N % pf == 0)
        {
            N /= pf;
            taken[pf]++;
            tmp *= pf;
            counter++;
        }

        pf = primes[index++];
    }

    if (N != 1)
        taken[N]++;

    return ret;
}
