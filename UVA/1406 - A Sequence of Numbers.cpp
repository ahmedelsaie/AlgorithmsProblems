#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX1 100009
#define MAX2 (1<<17)+9

///segment_tree
struct seg_tree
{
    ll seg[4 * MAX2], lazy[4 * MAX2];

    void construct_segtree(int array[], int start, int end, int pos)
    {
        if(end == start + 1)
            seg[pos] = 0, lazy[pos] = 0;
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(array, start, mid, 2 * pos + 1);
            construct_segtree(array, mid, end, 2 * pos + 2);
            ll t1 = seg[2 * pos + 1];
            ll t2 = seg[2 * pos + 2];
            seg[pos] = t1 + t2;
        }
    }

    ll get_query(int ql, int qh, int low, int high, int pos)
    {
        if(lazy[pos] != 0)
        {
            seg[pos] += lazy[pos];

            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }

            lazy[pos] = 0;
        }

        if (qh <= low || ql >= high) ///no overlap
            return 0;

        if(low >= ql && high <= qh) ///total overlap
            return seg[pos];

        int mid = (low + high) / 2;

        ///partial overlap
        return get_query(ql, qh, low, mid, 2 * pos + 1) + get_query(ql, qh, mid, high, 2 * pos + 2);
    }

    void update(int ql, int qh, int low, int high, ll val, int pos)
    {
        int mid = (high + low) / 2;

        if(lazy[pos] != 0)
        {
            seg[pos] += lazy[pos];

            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }

            lazy[pos] = 0;
        }

        if (qh <= low || ql >= high) ///no overlap
            return ;

        if(low >= ql && high <= qh) ///total overlap
        {
            seg[pos] += val;

            if(high != low + 1)
            {
                lazy[2 * pos + 1] += val;
                lazy[2 * pos + 2] += val;
            }
            return;
        }

        update(ql, qh, low, mid, val, 2 * pos + 1);
        update(ql, qh, mid, high, val, 2 * pos + 2);

        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];

        return;
    }

};

void fill(int first, int sec, int rem, int bit, int val);
void pre_process();

int array[MAX1], n;
int work[MAX2];
ll ans[17][MAX2];
char input[10];
seg_tree tree;
ll ret, add,x;

int main()
{
    int cases = 1;
    while(scanf("%d", &n) == 1 && n != -1)
    {
        ret = 0, add = 0;
        // scanf("%d", &n);
    if(n <0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        pre_process();
        while(true)
        {
            scanf("%s", input);
            if(input[0] == 'E')
                break;

            scanf("%lld", &x);
            if(input[0] == 'C')
                add += x;
            else
            {
                //x--;
                int t=(int)x;
                ll y = add % (ll)(2 * (1 << t));
                ret += (ll) ans [x][y];
            }
        }

        printf("Case %d: %lld\n", cases++, ret);
    }

    return 0;
}

void pre_process()
{
   // memset(ans, 0, sizeof(ans));

    for(int bit = 0; bit <= 15; bit++)
    {
        int rem = (1 << bit) * 2, first, sec;
        tree.construct_segtree(array, 0, rem, 0);

        //printf("top %d %d\n", bit, rem);

        ///fitting numbers
        for(int i = 0; i <= rem; i++)
            work[i] = 0;
        //memset(work, 0, sizeof(work));
        for(int i = 0; i < n; i++)
            work[array[i] % rem]++;

        first = (1 << bit), sec = rem - 1;

        ///working algo
        for(int i = 0; i < rem; i++)
        {
            //  printf("first %d sec %d\n", first, sec);
            fill(first, sec, rem, bit, work[i]);
            first = (first - 1 + rem) % rem;
            sec = (sec - 1 + rem) % rem;
        }

        for(int i = 0; i < rem; i++)
            ans[bit][i] =(ll) tree.get_query(i, i + 1, 0, rem, 0);

    }
}

void fill(int first, int sec, int rem, int bit, int val)
{
    if(first <= sec)
    {
        tree.update(first, sec + 1, 0, rem, val, 0);
        // for(int i = first; i <= sec; i++)
        //   ans[bit][i] += val;
    }
    else
    {
        tree.update(0, sec + 1, 0, rem, val, 0);
        //    for(int i = 0; i <= sec; i++)
        //      ans[bit][i] += val;

        tree.update(first, rem, 0, rem, val, 0);
        // for(int i = first; i < rem; i++)
        //   ans[bit][i] += val;
    }
}
