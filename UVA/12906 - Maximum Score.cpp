#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll  unsigned long long

ll fn(int left, int mode);
ll solve();

ll dp[MAX][2];
const ll MOD = 1000000007;
pair<ll, ll> arr[MAX];
ll val;
int n, cases = 1, tc;

int main()
{
    memset(dp, -1, sizeof(dp));

    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%llu %llu", &arr[i].first, &arr[i].second), arr[i].first *= -1;

        ll cnt = solve();
        printf("Case %d: %llu %llu\n", cases++, val, cnt);
    }

    return 0;
}

ll solve()
{
    sort(arr, arr + n);
    ll ret = 1;

    int i = 0;
    ll prev = arr[i].first;

    while(i < n)
    {
        if(arr[i].first != prev)
            break;
        i++;
    }

 //   if(i!=n)
    for(i; i < n; i++)
        ret = ret * fn(arr[i].second, 0) % MOD, ret %= MOD;

    i = 0, prev = arr[i].first;
    ll cnt = 0;
    int j = 0;

    while(i < n)
    {
        if(arr[i].first == prev)
            cnt += arr[i].second;
        else
        {
            arr[j++].second = cnt;
            prev = arr[i].first, cnt = arr[i].second;
        }
        i++;
    }

    arr[j++].second = cnt;
    ll total = 0;
    for(int i = 0; i < j; i++)
        total += arr[i].second;

    val = 0;
    for(int i = 0; i < j; i++)
        val += total * arr[i].second, total -= arr[i].second;


    return ret;
}

ll fn(int left, int mode)
{
    if(left == 0)return 1;

    ll& ret = dp[left][mode];
    if(ret != -1)return ret;
    ret = 0;

    if(mode == 0)
        ret += fn(left, mode + 1), ret %= MOD;

    ret += fn(left - 1, mode), ret %= MOD;;

    return ret;
}
