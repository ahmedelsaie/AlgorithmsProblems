#include <stdio.h>
#include <cstring>
#define ull unsigned long long
ull fn(int left);
ull fac(int i);
ull comb(int m, int n);

bool visited[25];
ull dp[25];

ull dp_fac[25];
bool visited_fac[25];
int n, k, cases;

int main()
{
    memset(visited_fac, false, sizeof(visited_fac));
    memset(visited, false, sizeof(visited));

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        ull up = fn(n), down = fac(n);
        printf("%llu/%llu\n", up, down);
    }


    return 0;
}

ull fn(int left)
{
    if(left == 0)
        return 1;

    bool& flag = visited[left];
    ull& ret = dp[left];

    if(flag)
        return ret;

    ret = 0, flag = true;
    ull tmp;

    for(int i = 2; i <= left; i++)
    {
        tmp = fn(left - i);
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


    /*
        if(i==0 || i==1)
            return 1;

        bool &flag=visited_fac[i];
        ull &ret=dp_fac[i];

        if(flag)
            return ret;

        flag=true;

        ret=i*fac(i-1);

        return ret;
        */
}

ull fac(int i)
{
    if(i == 0 || i == 1)
        return 1;

    bool& flag = visited_fac[i];
    ull& ret = dp_fac[i];

    if(flag)
        return ret;

    flag = true;

    ret = i * fac(i - 1);

    return ret;
}

ull gcd(ull a, ull b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
