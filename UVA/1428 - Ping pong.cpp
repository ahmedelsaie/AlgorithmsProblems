#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX1 100005
#define MAX2 20005

void construct(int array[], int seg[], int low, int high, int pos);
int update(int seg_tree[], int indx, int val, int low, int high, int pos);
int get_query(int seg_tree[], int ql, int qh, int low, int high, int pos);
ll fn();

ll left1[MAX2], right1[MAX2];
int seg[4 * MAX1], array[MAX2];
int n, cases;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        printf("%lld\n", fn());
    }
    return 0;
}

ll fn()
{
    ll ret = 0;

    construct(array, seg, 0, 100001, 0);
    for(int i = 0; i < n; i++)
    {
        left1[i] = get_query(seg, 1, array[i], 0, 100001, 0);
        update(seg, array[i], 1, 0,  100001, 0);
    }

    construct(array, seg, 0, 100001, 0);
    for(int i = n - 1; i >= 0; i--)
    {
        right1[i] = get_query(seg,  array[i], 100001, 0, 100001, 0);
        update(seg, array[i], 1, 0,  100001, 0);
    }

    for(int i = 0; i < n; i++)
        ret += right1[i] * left1[i];

    ///sec part
    construct(array, seg, 0, 100001, 0);
    for(int i = 0; i < n; i++)
    {
        left1[i] = get_query(seg,  array[i], 100001, 0, 100001, 0);
        update(seg, array[i], 1, 0,  100001, 0);
    }

    construct(array, seg, 0, 100001, 0);
    for(int i = n - 1; i >= 0; i--)
    {
        right1[i] = get_query(seg, 1, array[i], 0, 100001, 0);
        update(seg, array[i], 1, 0,  100001, 0);
    }

    for(int i = 0; i < n; i++)
        ret += right1[i] * left1[i];

    return ret;
}

int get_query(int seg_tree[], int ql, int qh, int low, int high, int pos)
{
    ///no overlap
    if (qh <= low || ql >= high)
        return 0;

    ///total overlap
    if(low >= ql && high <= qh)
        return seg_tree[pos];

    int mid = (low + high) / 2;

    ///partial overlap
    return get_query(seg_tree, ql, qh, low, mid, 2 * pos + 1) + get_query(seg_tree, ql, qh, mid, high, 2 * pos + 2);
}

int update(int seg_tree[], int indx, int val, int low, int high, int pos)
{
    if(indx == low && high == low + 1)
    {
        seg_tree[pos] += val;
        return seg_tree[pos];
    }

    ///check in which part
    int mid = (low + high) / 2;

    if(indx >= low && indx < mid)
        seg_tree[pos] = seg_tree[2 * pos + 2] + update(seg_tree, indx, val, low, mid, 2 * pos + 1);
    else
        seg_tree[pos] = seg_tree[2 * pos + 1] + update(seg_tree, indx, val, mid, high, 2 * pos + 2);;

    return seg_tree[pos];
}

void construct(int array[], int seg[], int low, int high, int pos)
{
    if(high == low + 1)
        seg[pos] = 0;
    else
    {
        int mid = (high + low) / 2;
        construct(array, seg, low, mid, 2 * pos + 1);
        construct(array, seg, mid, high, 2 * pos + 2);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }
}
