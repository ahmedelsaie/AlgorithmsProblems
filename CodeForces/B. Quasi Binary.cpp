#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int inf = 99999999;
int n, num = 0, l, dp[1000009], a[20], array[100], ans[1000009], help[1000009], t = 0;
template <typename type>
void merge_sort(int start, int last, type array, type swap);
void gen(int i);
int fn(int accum);
int cnt(int x);
void trace(int accum);

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    l = cnt(n);

    gen(0);
    printf("%d\n", fn(0));
    //  for(int i=0;i<num;i++)
    //   printf("%d\n",array[i]);

    //  fn(0);
    trace(0);
    // printf("%d\n",t);
    merge_sort(0, t - 1, ans, help);

    for(int i = 0; i < t; i++)
    {
        if(i)
            printf(" ");

        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}

int fn(int accum)
{
    // printf("%d\n",accum);
    if(accum > n)
        return inf;

    if(accum == n)
        return 0;

    int& ret = dp[accum];
    if(ret != -1)
        return ret;

    ret = fn(accum + array[1]) + 1;

    for(int i = 1; i < num; i++)
        if(accum + array[i] <= n)
            ret = min(ret, fn(accum + array[i]) + 1);

    return ret;
}

void trace(int accum)
{
    if(accum == n)
        return ;

    int ret = inf, f = 0;
    for(int i = 1; i < num; i++)
    {
        if(accum + array[i] <= n)
            if(dp[accum + array[i]] + 1 < ret)
                ret = fn(accum + array[i]) + 1, f = i;
    }
    ans[t] = array[f], t++;
    trace(accum + array[f]) ;
}


void gen(int i)
{
    if(i == l)
    {
        int ret = 0;
        for(int j = 0; j < i; j++)
            ret = ret * 10 + a[j];
        array[num] = ret, num++;
        return;
    }

    a[i] = 0;
    gen(i + 1);

    a[i] = 1;
    gen(i + 1);

}

int cnt(int x)
{
    if(x == 0)
        return 1;
    int ret = 0;

    while(x)
    {
        x = x / 10;
        ret++;
    }
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
