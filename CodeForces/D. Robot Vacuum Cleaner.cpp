#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

int comp(pair<ll, ll> x, pair<ll, ll> y);
ll fn();

pair<ll, ll> arr[MAX];
char input[MAX];
int n;

int main()
{
    ll ans = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", input);

        ll s = 0, h = 0;
        int l = strlen(input);

        for(int j = 0; j < l; j++)
        {
            if(input[j] == 's')
                s++;
            else
                h++, ans += s;
        }

        arr[i].first = s, arr[i].second = h;
    }

    printf("%lld\n", ans + fn());

    return 0;
}

ll fn()
{
    sort(arr, arr + n, comp);

    ll sumH = 0;
    for(int i = 0; i < n; i++)
        sumH += arr[i].second;

    ll ret = 0;

    for(int i = 0; i < n; i++)
    {
        sumH -= arr[i].second;
        ret += arr[i].first * sumH;
    }

    return ret;
}

int comp(pair<ll,ll> x, pair<ll, ll> y)
{
    ll first = x.first * y.second;

    ll second = y.first * x.second;

    if(first > second)
        return 1;
    else
        return 0;
}



