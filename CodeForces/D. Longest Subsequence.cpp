#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009
#define ll long long

int fn();

int arr[MAX], ans[MAX], cnt[MAX], n, m, val = 0;

int main()
{
    memset(cnt, 0, sizeof(cnt));

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] <= m)
            cnt[arr[i]]++, val = max(val, arr[i]);
    }

    int ret = fn();

    printf("%d %d\n", ret, ans[ret]);

    for(int i = 0; i < n && ans[ret]; i++)
        if(ret % arr[i] == 0)
            printf("%d ", i + 1);

    return 0;
}

int fn()
{
    int ret = 0, big = 0;
    memset(ans, 0, sizeof(ans));

    for(int i = 0; i <= val; i++)
    {
        if(cnt[i])
            for(int j = 1; j * i <= m; j++)
                ans[j * i] += cnt[i];
    }

    for(int i = 0; i <= m; i++)
        if(ans[i] > big)
            big = ans[i], ret = i;

    int total = 0;
    for(int i = 0; i < n; i++)
        total += arr[i] > m;

    if(total == n)
        return 1;

    return ret;
}


