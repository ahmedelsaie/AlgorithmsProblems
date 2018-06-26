#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 200009

const int inf = 2289999;

///segment_tree
struct seg_tree
{
    int seg[4 * MAX];

    void construct_segtree(int array[], int start, int end, int pos)
    {
        if(end == start + 1)
            seg[pos] = start;
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(array, start, mid, 2 * pos + 1);
            construct_segtree(array, mid, end, 2 * pos + 2);
            seg[pos] = min(seg[2 * pos + 1], seg[2 * pos + 2]);
        }
    }

    int get_query(int ql, int qh, int low, int high, int pos)
    {
        ///no overlap
        if (qh <= low || ql >= high)
            return inf;

        ///total overlap
        if(low >= ql && high <= qh)
            return seg[pos];

        int mid = (low + high) / 2;

        ///partial overlap
        return min(get_query(ql, qh, low, mid, 2 * pos + 1), get_query(ql, qh, mid, high, 2 * pos + 2));
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

            seg[pos] = min(seg[2 * pos + 1], seg[2 * pos + 2]);
        }
    }

};
void pour(int i, ll x);

ll array[MAX], state[MAX], x, m, tmp;
int n, j, help[MAX];
seg_tree tree;

int main()
{
    memset(state, 0, sizeof(state));

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &array[i]);

    tree.construct_segtree(help, 0, n, 0);

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        if(tmp == 1)
            scanf("%d %lld", &j, &x), pour(j - 1, x);
        else
            scanf("%d", &j), printf("%lld\n", state[j - 1]);
    }

    return 0;
}

void pour(int i, ll x)
{
    int j = i;

    while(x)
    {
        j = tree.get_query(j, n, 0, n, 0);
        if(j == inf)
            break;

      //  printf("njnjn %d\n",j);
        ll left = array[j] - state[j];
        if(left <= x)
        {
            state[j] = array[j];
            x -= left;
            tree.update(j, inf, 0, n, 0);
        }
        else
            state[j] += x, x = 0;
    }

}
