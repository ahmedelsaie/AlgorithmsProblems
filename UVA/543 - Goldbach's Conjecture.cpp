#include <stdio.h>
#include <cstring>
#define MAX 1000009

void sieve();

long long sieve(long long n);
long long primes[MAX + 1];
bool array[MAX + 1];
long long x;
int no_primes;

int main()
{
    long long ans1;
    bool flag;
    sieve();
    while(true)
    {
        flag = false;
        scanf("%lld", &x);
        if(x == 0)
            break;
        for(int j = 0; j < no_primes && primes[j] < x ; j++)
        {
            if(array[x - primes[j]] == 0)
            {
                flag = true;
                ans1 = primes[j];
                break;
            }
        }
        if(flag)
            printf("%lld = %lld + %lld\n", x, ans1, x - ans1);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }


    return 0;
}

void sieve()
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
    no_primes = j;

}
