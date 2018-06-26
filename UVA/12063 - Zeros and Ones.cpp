#include <stdio.h>
#include <cstring>

unsigned long long pow(long long x);
unsigned long long fn(int zeros, int ones, int mod, int i);

int k, n;
unsigned long long dp[109][109][109];
bool visited[109][109][109];
long long pow_mod(long long a, long long p, long long n);

int main()
{
    int cases, p = 1;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &n, &k);
        printf("Case %d: ", p++);
        if(n & 1 || k == 0)
        {
            printf("0");
        }
        else
        {
            memset(visited, false, sizeof(visited));
            //  printf("%llu\n",help);
            long long help = pow_mod(2, 1, k); //% k;

            printf("%llu", fn(0, 0, 0, 0));
        }

        printf("\n");

    }
    return 0;
}

unsigned long long fn(int zeros, int ones, int mod, int i)
{
    if(zeros > .5 * n || ones > .5 * n)
        return 0;

    if(i == n)
    {
        if(mod == 0 && zeros == ones)
            return 1;
        return 0;
    }

    unsigned long long &ret = dp[zeros][ones][mod];
    bool &flag = visited[zeros][ones][mod];
    if(flag)
        return ret;
    flag = true;

    ret = 0;

    if(i != n - 1)
        ret += fn(zeros + 1, ones, mod, i + 1);

    long long tmp = pow_mod(2, i, k);
    long long help = (tmp + mod) % k;

    ret += fn(zeros, ones + 1, help, i + 1);
    return ret;
}

unsigned long long pow(long long x)
{
    unsigned long long ret = 1;
    for(int i = 0; i < x - 1; i++)
        ret = ret * 2;
    return ret;
}

long long pow_mod(long long a, long long p, long long n)
{
    if(p == 0)  return 1;
    long long ans = pow_mod(a, p / 2, n);
    ans = ans * ans % n;
    if(p % 2 == 1)    ans = ans * a % n;
    return ans;
}
