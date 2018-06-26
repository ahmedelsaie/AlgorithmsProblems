#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 10009

template <typename type>
void merge_sort(int start, int last, type array, type swap);
int update(int seg_tree[], int indx, int val, int low, int high, int pos);
int get_query(int seg_tree[], int ql, int qh, int low, int high, int pos);
void construct_segtree(int array[], int seg_tree[], int start, int end, int pos);
int bin_search(int x);
int fn();

int array[MAX], sorted[MAX], help[MAX], dp1[MAX], dp2[MAX], seg_tree[4 * MAX], n, m;
const int inf = 99999999;

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]), sorted[i] = array[i];
        printf("%d\n", fn());
    }

    return 0;
}

int fn()
{
    int ret = 0, tmp, tmp2, i = 0, prev;
    m = 0;
    merge_sort(0, n - 1, sorted, help);
    prev = sorted[0];

    while(i < n)
    {
        if(sorted[i] != prev)
            sorted[m] = prev, m++, prev = sorted[i];
        i++;
    }
    sorted[m] = prev, m++;

    construct_segtree(array, seg_tree, 0, m, 0);
    for(int i = n - 1; i >= 0; i--)
    {
        dp1[i] = 1;
        tmp = bin_search(array[i]);
        if(tmp > 0)
        {
            tmp2 = get_query(seg_tree, 0, tmp, 0, m, 0);
            dp1[i] = tmp2 + 1;
        }
        update(seg_tree, tmp, dp1[i], 0, m, 0);
    }

    construct_segtree(array, seg_tree, 0, m, 0);
    for(int i = 0; i < n; i++)
    {
        dp2[i] = 1;
        tmp = bin_search(array[i]);
        if(tmp > 0)
        {
            tmp2 = get_query(seg_tree, 0, tmp, 0, m, 0);
            dp2[i] = tmp2 + 1;
        }
        update(seg_tree, tmp, dp2[i], 0, m, 0);

        int val = 2 * min(dp2[i], dp1[i]);
        if(val > ret && (val) % 2 == 0)
            ret = max(ret, val - 1);

    }

    return ret;
}

int bin_search(int x)
{
    int big = m - 1, small = 0, mid;

    while(big >= small)
    {
        //printf("search %d %d\n",small,big);
        mid = (big + small) / 2;

        if(sorted[mid] == x)
            return mid;

        if(sorted[mid] < x)
            small = mid + 1;
        else
            big = mid - 1;
    }
}

int update(int seg_tree[], int indx, int val, int low, int high, int pos)
{
    if(indx == low && high == low + 1)
    {
        seg_tree[pos] = max(val, seg_tree[pos]);
        return seg_tree[pos];
    }

    ///check in which part
    int mid = (low + high) / 2;

    if(indx >= low && indx < mid)
        seg_tree[pos] = max(seg_tree[2 * pos + 2], update(seg_tree, indx, val, low, mid, 2 * pos + 1));
    else
        seg_tree[pos] = max(seg_tree[2 * pos + 1], update(seg_tree, indx, val, mid, high, 2 * pos + 2));

    return seg_tree[pos];
}

void construct_segtree(int array[], int seg_tree[], int start, int end, int pos)
{
    if(end == start + 1)
        seg_tree[pos] = 0;
    else
    {
        int mid = (start + end) / 2;
        construct_segtree(array, seg_tree, start, mid, 2 * pos + 1);
        construct_segtree(array, seg_tree, mid, end, 2 * pos + 2);
        seg_tree[pos] = max(seg_tree[2 * pos + 1], seg_tree[2 * pos + 2]);
    }
}

int get_query(int seg_tree[], int ql, int qh, int low, int high, int pos)
{
    ///no overlap
    if (qh <= low || ql >= high)
        return -1 * inf;

    ///total overlap
    if(low >= ql && high <= qh)
        return seg_tree[pos];

    int mid = (low + high) / 2;

    ///partial overlap
    return max(get_query(seg_tree, ql, qh, low, mid, 2 * pos + 1), get_query(seg_tree, ql, qh, mid, high, 2 * pos + 2));
}

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

