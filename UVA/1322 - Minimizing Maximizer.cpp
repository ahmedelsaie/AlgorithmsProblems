#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX1 50009
#define MAX2 500009

void construct_segtree(int arr2[], int seg_tree[], int start, int end, int pos);
void update(int seg[], int ql, int qh, int low, int high, int val, int pos);
int get_query(int seg[], int ql, int qh, int low, int high, int pos);
int fn();

int lazy[4 * MAX1], seg[4 * MAX1], n, m, cases;
pair<int, int> array[MAX2];
const int inf = 99999999;

int main()
{
    bool f = 1;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++)
            scanf("%d %d", &array[i].first, &array[i].second);
        construct_segtree(seg, seg, 0, n, 0);

        if(f)
            f = 0;
        else
            printf("\n");

        printf("%d\n", fn());
    }

    return 0;
}

int fn()
{
    int ret = inf, s, e, tmp;

    for(int i = m - 1; i >= 0; i--)
    {
        s = array[i].first - 1;
        e = array[i].second;

        tmp = get_query(seg, s, e, 0, n, 0);
        if(tmp < inf || e == n)
        {
            if(e == n)
                tmp = 1;
            else
                tmp++;
        }

        if(tmp < inf)
            update(seg, s, e , 0, n, tmp, 0);
    }

    return get_query(seg, 0, 1, 0, n, 0);
}

int get_query(int seg[], int ql, int qh, int low, int high, int pos)
{
    if(lazy[pos] != inf)
    {
        seg[pos] = min(seg[pos], lazy[pos]);

        if(high != low + 1) ///children exist
        {
            lazy[2 * pos + 1] = min(lazy[pos], lazy[2 * pos + 1]);
            lazy[2 * pos + 2] = min(lazy[pos], lazy[2 * pos + 2]);
        }

        lazy[pos] = inf;
    }

    if (qh <= low || ql >= high) ///no overlap
        return inf;

    if(low >= ql && high <= qh) ///total overlap
        return seg[pos];

    int mid = (low + high) / 2;

    ///partial overlap
    return min(get_query(seg, ql, qh, low, mid, 2 * pos + 1), get_query(seg, ql, qh, mid, high, 2 * pos + 2));
}

void update(int seg[], int ql, int qh, int low, int high, int val, int pos)
{
    int mid = (high + low) / 2;

    if(lazy[pos] != inf)
    {
        seg[pos] = min(seg[pos], lazy[pos]);

        if(high != low + 1) ///children exist
        {
            lazy[2 * pos + 1] = min(lazy[pos], lazy[2 * pos + 1]);
            lazy[2 * pos + 2] = min(lazy[pos], lazy[2 * pos + 2]);
        }

        lazy[pos] = inf;
    }

    if (qh <= low || ql >= high) ///no overlap
        return ;

    if(low >= ql && high <= qh) ///total overlap
    {
        seg[pos] = min(val, seg[pos]);

        if(high != low + 1)
        {
            lazy[2 * pos + 1] = min(val, lazy[2 * pos + 1]);
            lazy[2 * pos + 2] = min(val, lazy[2 * pos + 2]);
        }
        return;
    }

    update(seg, ql, qh, low, mid, val, 2 * pos + 1);
    update(seg, ql, qh, mid, high, val, 2 * pos + 2);

    seg[pos] = min(seg[2 * pos + 1], seg[2 * pos + 2]);

    return;
}

void construct_segtree(int arr2[], int seg_tree[], int start, int end, int pos)
{
    lazy[pos] = inf;

    if(end == start + 1)
        seg_tree[pos] = inf;
    else
    {
        int mid = (start + end) / 2;
        construct_segtree(arr2, seg_tree, start, mid, 2 * pos + 1);
        construct_segtree(arr2, seg_tree, mid, end, 2 * pos + 2);
        seg_tree[pos] = min(seg_tree[2 * pos + 1], seg_tree[2 * pos + 2]);
    }
}
