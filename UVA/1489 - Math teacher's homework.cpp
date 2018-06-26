#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define ll long long

ll fn();
ll gn(int i_bit, int i_num, int parity, int changed);
ll powr(ll x, ll y, ll mod);
void pre_process();

int arr[MAX];
int bits[MAX][MAX];
int total[MAX], dest[MAX];
int n, target, max_bits;
ll cnt[2][MAX][MAX];
ll dp[MAX][MAX][2][2];
const ll MOD = 1000000003, mod = 1000000003;

int main()
{
    while(true)
    {
        scanf("%d %d", &n, &target);

        if(n + target == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        pre_process();

        printf("%lld\n", fn());
    }

    return 0;
}

ll fn()
{
    memset(dp, -1, sizeof(dp));

    ll ret = 0;

    int f = 1;
    for(int i = max_bits - 1; i >= 0; i--)
    {
        ///odd no of ones = true
        int even = total[i] % 2 == 0 ? 1 : 0;

        ret += gn(i, 0, 0, 0), ret %= MOD;

        if((even && dest[i]) || (!even && !dest[i]))  ///last number here
        {
            f = 0;
            break;
        }
    }

    ret += f;

    return ret;
}

ll gn(int i_bit, int i_num, int parity, int changed)
{
    ///parity =0 even else odd
    if(i_num == n)
        return changed == 1 && ((parity == 0 && !dest[i_bit]) || (parity == 1 && dest[i_bit]));

    ll &ret = dp[i_bit][i_num][parity][changed];
    if(ret != -1)
        return ret;

    ret = 0;

    ///leave the same
    ret += gn(i_bit, i_num + 1, (parity + bits[i_num][i_bit]) % 2, changed) * cnt[0][i_num][i_bit] % MOD;
    ret %= MOD;

    ///change
    if(bits[i_num][i_bit])
    {
        if(changed == 1)
            ret += gn(i_bit, i_num + 1, parity, 1) * cnt[1][i_num][i_bit] % MOD, ret %= MOD;
        else
            ret += gn(i_bit, i_num + 1, parity, 1), ret %= MOD;
    }

    return ret;
}

void pre_process()
{
    memset(bits, 0, sizeof(bits));
    memset(total, 0, sizeof(total));

    max_bits = 0;

    for(int i = 0; i < n; i++)
    {
        int j = 0;
        int x = arr[i];

        while(x)
        {
            if(x % 2)
                bits[i][j] = 1, total[j]++;

            j++;
            x = x / 2;
        }

        max_bits = max(max_bits, j);
    }


    memset(dest, 0, sizeof(dest));
    int j = 0;
    int x = target;

    while(x)
    {
        if(x % 2)
            dest[j] = 1;

        j++;
        x = x / 2;
    }

    max_bits = max(max_bits, j);


    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++)
    {
        ll accum = 1;
        for(int j = 0; j < max_bits; j++)
        {
            if(bits[i][j] == 0)
                cnt[0][i][j] = cnt[1][i][j] = accum;
            else
            {
                cnt[1][i][j] = powr(2, j, mod);
                cnt[0][i][j] = accum;
                accum += cnt[1][i][j], accum %= MOD;
            }
        }
    }
}

ll powr(ll x, ll y, ll mod)
{
    ll ret = 1;
    while(y)
    {
        if(y & 1) ret = ret * x, ret %= mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return ret;
}


