#include <stdio.h>
#include <cstring>
#define MAX 20000000
using namespace std;

struct pair
{
    long long x, y;
};

pair ans[100009];
long long sieve(long long n);
long long primes[MAX + 1];
bool array[MAX + 1];

int main()
{
    memset(array, false, sizeof(array));
    array[0] = array[1] = 1;
    long long i, j, t;

    for( i = 2; i * i <= MAX; i++)
        if(!array[i])
            for( j = i * i; j <= MAX; j += i)
                array[j] = 1;

    j = 0;
    for(i = 3; i <= MAX; i++)
        if(!array[i])
        {
            primes[j] = i;
            j++;
        }
    long long k = 1;


    for(int i = 1; i < j  && k < 100009; i++)
        if(primes[i - 1] == primes[i] - 2)
        {
            // printf("%ll ")
            ans[k].x = primes[i - 1];
            ans[k].y = primes[i];
            k++;
        }

    while (scanf("%lld", &t) == 1)
        printf("(%lld, %lld)\n", ans[t].x, ans[t].y);




    return 0;
}

