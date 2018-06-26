#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#define ll long long
using namespace std;
template <typename type>
void merge_sort(int start, int last, type array, type swap);
int fn(int x, int y);

int boys[105], girls[105], help[105], dp[105][105];
int n, m;
const int inf = 9999999999;
///5 2 5 1 48

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &boys[i]);

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &girls[i]);

    merge_sort(0, n - 1, boys, help), merge_sort(0, m - 1, girls, help);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", fn(0, 0));

    return 0;
}

int fn(int x, int y)
{
    if(x == n || y == m)
        return 0;

    int& ret = dp[x][y];
    if(ret != -1)
        return ret;

    ret = -1 * inf;

    ret = max(ret, fn(x + 1, y)), ret = max(ret, fn(x, y + 1));
    if(abs(boys[x] - girls[y]) <= 1)
        ret = max(ret, fn(x + 1, y + 1) + 1);

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

        else if(swap[p1] < array[p2])
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

