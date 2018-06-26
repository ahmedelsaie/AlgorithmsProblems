#include <stdio.h>
#include <cstring>
#define MAX 1000009

long long sieve();
int numDiffPF(long long N);

long long array[MAX];
long long primes[MAX];
long long x;

int main()
{
    sieve();

    while(true)
    {
        scanf("%lld", &x);
        if(x == 0)
            break;

        printf("%lld : %d\n", x, numDiffPF(x));
    }

    return 0;
}

int numDiffPF(long long N)   // Count the number of different prime factors of N
{
    int counter = 0;
    int index = 0;
    long long pf = primes[index++];
    while (N != 1 && pf * pf <= N)
    {
        if (N % pf == 0)
            counter++;
        while (N % pf == 0)
            N /= pf;
        pf = primes[index++];
    }
    if (N != 1)
        counter++;
    return counter;
}

long long sieve()
{
    memset(array, false, sizeof(array));
    array[0] = array[1] = 1;
    long long i, j, t;

    for( i = 2; i * i <= MAX; i++)
        if(!array[i])
            for( j = i * i; j <= MAX; j += i)
                array[j] = 1;

    j = 0;
    for(i = 2; i <= MAX; i++)
        if(!array[i])
        {
            primes[j] = i;
            j++;
        }
    return j;
}
