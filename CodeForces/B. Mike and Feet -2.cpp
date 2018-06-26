#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 200009
const int inf = (1 << 30);

///segment_tree
struct seg_tree
{
    int seg[4 * MAX], lazy[4 * MAX], flag;

    void construct_segtree(int array[], int start, int end, int pos)
    {
        if(end == start + 1)
            seg[pos] = array[start];
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(array, start, mid, 2 * pos + 1);
            construct_segtree(array, mid, end, 2 * pos + 2);
            int t1 = seg[2 * pos + 1];
            int t2 = seg[2 * pos + 2];
            seg[pos] = (flag == 0 ? max(t1, t2) : min(t1, t2));
        }
    }

    int get_query(int ql, int qh, int low, int high, int pos)
    {
        ///no overlap
        if (qh <= low || ql >= high)
            return  (flag == 0 ? -1 * inf : inf);

        ///total overlap
        if(low >= ql && high <= qh)
            return seg[pos];

        int mid = (low + high) / 2;

        ///partial overlap
        int t1 = get_query(ql, qh, low, mid, 2 * pos + 1);
        int t2 = get_query(ql, qh, mid, high, 2 * pos + 2);

        return (flag == 0 ? max(t1, t2) : min(t1, t2));
    }

    void update(int indx, int val, int low, int high, int pos)
    {
        if(indx == low && high == low + 1)
            seg[pos] = val;
        else
        {
            ///check in which part
            int mid = (low + high) / 2;

            if(indx >= low && indx < mid)
                update(indx, val, low, mid, 2 * pos + 1);
            else
                update(indx, val, mid, high, 2 * pos + 2);

            int t1 = seg[2 * pos + 1];
            int t2 = seg[2 * pos + 2];

            seg[pos] = (flag == 0 ? max(t1, t2) : min(t1, t2));
        }
    }

    int get_query(int ql, int qh, int low, int high, int pos, int flag)
    {
        if(lazy[pos] != 0)
        {
            seg[pos] = max(seg[pos], lazy[pos]);

            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] = max(lazy[pos], lazy[2 * pos + 1]);
                lazy[2 * pos + 2] = max(lazy[pos], lazy[2 * pos + 2]);
            }

            lazy[pos] = 0;
        }

        if (qh <= low || ql >= high) ///no overlap
            return -1 * inf;

        if(low >= ql && high <= qh) ///total overlap
            return seg[pos];

        int mid = (low + high) / 2;

        ///partial overlap
        return max(get_query(ql, qh, low, mid, 2 * pos + 1, flag), get_query(ql, qh, mid, high, 2 * pos + 2, flag));
    }

    void update(int ql, int qh, int low, int high, int val, int pos)
    {
        int mid = (high + low) / 2;

        if(lazy[pos] != 0)
        {
            seg[pos] = max(seg[pos], lazy[pos]);

            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] = max(lazy[pos], lazy[2 * pos + 1]);
                lazy[2 * pos + 2] = max(lazy[pos], lazy[2 * pos + 2]);
            }

            lazy[pos] = 0;
        }

        if (qh <= low || ql >= high) ///no overlap
            return ;

        if(low >= ql && high <= qh) ///total overlap
        {
            seg[pos] = max(val, seg[pos]);

            if(high != low + 1)
            {
                lazy[2 * pos + 1] = max(val, lazy[2 * pos + 1]);
                lazy[2 * pos + 2] = max(val, lazy[2 * pos + 2]);
            }
            return;
        }

        update(ql, qh, low, mid, val, 2 * pos + 1);
        update(ql, qh, mid, high, val, 2 * pos + 2);

        seg[pos] = max(seg[2 * pos + 1], seg[2 * pos + 2]);

        return;
    }

};

template <typename type>
void merge_sort(int start, int last, type array, type swap);
int bin_search(int x);

int array[MAX], n, sorted[MAX], tmp[MAX], j = 0, z, y;
seg_tree ans, indx;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]), sorted[i] = array[i];

    merge_sort(0, n - 1, sorted, tmp);
    int i = 0, prev = sorted[0];
    while(i < n)
    {
        if(sorted[i] != prev)
            sorted[j++] = prev, prev = sorted[i];
        i++;
    }
    sorted[j++] = prev;

    ans.flag = 0;
    memset(ans.seg, 0, sizeof(ans.seg));

    indx.flag = 1;
    for(int i = 0; i < 4 * MAX; i++)
        indx.seg[i] = n;

    for(int i = n - 1; i >= 0; i--)
    {
        tmp[i] = 1;
        y = bin_search(array[i]);
        if(y != -1)
        {
            z = indx.get_query(0, y, 0, j, 0);
            if(z == inf)
                z = n - 1;
            else
                z--;
            //printf("%d %d\n",array[i],z);

            if(z - i > 0)
                tmp[i] += z - i;
            //  printf("%d %d\n", array[i], tmp[i]);

        }
        indx.update(y, i, 0, j, 0);
    }

    indx.flag = 0;
    memset(indx.seg, 0, sizeof(indx.seg));
    for(int i = 0; i < 4 * MAX; i++)
        indx.seg[i] = -1 * inf;

    for(int i = 0; i < n; i++)
    {
        y = bin_search(array[i]);
        if(y != -1)
        {
            z = indx.get_query(0, y, 0, j, 0);
            if(z == -1 * inf)
                z = 0;
            else
                z++;

            if(i - z > 0)
                tmp[i] += i - z;
            // printf("====%d %d\n", array[i], tmp[i]);

        }
        indx.update(y, i, 0, j, 0);

        ans.update(1, tmp[i] + 1, 0, n + 1, array[i], 0);
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", ans.get_query(i, i + 1, 0, n + 1, 0, 1));

    return 0;
}

int bin_search(int x)
{
    int small = 0, big = j - 1, mid;

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(sorted[mid] == x)
            return mid;

        if(sorted[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return -1;
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

