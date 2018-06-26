#include <bits/stdc++.h>
using namespace std;
#define MAX 1009
#define ll long long

ll const mod = (ll)1000000007;
const int inf = 9999999;

void pre_process();
ll fn_cnt(int i);
int fn(int i, int mode);
int check(int s, int e);

char arr[MAX];
int sum[30][MAX], con[30];
int dp[MAX][2], n;
ll dp_cnt[MAX];

int main()
{
    scanf("%d", &n);
    scanf("%s", arr);

    for(int i = 0; i < 26; i++)
        scanf("%d", &con[i]);

    pre_process();

    int small = fn(0, 0);
    int big = fn(0, 1);
    ll cnt = fn_cnt(0);

    printf("%lld\n%d\n%d\n", cnt, big, small);

    return 0;
}

void pre_process()
{
    memset(sum, 0, sizeof(sum));
    memset(dp, -1, sizeof(dp));
    memset(dp_cnt, -1, sizeof(dp_cnt));

    for(int j = 0; j < 26; j++)
    {
        for(int i = 0; i < n; i++)
            sum[j][i + 1] = sum[j][i - 1 + 1] + (arr[i] == ('a' + j));

        int i = n;
        sum[j][i + 1] = sum[j][i - 1 + 1];

    }

}

ll fn_cnt(int i)
{
    if(i == n)
        return 1;

    ll &ret = dp_cnt[i];
    if(ret != -1)
        return ret;

    ret = 0;

    for(int j = i + 1; j <= n; j++)
        if(check(i, j))
            ret += fn_cnt(j), ret = ret % mod;

    return ret;
}

int fn(int i, int mode)
{
    if(i == n)
        return 0;

    int &ret = dp[i][mode];
    if(ret != -1)
        return ret;

    ///0 min
    ret = mode == 0 ? inf : -inf;

    for(int j = i + 1; j <= n; j++)
    {
        if(check(i, j))
        {
            if(mode == 0)
                ret = min(ret, fn(j, mode) + 1);
            else
            {
                if(fn(j, mode) != -inf)
                    ret = max(ret, max(fn(j, mode), (j - i)));
            }
        }
    }

    return ret;
}

int check(int s, int e)
{
    for(int i = 0; i < 26; i++)
    {
        if(e - s > con[i] && sum[i][e - 1 + 1] - sum[i][s - 1 + 1])
            return 0;
    }

    return 1;
}
