#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 50009

struct seg_tree
{
    int seg[4 * MAX];

    void construct_segtree(int arr[], int start, int end, int pos)
    {
        if(end == start + 1)
            seg[pos] = 1;
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(arr, start, mid, 2 * pos + 1);
            construct_segtree(arr, mid, end, 2 * pos + 2);
            seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
        }
    }

    int get_query(int ql, int qh, int low, int high, int pos)
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

            seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
        }
    }

};

int bin_search(int y);

seg_tree x;

int arr[MAX], n, tmp, cases;

int main()
{
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]), arr[i]++;

        x.construct_segtree(arr, 0, n, 0);

        for(int i = 0; i < n; i++)
        {
            tmp = bin_search(arr[i]);
            if(i)
                printf(" ");
            printf("%d", tmp);
            x.update(tmp - 1, 0, 0, n, 0);
        }

        printf("\n");
    }

    return 0;
}

int bin_search(int y)
{
    int big = n, small = 0, mid, tmp, ret;

    while(big >= small)
    {
        mid = (big + small) / 2;
        tmp = x.get_query(0, mid, 0, n, 0);

        if(tmp == y)
            ret = mid;

        if(tmp >= y)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return ret;
}

