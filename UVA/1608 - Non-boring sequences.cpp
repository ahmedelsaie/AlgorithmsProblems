#include <bits/stdc++.h>
using namespace std;
#define MAX 200009
#define ll long long

int n;
const int inf = (1 << 30);

///segment_tree
struct seg_tree2
{
    int seg[4 * MAX], lazy[4 * MAX], flag;

    void construct_segtree(int arr[], int start, int end, int pos)
    {
        if(end == start + 1)
            seg[pos] = 0, lazy[pos] = 0;
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(arr, start, mid, 2 * pos + 1);
            construct_segtree(arr, mid, end, 2 * pos + 2);
            int t1 = seg[2 * pos + 1];
            int t2 = seg[2 * pos + 2];
            seg[pos] = lazy[pos] = 0;
        }
    }

    int get_query(int ql, int qh, int low, int high, int pos)
    {
        if(lazy[pos] != 0)
        {
            seg[pos] = max(seg[pos], lazy[pos]);

            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] = max(lazy[pos], lazy[2 * pos + 1]) ;
                lazy[2 * pos + 2] = max(lazy[pos], lazy[2 * pos + 2]) ;
            }

            lazy[pos] = 0;
        }

        if (qh <= low || ql >= high) ///no overlap
            return inf;

        if(low >= ql && high <= qh) ///total overlap
            return seg[pos];

        int mid = (low + high) / 2;

        ///partial overlap
        return min(get_query(ql, qh, low, mid, 2 * pos + 1), get_query(ql, qh, mid, high, 2 * pos + 2));
    }

    void update(int ql, int qh, int low, int high, int val, int pos)
    {
        int mid = (high + low) / 2;

        if(lazy[pos] != 0)
        {
            seg[pos] = max(seg[pos], lazy[pos]);

            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] = max(lazy[pos], lazy[2 * pos + 1]) ;
                lazy[2 * pos + 2] = max(lazy[pos], lazy[2 * pos + 2]) ;
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

        seg[pos] = min(seg[2 * pos + 1], seg[2 * pos + 2]);

        return;
    }

};

int get_indx(int x);
void pre_process();
int fn();

pair<int, int> arr[MAX], arr2[MAX];
int  cases, j, diff[MAX];
seg_tree2 tree2;
vector<int> vec[MAX];

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i].first), arr[i].second = i;

        pre_process();

        printf("%s\n", fn() == 0 ? "boring" : "non-boring");

        for(int i = 0; i < n; i++)
            vec[i].clear();
    }

    return 0;
}

int fn()
{
    int right, left;

    for(int i = 0; i < n; i++)
    {
        int tmp = get_indx(arr[i].first);
        if(arr[i].second + 1 < vec[tmp].size())
            right = vec[tmp][arr[i].second + 1] - 1;
        else
            right = n;

        if(arr[i].second == 0)
            left = 0;
        else
            left = vec[tmp][arr[i].second - 1] + 1;

        tmp = -inf;

        tmp = tree2.get_query(left, i, 0, n, 0);
        if(tmp < i)
            return 0;

        tree2.update(left, i + 1, 0, n, right, 0);
    }

    if(tree2.get_query(0, n, 0, n, 0) != n)
        return 0;

    return 1;
}

void pre_process()
{
    for(int i = 0; i < n; i++)
        arr2[i] = arr[i];

    sort(arr2, arr2 + n);

    j = 0;
    int i = 0, prev = arr2[0].first, accum = 0;

    while(i < n)
    {
        if(prev != arr2[i].first)
            diff[j++] = prev, prev = arr2[i].first, accum = 0;

        arr[arr2[i].second].second = accum;
        accum++;
        i++;
    }

    diff[j++] = prev;

    for(int i = 0; i < n; i++)
    {
        int tmp = get_indx(arr2[i].first);
        vec[tmp].push_back(arr2[i].second);
    }

    int h[MAX];
    tree2.construct_segtree(h, 0, n, 0);
    return ;
}

int get_indx(int x)
{
    int small = 0, big = j - 1, mid;
    while(big >= small)
    {
        mid = (small + big) / 2;

        if(diff[mid] == x)
            return mid;

        if(diff[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return -1;
}
