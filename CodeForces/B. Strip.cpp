#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 100009

const int inf = (1 << 30);

///segment_tree
struct seg_tree
{
    int seg[4 * MAX], flag;

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

};

int bin_search(int i);

int array[MAX], indx[MAX], n, val, l, zeros[MAX];
seg_tree big, small, ans;

int main()
{
    scanf("%d %d %d", &n, &val, &l);
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]), zeros[i] = inf;

    big.flag = 0, small.flag = 1;
    big.construct_segtree(array, 0, n, 0);
    small.construct_segtree(array, 0, n, 0);

    for(int i = 0; i < n; i++)
        indx[i] = bin_search(i);

    ans.flag = 1;
    ans.construct_segtree(zeros, 0, n, 0);

    for(int i = n - 1; i >= 0; i--)
    {
        if(indx[i] == -1)
            continue;

        int s = i + l;
        int b = indx[i];

        int tmp = ans.get_query(s , b + 1, 0, n, 0);

        if(b == n)
            tmp = 0;

        tmp++;
        ans.update(i, tmp, 0, n, 0);
    }

    int res = ans.get_query(0, 1, 0, n, 0);

    printf("%d\n", res == inf ? -1 : res);

    return 0;
}

int bin_search(int i)
{
    int b = n, s = i + l, mid, ret = i, tmp1, tmp2;

    ///check
    tmp2 = big.get_query(i, s, 0, n, 0);
    tmp1 = small.get_query(i, s, 0, n, 0);

    if(tmp2 - tmp1 > val || s > n)
        return -1;

    while(b >= s)
    {
        mid = (b + s) / 2;

        tmp2 = big.get_query(i, mid, 0, n, 0);
        tmp1 = small.get_query(i, mid, 0, n, 0);

        if(tmp2 - tmp1 <= val)
            s = mid + 1, ret = max(ret, mid);
        else
            b = mid - 1;
    }

    return ret;
}
