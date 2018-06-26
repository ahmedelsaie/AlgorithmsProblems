#include <stdio.h>
#include <cstring>
#define ull unsigned long long

ull fn(int left, int swaps);
ull fac(int i);
ull comb(int m, int n);

bool visited[25][25];
ull dp[25][25];

ull dp_fac[25];
bool visited_fac[25];
int n, k;

int main()
{
    memset(visited_fac, false, sizeof(visited_fac));
    memset(visited, false, sizeof(visited));

    while(true)
    {

        scanf("%d %d", &n, &k);
        if(n == 0 && k == 0)
            break;

        printf("%llu\n", fn(n, k));
    }

    return 0;
}

ull fn(int left, int swaps)
{
    if(left == 0)
    {
        if(swaps == 0)
            return 1;
        return 0;
    }

    if(left < 0 || swaps < 0) // || start==n)
        return 0;

    bool &flag = visited[left][swaps];
    ull &ret = dp[left][swaps];

    if(flag)
        return ret;
    ret = 0;
    flag = true;
    ull tmp;

    for(int i = 1; i <= left; i++)
    {
        tmp = fn(left - i, swaps - i + 1);

        tmp = tmp * fac(i - 1);
        tmp = tmp * comb(left - 1, i - 1);
        ret += tmp;
    }

    return ret;
}

ull comb(int m, int n)
{
    ull x = fac(m);
    x = x / fac(n);
    x = x / fac(m - n);

    return x;
}

ull fac(int i)
{
    if(i == 0 || i == 1)
        return 1;

    bool &flag = visited_fac[i];
    ull &ret = dp_fac[i];

    if(flag)
        return ret;

    flag = true;

    ret = i * fac(i - 1);

    return ret;
}
