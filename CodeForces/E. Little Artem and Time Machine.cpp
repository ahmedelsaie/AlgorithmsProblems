#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

const int inf = 999999999;

///segment_tree
struct seg_tree
{
    int seg[4 * MAX], lazy[4 * MAX];

    void construct_segtree(int start, int end, int pos)
    {
        lazy[pos] = -inf;
        if(end == start + 1)
            seg[pos] = 0;
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(start, mid, 2 * pos + 1);
            construct_segtree(mid, end, 2 * pos + 2);
            int t1 = seg[2 * pos + 1];
            int t2 = seg[2 * pos + 2];
            seg[pos] = t1 + t2;
        }
    }

    int get_query(int ql, int qh, int low, int high, int pos)
    {
        if(lazy[pos] != -inf)
        {
            seg[pos] += lazy[pos];

            if(high != low + 1) ///children exist
            {
                add_lazy(2 * pos + 1, lazy[pos]);
                add_lazy(2 * pos + 2, lazy[pos]);
            }

            lazy[pos] = -inf;
        }

        if (qh <= low || ql >= high) ///no overlap
            return 0;

        if(low >= ql && high <= qh) ///total overlap
            return seg[pos];

        int mid = (low + high) / 2;

        ///partial overlap
        return get_query(ql, qh, low, mid, 2 * pos + 1) + get_query(ql, qh, mid, high, 2 * pos + 2);
    }

    void update(int ql, int qh, int low, int high, int val, int pos)
    {
        int mid = (high + low) / 2;

        if(lazy[pos] != -inf)
        {
            seg[pos] += lazy[pos];

            if(high != low + 1) ///children exist
            {
                add_lazy(2 * pos + 1, lazy[pos]);
                add_lazy(2 * pos + 2, lazy[pos]);
            }

            lazy[pos] = -inf;
        }

        if (qh <= low || ql >= high) ///no overlap
            return ;

        if(low >= ql && high <= qh) ///total overlap
        {
            seg[pos] += val;

            if(high != low + 1)
            {
                add_lazy(2 * pos + 1, val);
                add_lazy(2 * pos + 2, val);
            }
            return;
        }

        update(ql, qh, low, mid, val, 2 * pos + 1);
        update(ql, qh, mid, high, val, 2 * pos + 2);

        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];

        return;
    }

private:
    void  add_lazy(int place, int val)
    {
        if(lazy[place] == -inf)
            lazy[place] = val;
        else
            lazy[place] += val;
    }
};

struct Query
{
    int time, val, type;
};

void pre_process();
int cnt(int x, int moment);
void update(int x, int moment, int type);
int bin_search(int x, int time);

Query queries[MAX];
seg_tree tree;
pair<int, int> arr[MAX];
int n, m;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", &queries[i].type, &queries[i].time, &queries[i].val);

    pre_process();

    for(int i = 0; i < n; i++)
    {
        if(queries[i].type == 1)
            update(queries[i].val, queries[i].time, 1);
        else   if(queries[i].type == 2)
            update(queries[i].val, queries[i].time, -1);
        else
            printf("%d\n", cnt(queries[i].val, queries[i].time));
    }

    return 0;
}

void pre_process()
{
    for(int i = 0; i < n; i++)
        arr[i].first = queries[i].val, arr[i].second = queries[i].time;

    sort(arr, arr + n);

    int i = 0, k = 0;
    pair<int, int> prev;
    prev.first = prev.second = -1;

    while(i < n)
    {
        if(prev.first != arr[i].first || prev.second != arr[i].second)
        {
            prev = arr[i];
            arr[k++] = arr[i];
        }

        i++;
    }

    m = k;

    tree.construct_segtree(0, m, 0);
}

int cnt(int x, int moment)
{
    int indx = bin_search(x, moment);
    // printf("------------- %d\n",indx);
    return tree.get_query(indx, indx + 1, 0, n, 0);
}

void update(int x, int moment, int type)
{
    int start = bin_search(x, moment);
    int end = bin_search(x,inf);

    tree.update(start, end + 1, 0, n, type, 0);
}

int bin_search(int x, int time)
{
    int s = 0, b = m, ret = -1, ret_val = -inf;

    while(b >= s)
    {
        int mid = (b + s) / 2;
        if(arr[mid].first == x && arr[mid].second == time)
            return mid;

        if(arr[mid].first == x)
        {
            if(ret_val <= arr[mid].second)
                ret_val = arr[mid].second, ret = max(mid, ret);
        }

        if((arr[mid].first < x) || (arr[mid].first == x && arr[mid].second < time))
            s = mid + 1;
        else
            b = mid - 1;
    }

    return ret;
}
