#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 200009

int bin_search(ll x);
int RLC(ll arr[], int m);
template <typename type>
void merge_sort(int start, int last, type array, type swap);

ll array[MAX], sorted[MAX], help[MAX];
int n, m, k;
ll dp[4][MAX];

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%lld", &array[i]), sorted[i] = array[i];

    merge_sort(0, n - 1, sorted, help);

    m = RLC(sorted, n);

    memset(dp, 0, sizeof(dp));

    for(int i = n - 1; i >= 0; i--)
    {
        int y = bin_search(array[i] * k);
        int x = bin_search(array[i]);
     //   printf("%d %d %d %lld\n", i, x, y,array[i] * k);
        ///i am in 1
        if(y != -1)
            dp[1][x] += dp[2][y];

        ///i am in 2
        if(y != -1)
            dp[2][x] += dp[3][y];

        ///i am in 3
        dp[3][x]++;
    }

    ll ans = 0;
    for(int i = 0; i < m; i++)
        ans += dp[1][i];

    printf("%lld\n", ans);
    return 0;
}

int bin_search(ll x)
{
    int small = 0, big = m - 1, mid, ret = -1;

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(sorted[mid] == x)
            return mid;

        if(sorted[mid] < x)
            small = mid + 1;
        else
            big = mid - 1;
    }

    return ret;
}

int RLC(ll arr[], int m)
{
    int i = 0, prev = arr[i], j = 0;

    while(i < m)
    {
        if(arr[i] != prev)
            arr[j++] = prev, prev = arr[i];
        i++;
    }

    arr[j++] = prev;

    return j;
}

///merge_sort
template <typename type>
void merge_sort(int start, int last, type array, type swap)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort(start, middle, array, swap);
    merge_sort(middle + 1, last, array, swap);

    ///MERGING  ///MERGING  ///MERGING  ///MERGING
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        swap[i] = array[i];

    while(main_p <= last)
    {
        if(p1 > middle)
            array[main_p] = array[p2], p2++;

        else if(p2 > last)
            array[main_p] = swap[p1], p1++;

        else if(swap[p1] < array[p2])
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
