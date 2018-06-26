#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

ll array[MAX], cost[MAX], need[MAX];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld %lld", &need[i], &array[i]);

    cost[0] = array[0];
    for(int i = 1; i < n; i++)
        cost[i] = min(cost[i - 1], array[i]);

    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += cost[i] * need[i];

    printf("%lld\n",ans);
    return 0;
}
