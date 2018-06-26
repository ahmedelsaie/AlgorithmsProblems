#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 1024009

void update(int seg[], int ql, int qh, int low, int high, int val, int pos);
pair<int, int> add3(pair<int, int> newx, pair<int, int> oldx);
int add1(pair<int, int> x, int l, int prev);
void construct_segtree(int arr2[], int seg_tree[], int start, int end, int pos);
int get_query(int seg_tree[], int ql, int qh, int low, int high, int pos);

pair<int, int> lazy[4 * MAX];
int array[MAX], seg_tree[4 * MAX], n, n_queries, visited[4 * MAX];

int main()
{
    char input[200];
    int x, y, n_tmp, tmp_l, cases, p = 1, q;

    scanf("%d", &cases);
    while(cases--)
    {
        q = 1, n = 0;
        scanf("%d", &n_tmp);
        for(int i = 0; i < n_tmp; i++)
        {
            scanf("%d %s", &x, input);
            tmp_l = strlen(input);

            for(int k = 0; k < x; k++)
                for(int j = 0; j < tmp_l; j++)
                    array[n] = input[j] - '0', n++;
        }

        construct_segtree(array, seg_tree, 0, n, 0);

        printf("Case %d:\n", p++, n);

        scanf("%d", &n_queries);
        for(int i = 0; i < n_queries; i++)
        {
            scanf("%s %d %d", input, &x, &y);
            if(input[0] == 'I')
                update(seg_tree, x, y + 1, 0, n, 0, 0);
            else if(input[0] == 'F')
                update(seg_tree, x, y + 1, 0, n, 1, 0);
            else if(input[0] == 'E')
                update(seg_tree, x, y + 1, 0, n, 2, 0);
            else
                printf("Q%d: %d\n", q++, get_query(seg_tree, x, y + 1 , 0, n, 0));
        }
    }

    return 0;
}

int get_query(int seg[], int ql, int qh, int low, int high, int pos)
{
    pair<int, int> tmp;
    tmp.first = tmp.second = -1;

    if(lazy[pos].first != -1 || lazy[pos].second != -1)
    {
        seg[pos] = add1(lazy[pos], high - low, seg[pos]);

        if(high != low + 1) ///children exist
        {
            lazy[2 * pos + 1] = add3(lazy[pos], lazy[2 * pos + 1]);
            lazy[2 * pos + 2] = add3(lazy[pos], lazy[2 * pos + 2]);
        }

        lazy[pos].first = lazy[pos].second = -1;
    }

    if (qh <= low || ql >= high) ///no overlap
        return 0;

    if(low >= ql && high <= qh) ///total overlap
        return seg[pos];

    int mid = (low + high) / 2;

    ///partial overlap
    return get_query(seg, ql, qh, low, mid, 2 * pos + 1) + get_query(seg, ql, qh, mid, high, 2 * pos + 2);
}

void update(int seg[], int ql, int qh, int low, int high, int val, int pos)
{
    pair<int, int> tmp;
    tmp.first = tmp.second = -1;

    int mid = (high + low) / 2;

    if(lazy[pos].first != -1 || lazy[pos].second != -1)
    {
        seg[pos] = add1(lazy[pos], high - low, seg[pos]);

        if(high != low + 1) ///children exist
        {
            lazy[2 * pos + 1] = add3(lazy[pos], lazy[2 * pos + 1]);
            lazy[2 * pos + 2] = add3(lazy[pos], lazy[2 * pos + 2]);
        }

        lazy[pos].first = lazy[pos].second = -1;
    }

    if (qh <= low || ql >= high) ///no overlap
        return ;

    if(low >= ql && high <= qh) ///total overlap
    {
        if(val == 0)
            tmp.second = 1;
        else
            tmp.first = val;
        seg[pos] = add1(tmp, high - low, seg[pos]);

        if(high != low + 1)
        {
            lazy[2 * pos + 1] = add3(tmp, lazy[2 * pos + 1]);
            lazy[2 * pos + 2] = add3(tmp, lazy[2 * pos + 2]);
        }
        return;
    }

    update(seg, ql, qh, low, mid, val, 2 * pos + 1);
    update(seg, ql, qh, mid, high, val, 2 * pos + 2);

    seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];

    return;
}

pair<int, int> add3(pair<int, int> newx, pair<int, int> oldx)
{
    if(newx.first != -1) ///new apply
        return newx;
    else if(newx.second != -1)
    {
        if(oldx.second != -1) ///second has reverse
            oldx.second = -1;
        else                 ///second dont have reverse
            oldx.second = 1;
        return oldx;
    }

}

int add1(pair<int, int> x, int l, int prev)
{
    int ret = prev;

    if(x.first != -1)
    {
        if(x.first == 1)
            ret = l;
        else
            ret = 0;
    }

    if(x.second != -1)
        ret = l - ret;
    return ret;

}

void construct_segtree(int arr2[], int seg_tree[], int start, int end, int pos)
{
    lazy[pos].first = lazy[pos].second = -1;

    if(end == start + 1)
        seg_tree[pos] = arr2[start];
    else
    {
        int mid = (start + end) / 2;
        construct_segtree(arr2, seg_tree, start, mid, 2 * pos + 1);
        construct_segtree(arr2, seg_tree, mid, end, 2 * pos + 2);
        seg_tree[pos] = seg_tree[2 * pos + 1] + seg_tree[2 * pos + 2];
    }
}
