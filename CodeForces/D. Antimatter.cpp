#include <bits/stdc++.h>
using namespace std;
#define MAX 50009
#define ll long long

ll fn(int i, int total);

ll dp[1005][20009];
int arr[1005], n, c = 10000;
const ll MOD = 1000000007;

int main()
{
    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    ll ret = 0;
    for(int i = 0; i < n; i++)
    {
        ret += fn(i + 1, -arr[i]), ret %= MOD;;
        ret += fn(i + 1, arr[i]), ret %= MOD;;
    }

    printf("%lld\n", ret);

    return 0;

}

ll fn(int i, int total)
{
    if(i == n)
        return total == 0;

    ll &ret = dp[i][total + c];
    if(ret != -1)
        return ret;

    ret = (total == 0);

    ret += fn(i + 1, total + arr[i]), ret %= MOD;

    ret += fn(i + 1, total - arr[i]), ret %= MOD;

    return ret;// + (total == 0);
}

