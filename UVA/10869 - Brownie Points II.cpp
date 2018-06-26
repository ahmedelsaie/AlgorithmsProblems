#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define MAX 200009

///segment_tree
struct seg_tree
{
    int seg[4 * MAX];

    void construct_segtree(int array[], int start, int end, int pos)
    {
        if(end == start + 1)
            seg[pos] = 0;
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(array, start, mid, 2 * pos + 1);
            construct_segtree(array, mid, end, 2 * pos + 2);
            seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
        }
    }

    int get_query(int ql, int qh, int low, int high, int pos)
    {
        ///no overlap
        if (qh <= low || ql >= high || low == high || ql == qh)
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
        if(low == high)
            return;

        if(indx == low && high == low + 1)
            seg[pos] += val;
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

struct node
{
    int first, second, id;
};

int RLC(int diff[]);
int bin_search(int x, int diff[], int n);
void pre_process();
int fn();
int RLC(int diff[], int n);

node array[MAX], sorted_x[MAX], sorted_y[MAX];
int diff_x[MAX], diff_y[MAX], n_x, n_y;
seg_tree tree;
int left1[MAX], right1[MAX], left2[MAX], right2[MAX], n, que[MAX], ans[6 * MAX];
const int inf = 99899999;
int freq[MAX];
int k = 0;
int nw[6 * MAX];

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &array[i].first, &array[i].second), array[i].id = i;
            sorted_x[i] = sorted_y[i] = array[i];
            diff_x[i] = array[i].first;
            diff_y[i] = array[i].second;
        }

        pre_process();
        int a = fn();
        sort(ans, ans + k);
        printf("Stan: %d; Ollie:", a);
        k = RLC(ans, k);
        for(int i = 0; i < k; i++)
            printf(" %d", ans[i]);
        printf(";\n");
    }
    return 0;
}

int RLC(int diff[], int n)
{
    sort(diff, diff + n);
    int i = 0, prev = diff[0], j = 0;

    while(i < n)
    {
        if(prev != diff[i])
            diff[j++] = prev, prev = diff[i];
        i++;
    }

    diff[j++] = prev;
    return j;
}

bool comp(node x, node y)
{
    if(x.second == y.second)
        return (x.first < y.first);
    return x.second < y.second;
}

bool comp2(node x, node y)
{
    if(x.first == y.first)
        return x.second < y.second;
    return (x.first < y.first);
}

bool comp3(node x, node y)
{
    if(x.second == y.second)
        return (x.first > y.first);
    return x.second < y.second;
}

bool comp4(node x, node y)
{
    if(x.second == y.second)
        return (x.first > y.first);
    return x.second > y.second;
}

bool comp5(node x, node y)
{
    if(x.second == y.second)
        return (x.first < y.first);
    return x.second > y.second;
}

void pre_process()
{
    n_x = RLC(diff_x, n);
    n_y = RLC(diff_y, n);
    sort(sorted_y, sorted_y + n, comp);
    sort(sorted_x, sorted_x + n, comp2);

    ///left2

    tree.construct_segtree(diff_x, 0, n_x, 0);
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < n; i++)
    {
        int idx = bin_search(sorted_y[i].first, diff_x, n_x);
        int idy = bin_search(sorted_y[i].second, diff_y, n_y) ;

        int tmp = tree.get_query(0, idx, 0, n_x, 0);
        tmp -= freq[idy];
        left2[sorted_y[i].id] = tmp;
        tree.update(idx, 1, 0, n_x, 0);
        freq[idy]++;
    }
    sort(sorted_y, sorted_y + n, comp5);

    ///left1
    tree.construct_segtree(diff_x, 0, n_x, 0);
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < n; i++)
    {
        int idx = bin_search(sorted_y[i].first, diff_x, n_x);
        int idy = bin_search(sorted_y[i].second, diff_y, n_y) ;

        int tmp = tree.get_query(0, idx, 0, n_x, 0);
        tmp -= freq[idy];
        left1[sorted_y[i].id] = tmp;
        tree.update(idx, 1, 0, n_x, 0);
        freq[idy]++;
    }

    sort(sorted_y, sorted_y + n, comp3);

    ///right2

    tree.construct_segtree(diff_x, 0, n_x, 0);
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < n; i++)
    {
        int idx = bin_search(sorted_y[i].first, diff_x, n_x);
        int idy = bin_search(sorted_y[i].second, diff_y, n_y) ;

        int tmp = tree.get_query(idx + 1, n_x, 0, n_x, 0);
        tmp -= freq[idy];
        tree.update(idx, 1, 0, n_x, 0);
        right2[sorted_y[i].id] = tmp;
        freq[idy]++;
    }

    sort(sorted_y, sorted_y + n, comp4);

    ///right1
    tree.construct_segtree(diff_x, 0, n_x, 0);
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < n; i++)
    {
        int idx = bin_search(sorted_y[i].first, diff_x, n_x);
        int idy = bin_search(sorted_y[i].second, diff_y, n_y) ;

        int tmp = tree.get_query(idx + 1, n_x, 0, n_x, 0);
        tmp -= freq[idy];
        tree.update(idx, 1, 0, n_x, 0);
        right1[sorted_y[i].id] = tmp;
        freq[idy]++;
    }


}

int bin_search(int x, int diff[], int n)
{
    int small = 0, big = n - 1, mid;

    while(big >= small)
    {
        mid = (big + small) / 2;

        if(diff[mid] == x)
            return mid;

        if(diff[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }

}

int fn()
{
    ///work on sorted _x
    k = 0;
    int i = 0, prev = inf, j = 0;
    int big_stan = -1 * inf;
    int small_stan = -inf;
    int stan, olie;
    int  p = 0;

    while(i < n)
    {
        int id = sorted_x[i].id;
        stan = right1[id] + left2[id];
        olie = right2[id] + left1[id];
        if(prev == sorted_x[i].first)
        {
            if(stan == small_stan)
                nw[p++] = olie;

            if(stan < small_stan)
                small_stan = stan, p = 1, nw[0] = olie;
        }
        else
        {
            if(small_stan == big_stan)
            {
                int g = 0;
                for(int i = k; i < k + p; i++)
                    ans[i] = nw[g++];
                k += p;
            }

            if(small_stan > big_stan)
            {
                big_stan = small_stan;
                k = p;
                for(int i = 0; i < p; i++)
                    ans[i] = nw[i];
            }

            small_stan = stan;
            prev = sorted_x[i].first;
            p = 1, nw[0] = olie;
        }

        i++;
    }

    if(small_stan == big_stan)
    {
        int g = 0;
        for(int i = k; i < k + p; i++)
            ans[i] = nw[g++];
        k += p;
    }

    if(small_stan > big_stan)
    {
        big_stan = small_stan;
        k = p;
        for(int i = 0; i < p; i++)
            ans[i] = nw[i];
    }

    return big_stan;
}
