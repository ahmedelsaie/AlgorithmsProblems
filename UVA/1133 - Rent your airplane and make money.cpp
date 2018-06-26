#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 3009
#define ll long long

struct block
{
    ll start, dura, price;
};

bool comp(block& x, block& y);
template <typename type>
void merge_sort(int start, int last, type array, type swap);
ll fn(int curr);

block array[MAX], help[MAX];
ll visited[MAX], dp[MAX];
int n, cases = 1;
ll ans;
const int inf = 0x3f3f3f3f;
char tmp[1005];

int main()
{
    memset(visited, -1, sizeof(visited));
    bool t = 1;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%s %lld %lld %lld", tmp, &array[i].start, &array[i].dura, &array[i].price);
        merge_sort(0, n - 1, array, help);
        ans = 0;

        for(int i = 0; i < n; i++)
            ans = max(ans, fn(i) + array[i].price);

        if(t)
            t = 0;
        else
            printf("\n");
        printf("%lld\n", ans);
        cases++;
    }

    return 0;
}

ll fn(int curr)
{
    if(curr == n)
        return 0;

    ll& flag = visited[curr];
    ll& ret = dp[curr];
    if(flag == cases)
        return ret;
    flag = cases, ret = 0;

    int tmp = array[curr].start + array[curr].dura;

    for(int i = curr + 1; i < n; i++)
        if(array[i].start >= tmp)
            ret = max(ret, fn(i) + array[i].price);

    return ret;
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

        else if(comp(swap[p1], array[p2]))
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

bool comp(block& x, block& y)
{
    if(x.start == y.start)
        return x.dura < y.dura;
    return x.start < y.start;
}
