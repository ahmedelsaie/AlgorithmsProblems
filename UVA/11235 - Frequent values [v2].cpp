#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 100009

void construct_segtree(pair<int, int> arr2[], int seg_tree[], int start, int end, int pos);
int get_query(int seg_tree[], int ql, int qh, int low, int high, int pos);
int bin_search(int x);
int fn_ans(int small, int big);

int array[MAX], seg_tree[4 * MAX];
int n, j, n_queries, small, big;
const int inf = 999999999;
pair<int, int> arr2[MAX];

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        scanf("%d", &n_queries);

        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);

        ///run length encoding
        int prev = array[0], start = 0, end = 0, i = 0;
        j = 0;

        while(i < n)
        {
            if(array[i] == prev)
                end = i;
            else
            {
                arr2[j].first = start, arr2[j].second = end + 1;
                j++;
                prev = array[i];
                start = end = i;
            }
            i++;
        }

        arr2[j].first = start, arr2[j].second = end + 1;
        j++;

        construct_segtree(arr2, seg_tree, 0, j, 0);

        for(int i = 0; i < n_queries; i++)
            scanf("%d %d", &small, &big), printf("%d\n", fn_ans(--small, big));

    }

    return 0;
}

int fn_ans(int small, int big)
{
    int first, second, ret = -1 * inf;
    first = bin_search(small);
    second = bin_search(big);

    //printf("%d %d\n", first, second);
    if(first != -1)
    {
        int tmp1 = max(arr2[first].first, small);
        int tmp2 = min(arr2[first].second, big);
        ret = max(ret, tmp2 - tmp1);
        //printf("sf %d %d  %d\n", tmp1, tmp2, ret);
    }

    if(second != -1)
    {
        int tmp1 = max(arr2[second].first, small);
        int tmp2 = min(arr2[second].second, big);
        ret = max(ret, tmp2 - tmp1);
    }

    if(second > first + 1)
        ret = max(ret, get_query(seg_tree, first + 1, second, 0, j, 0));

    return ret;
}

int bin_search(int x)
{
    int big = j - 1, small = 0, mid, val = -1 * inf, ret = 1;

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(arr2[mid].first <= x)
        {
            if(arr2[mid].first > val)
                val = arr2[mid].first, ret = mid;
            small = mid + 1;
        }
        else
            big = mid - 1;
    }

    return ret;
}

void construct_segtree(pair<int, int> arr2[], int seg_tree[], int start, int end, int pos)
{
    if(end == start + 1)
        seg_tree[pos] = arr2[start].second - arr2[start].first;
    else
    {
        int mid = (start + end) / 2;
        construct_segtree(arr2, seg_tree, start, mid, 2 * pos + 1);
        construct_segtree(arr2, seg_tree, mid, end, 2 * pos + 2);
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
