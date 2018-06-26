#include <stdio.h>
#include <cstring>
#define MAX 1000009

long long sieve();
long long EulerPhi(long long N);

bool array[MAX];
long long primes[MAX];

int main()
{
    long long x;
    sieve();

    while(true)
    {
        scanf("%lld", &x);
        if(x == 0)
            break;

        if(x == 1)
            printf("0\n");
        else
            printf("%lld\n", EulerPhi(x));
    }

    return 0;
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

long long EulerPhi(long long N)
{
    int index = 0;
    long long pf = primes[index++];
    long long ans = N; // start from ans = N
    while (N != 1 && pf * pf <= N)
    {
        if (N % pf == 0)
            ans = ans - (ans / pf); // ans = ans * (1 - (1 / p)) just to avoid doubles
        while (N % pf == 0)
            N /= pf;
        pf = primes[index++];
    }
    if (N != 1)
        ans = ans - (ans / N); // last factor is N
    return ans;
}
