#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

long reverse(long x);
long power(long x, long y);
long palin(long x);

int main()
{
    long counter;
    long ans;
    long n;

    scanf("%ld", &n);
    while(n > 0)
    {
        scanf("%ld", &ans);
        counter = 0;

        while(counter < 1050)
        {
            ans = ans + reverse(ans);
            if(palin(ans))
            {
                printf("%ld %ld\n", counter + 1, ans);
                break;
            }
            counter++;
        }
        n--;
    }

    return 0;
}

long reverse(long x)
{
    long y = x;
    long ans = 0;

    long flag = 0;
    while(y != 0)
    {
        flag++;
        y = y / 10;
    }

    while(x != 0)
    {
        ans = ans + x % 10 * power(10, flag - 1);
        flag--;
        x = x / 10;
    }
    return ans;
}

long power(long x, long y)
{
    long ans, counter;
    ans = 1;
    for(counter = 0; counter < y; counter++)
        ans = ans * x;
    return ans;
}

long palin(long x)
{
    long y = x;
    long counter;
    long flag = 0;
    while(y != 0)
    {
        flag++;
        y = y / 10;
    }

    long i = flag / 2;

    for(counter = 0; counter < i; counter++)
    {
        if(x % 10 != x / power(10, flag - 1))
            return 0;
        else
        {

            x = x / 10;
            x = x % power(10, flag - 2);
            flag--;
            flag--;
        }
    }

    return 1;
}




