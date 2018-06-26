#include <stdio.h>
#include <cstring>
#define MAX 1000009

long long sieve();
long long numPF(long long N) ;  // Count the number of prime factors of N

long long array[MAX];
long long primes[MAX];
long long x;
long long ans[100];

int main()
{
    long long ans1;
    sieve();
    bool flag;
    while(true)
    {
        flag = false;
        scanf("%lld", &x);
        if(x == 0)
            break;
        if(x < 0)
        {
            flag = true;
            x = -1 * x;
        }
        ans1 = numPF(x);
        if(flag)
        {
            //200 = 2 x 2 x 2 x 5 x 5
            printf("-%d = -1 x ", x);

        }
        else
            printf("%d = ", x);
        for(int i = 0; i < ans1; i++)
        {
            if(i == 0)
                printf("%lld", ans[i]);
            else
                printf(" x %lld", ans[i]);
        }
        printf("\n");
    }


    return 0;
}

long long numPF(long long N)   // Count the number of prime factors of N
{
    long long counter = 0;
    int index = 0;
    long long pf = primes[index++];
    while (N != 1 && pf * pf <= N)
    {
        while (N % pf == 0)
        {

            N /= pf;
            ans[counter] = pf;
            counter++;
        }
        pf = primes[index++];
    }
    long long temp = 1;
    for(int i = 0; i < counter; i++)
        temp = temp * ans[i];

    pf = primes[index++];
    if (N != 1)
    {
        ans[counter] = x / temp;
        counter++;

    }
    return counter;
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
