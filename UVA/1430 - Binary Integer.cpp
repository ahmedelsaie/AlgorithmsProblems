#include <bits/stdc++.h>
using namespace std;
#define MAX 41
#define ll long long

int gn(int good, int bad, int left_good, int left);
int fn(int good, int bad, int left);
void build_combtable();
int get_goods(int n_bits);

int dp2[MAX][MAX][MAX][24];
int dp[MAX][MAX][24];
int C[MAX][24];
const int MOD = 10007;
char arr1[MAX], arr2[MAX];
int n_bits, k, cases = 1;

int main()
{
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));

    build_combtable();

    ///good don't need to be change

    while(true)
    {
        scanf("%d %d", &n_bits, &k);

        if(n_bits + k == 0)
            break;

        scanf("%s %s", arr1, arr2);

        int good = get_goods(n_bits);
        int bad = n_bits - good;

        printf("Case #%d: %d\n", cases++, fn(good, bad, k));
    }

    return 0;
}

int fn(int good, int bad, int left)
{
    if(good + bad == 0)
        return left == 0;

    int &ret = dp[good][bad][left];
    if(ret != -1)
        return ret;
    ret = 0;

    if(good)
    {
        for(int i = 0; i <= left; i += 2)
            for(int j = 0; j <= good - 1 + bad; j++)
            {
                int t = good - 1 + bad;
                ret += gn(good - 1, bad, j, i) * fn(j, t - j, left - i);
                ret %= MOD;
            }
    }
    else
    {
        for(int i = 1; i <= left; i += 2)
            for(int j = 0; j <= good + bad - 1; j++)
            {
                int t = good + bad - 1;
                ret += gn(good , bad - 1, j, i) * fn(j, t - j, left - i);
                ret %= MOD;
            }
    }

    return ret;
}

int gn(int good, int bad, int left_good, int left)
{
    if(good < 0 || bad < 0 || left_good < 0 || left < 0  || good + bad < left_good || good + min(bad, 2 * left) < left_good)
        return 0;

    if(good + bad == 0)
        return left_good == 0 && left == 0;


    int &ret = dp2[good][bad][left_good][left];
    if(ret != -1)
        return ret;

    ret = 0;

    if(good)
    {
        for(int i = 0; i <= left; i++)
        {
            for(int j = 0; j <= min(i, good - 1); j++)
            {
                int k = i - j;
                ll comb = C[good - 1][j] * C[bad][k] % MOD;
                ret += comb * gn(good - 1 - j + k, bad - k + j, left_good - (i % 2 == 0), left - i);
                ret %= MOD;
            }
        }
    }
    else
    {
        for(int i = 0; i <= left; i++)
        {
            for(int j = 0; j <= min(i, bad - 1); j++)
            {
                int k = i - j;
                ll comb = C[bad - 1][j] * C[good][k] % MOD;;
                ret += comb * gn(good + j - k, bad + k - j - 1, left_good - (i % 2 != 0), left - i);
                ret %= MOD;
            }
        }
    }

    return ret;
}

int get_goods(int n_bits)
{
    int ret = 0;

    for(int i = 0; i < n_bits; i++)
    {
        if(arr1[i] == arr2[i])
            ret++;
    }

    return ret;
}

void build_combtable()
{
    for(int left = 0; left <= 40; left++)
        for(int p = 0; p <= 20; p++)
        {
            int& ret = C[left][p];
            if(left == 0)
                ret = (p == 0);
            else
            {
                ret = (ret % MOD + C[left - 1][p] % MOD) % MOD;
                if(p > 0)
                    ret = (ret % MOD + C[left - 1][p - 1] % MOD) % MOD;
            }
        }
}
