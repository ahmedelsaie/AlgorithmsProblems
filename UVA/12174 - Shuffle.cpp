#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 100009

const int inf = (1 << 31) - 1;

struct seg_tree
{
    int seg[4 * MAX];

    void construct_segtree(int arr[], int start, int end, int pos)
    {
        if(end == start)
            seg[pos] = arr[start];
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(arr, start, mid, 2 * pos);
            construct_segtree(arr, mid + 1, end, 2 * pos + 1);
            seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
        }
    }

    int get_query(int ql, int qh, int low, int high, int pos)
    {
        ///no overlap
        if (qh < low || ql > high)
            return inf;

        ///total overlap
        if(low >= ql && high <= qh)
            return seg[pos];

        int mid = (low + high) / 2;

        ///partial overlap
        return  min(get_query(ql, qh, low, mid, 2 * pos), get_query(ql, qh, mid + 1, high, 2 * pos + 1));
    }

};

int check(int start);

int nxt[MAX], prev1[MAX], arr[MAX], n, diff, ans, cases;
seg_tree x;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        memset(prev1, -1, sizeof(prev1));
        fill(nxt, nxt + MAX, inf);

        ans = 0;

        scanf("%d %d", &diff, &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);

        for(int i = 1; i <= n; i++)
        {
            if(prev1[arr[i]] != -1)
                nxt[prev1[arr[i]]] = i;

            prev1[arr[i]] = i;
        }

        x.construct_segtree(nxt, 1, n, 1);
        for(int i = 1; i <= diff; i++)
            if(check(i))
                ans++;

        printf("%d\n", ans);
    }

    return 0;
}

int check(int start)
{
    ///first check
    int i = min(n, diff - start) + 1;
    int tmp = x.get_query(1, i, 1, n, 1);

    if(tmp <= i)
        return 0;

    i++;
    while(i <= n)
    {
        int last = min(n, i + diff - 1);
        tmp = x.get_query(i, last, 1, n, 1);

        if(tmp <= last)
            return 0;

        i += diff;
    }

    return 1;
}
