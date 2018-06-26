#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

ll fn(int i, int taken, int f);
ll tabular();
int con(int i, int j);

ll dp[2][500][500];
int n, m, x;
ll const MOD = 1000000007 ;

int main()
{
    // memset(dp, -1, sizeof(dp));

    scanf("%d %d %d", &m, &n, &x);

    x--;

    ll fac = 1;
    for(ll i = 1; i <= m; i++)
        fac = fac * i, fac %= MOD;

    printf("%lld\n", (tabular()*fac) % MOD);

    return 0;
}
//1 10000 1


ll tabular()
{
    if(m > 2 * n)
        return 0;
    //  memset(dp,0,sizeof(dp));

    for(int i = n; i >= 0; i--)
        for(int open = 0; open <= m; open++)
            for(int close = open; close >= 0; close--)
            {
                ll &ret = dp[i % 2][open][close];
                ret = 0;

                if(close > open || open > m)
                    ret = 0;
                else if(i == n)
                    ret = (open == close && open == m);
                else
                {
                    ///skip
                    if(i != x)
                    {
                        ret += dp[(i + 1) % 2][open][close], ret %= MOD;
                        ///close only
                        if(open > close)
                            ret += dp[(i + 1) % 2][open][close + 1], ret %= MOD;
                    }

                    ///open only
                    if(open + 1 <= m)
                        ret += dp[(i + 1) % 2][open + 1][close], ret %= MOD;

                    if(open == close && open + 1 <= m)
                        ret += dp[(i + 1) % 2][open + 1][close + 1], ret %= MOD;
                    else
                    {
                        if(open - close > 0 && open + 1 <= m)
                            ret += dp[(i + 1) % 2][open + 1][close + 1], ret %= MOD;
                    }
                }

                // if(i + open + close == 0)
                ///     printf("%lld\n", ret);
            }

    return dp[0][0][0];
}

/*

ll fn(int i, int open, int close)
{
    //printf("%d %d %d \n", i, open, close);

    if(close > open || open > m)
        return 0;

    if(i == n)
        return open == close && open == m;
    ll &ret = dp[con(i, open)][close];
    if(ret != -1)
        return ret;

    ret = 0;

    ///skip
    if(i != x)
    {
        ret += fn(i + 1, open, close), ret %= MOD;
        ///close only
        ret += fn(i + 1, open, close + 1), ret %= MOD;
    }

    ///open only
    ret += fn(i + 1, open + 1, close), ret %= MOD;

    if(open == close)
        ret += fn(i + 1, open + 1, close + 1), ret %= MOD;
    else
    {
        if(open - close > 0)
            ret += fn(i + 1, open + 1, close + 1), ret %= MOD;
    }


    // ret += 2 * fn(i + 1, open + 1, close + 1);

    return ret;
}

int con(int i, int j)
{

    1 100000 1

      11 79 54
    5+2*5
    10+1*5

    if(n > m)
        return j * n + i;
    return j + i * m;
}



/*

#include <bits/stdc++.h>
using namespace std;
#define MAX 200009
#define ll long long

ll fn(int i, int taken, int f);
int con(int i, int j);

ll dp[MAX][2];
int n, m, x;

int main()
{
    memset(dp, -1, sizeof(dp));

    scanf("%d %d %d", &m, &n, &x);

    x--;

    printf("%lld\n", fn(0, 0, 0));

    return 0;
}

ll fn(int i, int taken, int f)
{
    if(taken > m)
        return 0;

    if(i == n)
        return taken == m && f == 1;

    ll &ret = dp[con(i, taken)][f];
    if(ret != -1)
         return ret;

    ret = 0;

    ///skip
    ret += fn(i + 1, taken, f);

    if(i < x)
        ret += (i - taken + 1) * fn(i + 1, taken + 1, f);
    else
    {
        if(f == 0)
        {
            ret += (i - (taken + 1) + 1) * fn(i + 1, taken + 1, f);
            ret += fn(i + 1, taken + 1, 1);
        }
        else
            ret += (i - taken + 1) * fn(i + 1, taken + 1, f);
    }

    return ret;
}

int con(int i, int j)
{
    return j + i * m;
}




*/
