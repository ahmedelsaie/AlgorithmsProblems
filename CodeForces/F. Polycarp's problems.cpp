#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
#define ll long long

ll fn(int i, int left);
int bin_search(ll x);

const ll inf = 9223372036854775808;
ll array[MAX], dp[MAX][MAX], query[200009];
pair<ll, int> ans[MAX];
int n, m;

int main()
{
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            dp[i][j] = inf;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%lld", &array[i]);

    for(int i = 0; i < m; i++)
        scanf("%lld", &query[i]);

    for(int i = 0; i <= n; i++)
        ans[i].first = fn(0, i), ans[i].second = i;// printf("huhui %lld\n", fn(0, i));

    // sort(ans, ans + n);

    for(int i = 0; i < m; i++)
        printf("%d\n", bin_search(query[i]));

    return 0;
}

ll fn(int i, int left)
{
    if(i == n)return 0;

    ll &ret = dp[i][left];
    if(ret != inf) return ret;

    ///take
    ret = min(array[i], array[i] + fn(i + 1, left));
    if(left)
        ret = max(ret, fn(i + 1, left - 1));

    return ret;
}

int bin_search(ll x)
{
    x = -x;
    int small = 0, big = n + 1, ret = n;

    while(big >= small)
    {
        int mid = (big + small) / 2;
        if(ans[mid].first >= x)
            big = mid - 1, ret = min(ret, ans[mid].second);
        else
            small = mid + 1;
    }

    return ret;
}
