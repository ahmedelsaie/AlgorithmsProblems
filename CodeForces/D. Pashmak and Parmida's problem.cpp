#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 1000009

struct block
{
    int total, pos, val;
};

///segment_tree
struct seg_tree
{
    ll seg[4 * MAX];

    void construct_segtree(int array[], int start, int end, int pos)
    {
        if(end == start + 1)
            seg[pos] = 0;
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(array, start, mid, 2 * pos + 1);
            construct_segtree(array, mid, end, 2 * pos + 2);
            seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
        }
    }

    ll get_query(int ql, int qh, int low, int high, int pos)
    {
        ///no overlap
        if (qh <= low || ql >= high)
            return 0;

        ///total overlap
        if(low >= ql && high <= qh)
            return seg[pos];

        int mid = (low + high) / 2;

        ///partial overlap
        return get_query(ql, qh, low, mid, 2 * pos + 1) + get_query(ql, qh, mid, high, 2 * pos + 2);
    }

    void update(int indx, ll val, int low, int high, int pos)
    {
        if(indx == low && high == low + 1)
            seg[pos] += val;
        else
        {
            ///check in which part
            int mid = (low + high) / 2;

            if(indx >= low && indx < mid)
                update(indx, val, low, mid, 2 * pos + 1);
            else
                update(indx, val, mid, high, 2 * pos + 2);

            seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
        }
    }

};

template <typename type>
void merge_sort(int start, int last, type array, type swap);

block array[MAX];
pair<int, int>  sorted[MAX], help[MAX];
seg_tree x;
int h[4], n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i].val), sorted[i].first = array[i].val, sorted[i].second = i;

    merge_sort(0, n - 1, sorted, help);

    int i = 0, prev = sorted[i].first, accum = 0, first = 0;

    while(i < n)
    {
        if(sorted[i].first != prev)
        {
           // if(prev==2)
             //   printf("hello %d\n",accum);
            int k = 1;
            for(int j = first; j < i; j++)
                array[sorted[j].second].pos = k++, array[sorted[j].second].total = accum;

            accum = 1, prev = sorted[i].first;
            first = i;
        }
        else
            accum++;

        i++;
    }

    int k = 1;
    for(int j = first; j < i; j++)
        array[sorted[j].second].pos = k++, array[sorted[j].second].total = accum;

    x.construct_segtree(h, 0, n + 1, 0);



    ll ans = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        int nw = array[i].pos;
        ll tmp = x.get_query(0, nw, 0, n + 1, 0);
        ans += tmp;
        x.update(array[i].total - array[i].pos + 1, 1, 0, n + 1, 0);
    }

    printf("%lld\n", ans);

    return 0;
}

bool comp(pair<int, int> x, pair<int, int> y)
{
    if(x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
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

