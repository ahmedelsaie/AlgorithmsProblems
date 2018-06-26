#include <bits/stdc++.h>
using namespace std;
#define MAX 200009
#define MAX2 200009
#define ll long long

const ll inf = 9223372036854775807;

///segment_tree
struct sum_tree
{
    ll seg[4 * MAX2], lazy[4 * MAX2];

    void construct_segtree(ll array[], int start, int end, int pos)
    {
        lazy[pos] = 0;
        if(end == start + 1)
            seg[pos] = 0;
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

            seg[pos] += (high - low) * lazy[pos];
            if(seg[pos] < 0) 5 / 0;
            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];

                if(lazy[2 * pos + 2] < 0 || lazy[2 * pos + 2]) 5 / 0;
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
            seg[pos] += (high - low) * lazy[pos];
            if(seg[pos] < 0) 5 / 0;
            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];

                if(lazy[2 * pos + 2] < 0 || lazy[2 * pos + 2]) 5 / 0;
            }

            lazy[pos] = 0;
        }

        if (qh <= low || ql >= high) ///no overlap
            return ;

        if(low >= ql && high <= qh) ///total overlap
        {
            seg[pos] += (high - low) * val;
            if(seg[pos] < 0) 5 / 0;
            if(high != low + 1)
            {
                lazy[2 * pos + 1] += val;
                lazy[2 * pos + 2] += val;

                if(lazy[2 * pos + 2] < 0 || lazy[2 * pos + 2]) 5 / 0;

            }
            return;
        }

        update(ql, qh, low, mid, val, 2 * pos + 1);
        update(ql, qh, mid, high, val, 2 * pos + 2);

        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
        if(seg[pos] < 0) 5 / 0;
        return;
    }

};

///the problem is here
///segment_tree
struct max_tree
{
    int seg[4 * MAX2];
    ll val[4 * MAX2], lazy[4 * MAX2];

    void construct_segtree(ll array[], int start, int end, int pos)
    {
        lazy[pos] = 0;
        if(end == start + 1)
            seg[pos] = start, val[pos] = 0;
        else
        {
            int mid = (start + end) / 2;
            construct_segtree(array, start, mid, 2 * pos + 1);
            construct_segtree(array, mid, end, 2 * pos + 2);
            ll t1 = seg[2 * pos + 1];
            ll t2 = seg[2 * pos + 2];
            seg[pos] = (val[2 * pos + 1] >= val[2 * pos + 2] ? t1 : t2);
            val[pos] = max(val[2 * pos + 1], val[2 * pos + 2]);
        }
    }

    pair<ll, int> get_query(int ql, int qh, int low, int high, int pos)
    {
        pair<ll, int> ret;
        ret.first = -inf, ret.second = 4 * MAX2 - 1;

        if(lazy[pos] != 0)
        {
            val[pos] += lazy[pos];

            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }

            lazy[pos] = 0;
        }

        if (qh <= low || ql >= high) ///no overlap
            return ret;

        if(low >= ql && high <= qh) ///total overlap
        {
            ret.first = val[pos], ret.second = seg[pos];
            return ret;
        }

        int mid = (low + high) / 2;

        ///partial overlap
        pair<ll, int> t1 = get_query(ql, qh, low, mid, 2 * pos + 1);
        pair<ll, int> t2 = get_query(ql, qh, mid, high, 2 * pos + 2);

        if(t1.first == t2.first)return t1.second <= t2.second ? t1 : t2;
        return t1.first > t2.first ? t1 : t2;
    }

    void update(int ql, int qh, int low, int high, ll val2, int pos)
    {
        int mid = (high + low) / 2;

        if(lazy[pos] != 0)
        {
            val[pos] += lazy[pos];

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
            val[pos] += val2;

            if(high != low + 1) ///children exist
            {
                lazy[2 * pos + 1] += val2;
                lazy[2 * pos + 2] += val2;
            }

            lazy[pos] = 0;
            return;
        }

        update(ql, qh, low, mid, val2, 2 * pos + 1);
        update(ql, qh, mid, high, val2, 2 * pos + 2);

        val[pos] = max(val[2 * pos + 1], val[2 * pos + 2]);

        if(val[2 * pos + 1] >= val[2 * pos + 2])
            seg[pos] = seg[2 * pos + 1];
        else
            seg[pos] = seg[2 * pos + 2];

        return;
    }

};

ll get(ll x, int mod);
ll fn();
ll gn();
ll fn2();

ll n, k, fives, ones;
ll arr[MAX];
max_tree best_tree;
sum_tree sum;

int main()
{

    scanf("%lld %lld %lld %lld", &n, &k, &fives, &ones);
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    sort(arr, arr + n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    ll ret =  min(fn(), fn2());
    printf("%lld\n", ret);

    return 0;
}

ll get(ll x, int mod)
{
    ll ret = 0;

    while(abs(x % (ll) 5) != mod)
        ret++, x++;

    return ret;
}

ll gn()
{
    ll ret = inf;

    for(int mod = 0; mod < 5; mod++)
    {
        ll last = arr[n - 1] + get(arr[n - 1], mod);
        ll ret1 = 0;
        for(int i = 0; i < n; i++)
        {
            ret1 += get(arr[i], mod) * ones;
            ll diff = get(arr[i], mod);
            if(fives > ones * 5)
                ret1 += abs(((arr[i] + diff - last)) * ones);
            else
                ret1 += abs(((arr[i] + diff - last) / 5) * fives);

        }

        ret = min(ret, ret1);
    }
    return ret;
}

ll fn2()
{
    ///post =0 positive
    ll ret = inf;
    int first = 0;

    for(int mod = 0; mod < 5; mod++)
    {
        //    mod = 3;
        best_tree.construct_segtree(arr, 0, k, 0);
        sum.construct_segtree(arr, 0, k, 0);

        ll with = 0;
        ll last = arr[0] + get(arr[0], mod);
        int i = n;

        for(int j = 0; j < n; j++)
            if(arr[j] + get(arr[j], mod) < 0)
            {
                last = arr[j] + get(arr[j], mod);
                i = j;
                break;
            }
//
        //          printf("%d %lld\n",mod,last);
        for(; i < n; i++)
        {
            ll diff = get(arr[i], mod);

            ll add_before = abs(((arr[i] + diff - last) / 5) * fives);

            if(fives > ones * 5)
                add_before = abs(((arr[i] + diff - last)) * ones);

            if(arr[i] + diff >= 0)
                continue;

            ///update trees
            sum.update(0, k, 0, k, add_before, 0);
            best_tree.update(0, k, 0, k, add_before, 0);

            /*   for(int j = 0; j < k; j++)
                   printf("%lld ", best_tree.get_query(j, j + 1, 0, k, 0));
               printf("\n=========\n");
            */
            ll val = diff * ones;
            pair<ll, int> tmp;
            if(with < k)
                tmp = best_tree.get_query(with, with + 1, 0, k, 0);
            else
                tmp = best_tree.get_query(0, k, 0, k, 0);

            //    printf("i= %d mod = %d with = %lld  tag = %d\n", i, mod, with, tmp.second);
            //       printf("000000000000 %d %d\n", best_tree.get_query(with,with+1,0,k,0).second,tmp.second);

            if(tmp.first >= val || with < k)
            {
                sum.update(tmp.second, tmp.second + 1, 0, k, -tmp.first, 0);

                sum.update(tmp.second, tmp.second + 1, 0, k, val, 0);

                best_tree.update(tmp.second, tmp.second + 1, 0, k, -tmp.first, 0);
                best_tree.update(tmp.second, tmp.second + 1, 0, k, val, 0);
            }
            with = min(with + 1, k);

            if(with >= k) // || with==k)
            {
                //  printf("ret %lld %lld\n",ret, sum.get_query(0, k, 0, k, 0));

                if(first == 0)ret = sum.get_query(0, k, 0, k, 0);
                ret = min(ret, sum.get_query(0, k, 0, k, 0));
                first = 1;
            }

            last = arr[i] + diff;
        }
        // break;
    }
    //printf("%lld\n", ret);
    return ret;
}

ll fn()
{
    ll ret = 0;
    int first = 0;
    ll last2 = n;
    for(int i = 0; i < n; i++)
        if(arr[i] >= 0)
        {
            last2 = arr[i];
            break;
        }

    if(last2 == n)
        return inf;

    for(int mod = 0; mod < 5; mod++)
    {
        // mod = 0;
        best_tree.construct_segtree(arr, 0, k, 0);
        sum.construct_segtree(arr, 0, k, 0);

        ll with = 0;

        ll last = last2 + get(last2, mod);

        for(int i = 0; i < n; i++)
        {
            ll diff = get(arr[i], mod);
            ll val = diff * ones;
            ll add_before = abs(((arr[i] + diff - last) / 5) * fives);

            if(fives > ones * 5)
                add_before = abs(((arr[i] + diff - last)) * ones);

            if(arr[i] < 0)
            {
                ll a = ((last - arr[i]) / 5) * fives;
                if(fives > ones * 5)
                    a = ((last - arr[i])) * ones;
                else
                    a += ((last - arr[i]) % 5) * ones;

                val = a;
            }
            ///update trees

            if(arr[i] >= 0)
            {
                sum.update(0, k, 0, k, add_before, 0);
                best_tree.update(0, k, 0, k, add_before, 0);
            }

            /*   for(int j = 0; j < k; j++)
                   printf("%lld ", best_tree.get_query(j, j + 1, 0, k, 0));
               printf("\n=========\n");
            */


            pair<ll, int> tmp;
            if(with < k)
                tmp = best_tree.get_query(with, with + 1, 0, k, 0);
            else
                tmp = best_tree.get_query(0, k, 0, k, 0);

            //    printf("i= %d mod = %d with = %lld  tag = %d\n", i, mod, with, tmp.second);
            //       printf("000000000000 %d %d\n", best_tree.get_query(with,with+1,0,k,0).second,tmp.second);

            if(arr[i] < 0)
            {
                if(tmp.first >= val || with < k)
                {
                    sum.update(tmp.second, tmp.second + 1, 0, k, -tmp.first, 0);
                    sum.update(tmp.second, tmp.second + 1, 0, k, val, 0);

                    best_tree.update(tmp.second, tmp.second + 1, 0, k, -tmp.first, 0);
                    best_tree.update(tmp.second, tmp.second + 1, 0, k, val, 0);
                }
            }
            else
            {
                if(tmp.first >= val || with < k)
                {
                    sum.update(tmp.second, tmp.second + 1, 0, k, -tmp.first, 0);

                    sum.update(tmp.second, tmp.second + 1, 0, k, val, 0);

                    best_tree.update(tmp.second, tmp.second + 1, 0, k, -tmp.first, 0);
                    best_tree.update(tmp.second, tmp.second + 1, 0, k, val, 0);
                }
            }


            with++, with = min(with, k);

            if(with >= k) // || with==k)
            {
                //  printf("ret %lld %lld\n",ret, sum.get_query(0, k, 0, k, 0));

                if(first == 0)ret = sum.get_query(0, k, 0, k, 0);
                ret = min(ret, sum.get_query(0, k, 0, k, 0));
                first = 1;
            }

            if(arr[i] >= 0)
                last = arr[i] + diff;
        }
        // break;
    }
    //printf("%d %lld\n", mod, ret);

    return ret;
}
