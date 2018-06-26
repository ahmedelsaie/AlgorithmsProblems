#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 100005

int get_query(pair<int, int> seg[], int ql, int qh, int low, int high, int pos);
void update(pair<int, int> seg[], int ql, int qh, int low, int high, int val, int pos);
void construct_segtree(int arr2[], pair<int, int> seg_tree[], int start, int end, int pos);

pair<int, int> seg[4 * MAX];
int lazy[4 * MAX], array[MAX], n, q, x, y, z;

int main()
{
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        array[i] = 0;
    construct_segtree(array, seg, 0, n, 0);

    for(int i = 0; i < q; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        y, z++;
        if(x == 0)
            update(seg, y, z, 0, n, 1, 0);
        else
            printf("%d\n", get_query(seg, y, z, 0, n, 0));
    }
    return 0;
}

int get_query(pair<int, int> seg[], int ql, int qh, int low, int high, int pos)
{
    if(lazy[pos] != 0)
    {
        if(lazy[pos] % 3 == 1)
        {
            int t = (high - low) - seg[pos].first - seg[pos].second;
            int tmp = seg[pos].first;
            seg[pos].first = t;
            seg[pos].second = tmp;
        }
        else if(lazy[pos] % 3 == 2)
        {
///            0 1 2
            int tmp = (high - low) - seg[pos].first - seg[pos].second;
            seg[pos].first = seg[pos].second;
            seg[pos].second = tmp;
        }

        if(high != low + 1) ///children exist
        {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }

        lazy[pos] = 0;
    }

    if (qh <= low || ql >= high) ///no overlap
        return 0;

    if(low >= ql && high <= qh) ///total overlap
        return seg[pos].first;

    int mid = (low + high) / 2;

    ///partial overlap

    return get_query(seg, ql, qh, low, mid, 2 * pos + 1) + get_query(seg, ql, qh, mid, high, 2 * pos + 2);
}

void update(pair<int, int> seg[], int ql, int qh, int low, int high, int val, int pos)
{
    ///0   ///1
    int mid = (high + low) / 2;

    if(lazy[pos] != 0)
    {
        if(lazy[pos] % 3 == 1)
        {
            int tmp = seg[pos].first;
            seg[pos].first = (high - low) - seg[pos].first - seg[pos].second;
            seg[pos].second = tmp;
        }
        else if(lazy[pos] % 3 == 2)
        {
///           0 1 2
            int tmp = (high - low) - seg[pos].first - seg[pos].second;
            seg[pos].first = seg[pos].second;
            seg[pos].second = tmp;
        }

        if(high != low + 1) ///children exist
        {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }

        lazy[pos] = 0;
    }

    if (qh <= low || ql >= high) ///no overlap
        return ;

    if(low >= ql && high <= qh) ///total overlap
    {
        if(val % 3 == 1)
        {
            int tmp = seg[pos].first;
            seg[pos].first = (high - low) - seg[pos].first - seg[pos].second;
            seg[pos].second = tmp;
        }
        else if(val % 3 == 2)
        {
///            0 1 2
            int tmp = (high - low) - seg[pos].first - seg[pos].second;
            seg[pos].first = seg[pos].second;
            seg[pos].second = tmp;
        }

        if(high != low + 1)
        {
            lazy[2 * pos + 1] += val;
            lazy[2 * pos + 2] += val;
        }
        return;
    }

    update(seg, ql, qh, low, mid, val, 2 * pos + 1);
    update(seg, ql, qh, mid, high, val, 2 * pos + 2);

    seg[pos].first = seg[2 * pos + 1].first + seg[2 * pos + 2].first;
    seg[pos].second = seg[2 * pos + 1].second + seg[2 * pos + 2].second;

    return;
}

void construct_segtree(int arr2[], pair<int, int> seg_tree[], int start, int end, int pos)
{
    lazy[pos] = 0;

    if(end == start + 1)
        seg_tree[pos].first = (arr2[start] % 3 == 0), seg_tree[pos].second = (arr2[start] % 3 == 1);
    else
    {
        int mid = (start + end) / 2;
        construct_segtree(arr2, seg_tree, start, mid, 2 * pos + 1);
        construct_segtree(arr2, seg_tree, mid, end, 2 * pos + 2);
        seg_tree[pos].first = seg_tree[2 * pos + 1].first + seg_tree[2 * pos + 2].first;
        seg_tree[pos].second = seg_tree[2 * pos + 1].second + seg_tree[2 * pos + 2].second;
    }
}
