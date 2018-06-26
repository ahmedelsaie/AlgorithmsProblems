#include <stdio.h>
#include <cstring>
#define MAX 1000009

int reverse(int length, int x);
int power(int x, int y);
bool is_cirular(int x);
int cnt(int x);
void sieve();
void fn();

bool array[MAX];
int ans[MAX];

int main()
{
    int start, end, result;
    sieve();
    fn();

    while(true)
    {
        scanf("%d", &start);
        if(start <= -1)
            break;
        scanf("%d", &end);

        result = ans[end] - ans[start - 1];

        if(result == 0)
            printf("No Circular Primes.");
        if(result == 1)
            printf("%d Circular Prime.", result);
        if(result > 1)
            printf("%d Circular Primes.", result);

        printf("\n");
    }

    return 0;
}

void fn()
{
    int ret = 0, length, x;
    bool flag;

    ans[0] = 0;
    for(int i = 1; i <= 1000000; i++)
    {
        if(is_cirular(i))
            ret++;
        ans[i] = ret;
    }
}

bool is_cirular(int x)
{
    int length = cnt(x);
    int y = x;

    for(int j = 0; j < length; j++)
    {
        y = reverse(length, y);
        if(array[y])
            return false;
    }

    return true;
}

int cnt(int x)
{
    int ret = 0;
    while(x)
    {
        x = x / 10;
        ret++;
    }
    return ret;
}

int reverse(int length, int x)
{
    if(length == 1)
        return x;
    length--;
    int help = power(10, length);
    int mod = x % help;
    int num = x / help;

    mod = mod * 10;
    mod += num;

    return mod;
}

int power(int x, int y)
{
    int ans, counter;
    ans = 1;
    for(counter = 0; counter < y; counter++)
        ans = ans * x;
    return ans;
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
}
