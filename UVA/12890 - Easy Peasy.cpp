#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long
struct sparse_table
{
    int n;
    ll spt[MAX][20];

    void construct(ll a[], int n)
    {
        for(int i = 0; i < n; i++)
            spt[i][0] = a[i];

        for(int j = 1; (1 << j) <= n; j++)
            for(int i = 0; i + (1 << j) - 1 < n; i++)
                spt[i][j] = min(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
    }

    ll get_query(int i, int j)
    {
        int k = (int)floor(log((double)j - i + 1) / log(2.0));
        return min(spt[i][k], spt[j - (1 << k) + 1][k]);
    }
};

int compress();
int bin_search(int x);
ll fn();
int bin_search2(int i);

sparse_table table;
ll arr[MAX], help[MAX], nxt[MAX], tmp_nxt[MAX];
int n, m, tc;
ll const inf = 99999999999;

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]), help[i] = arr[i];
        printf("%lld\n", fn());
    }

    return 0;
}

ll fn()
{
    m = compress();
    for(int i = 0; i < n; i++)
        nxt[i] = inf, tmp_nxt[i] = inf;

    for(int i = n - 1; i >= 0; i--)
    {
        int tmp = bin_search(arr[i]);
        nxt[i] = tmp_nxt[tmp];
        tmp_nxt[tmp] = i;
    }

    // for(int i=0;i<n;i++)
    //   printf("%d ",nxt[i]);
    table.n = n;
    table.construct(nxt, n);

    ll ret = 0;
    for(int i = 0; i < n; i++)
    {
        ll tmp = (ll) bin_search2(i);
        ret += tmp - i + 1;
    }

    return ret;
}

int bin_search2(int i)
{
    int small = i, big = n - 1, mid;
    int ret = i;
    while(big >= small)
    {
        mid = (big + small) / 2;
        if(table.get_query(i, mid ) > mid)
            small = mid + 1, ret = max(ret, mid);
        else
            big = mid - 1;
    }

    return ret;
}

int bin_search(int x)
{
    int small = 0, big = m, mid;

    while(big >= small)
    {
        mid = (big + small) / 2;
        if(help[mid] == x)
            return mid;

        if(help[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }
}

int compress()
{
    sort(help, help + n);

    int i = 0, prev = help[0], j = 0;

    while(i < n)
    {
        if(help[i] != prev)
        {
            help[j++] = prev;
            prev = help[i];
        }

        i++;
    }

    help[j++] = prev;
    return j;
}


