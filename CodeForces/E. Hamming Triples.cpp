#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define ll long long

int setbit(int mask, int bit, int value);
int getbit(int mask, int bit);
ll cnt(int i, int msk_type, int msk_change, int mode);
ll fn(int i, int msk_type, int msk_change, int mode);
int bin_search(int t, int val);
ll get_ham(int small, int big, int msk_type);
void pre_process();
int check(int msk_type);
int check(int msk_type, int msk_change);
ll C(int x, int y);
ll C(ll x, ll y);

pair<int, int> zero_one[MAX], one_zero[MAX];
int a = 0, b = 0;
int n, l, indx[MAX], diff_indx;
const ll inf = 9999999999;
ll dp[MAX][8][8][2], cnt_dp[MAX][8][8][2];
int bin_ans[MAX], bin_ans2[MAX];

int main()
{
    scanf("%d %d", &l, &n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        if(x == 0)
            zero_one[a++].first = y;
        else
            one_zero[b++].first = y;
    }

    pre_process();



    ll ans = 0, ret = 0;
    for(int i = 0; i < 8; i++)
    {
        // if(check(i))
        ans = max(ans, fn(0, i, 0, 0));
    }

    for(int i = 0; i < 8; i++)
        if(ans == fn(0, i, 0, 0) && check(i))
            //   printf("======%d %d\n", i, cnt(0, i, 0, 0));
            ret += cnt(0, i, 0, 0);
    printf("%lld\n", ret);

    return 0;
}

int check(int msk_type, int msk_change)
{
    int a = getbit(msk_type, 0);
    int b = getbit(msk_type, 1);
    int c = getbit(msk_type, 2);

    if(getbit(msk_change, 0)) a = !a;
    if(getbit(msk_change, 1)) b = !b;
    if(getbit(msk_change, 2)) c = !c;

    if(a == b && getbit(msk_change, 0) == 0 && getbit(msk_change, 1) == 1)return 0;
    if(a == c && getbit(msk_change, 0) == 0 && getbit(msk_change, 2) == 1)return 0;
    if(b == c && getbit(msk_change, 1) == 0 && getbit(msk_change, 2) == 1)return 0;

    return 1;
}

int check(int msk_type)
{
    int a = getbit(msk_type, 0);
    int b = getbit(msk_type, 1);
    int c = getbit(msk_type, 2);

    if(a > b || a > c) return 0;

    if(b > c) return 0;

    return 1;
}

ll cnt(int i, int msk_type, int msk_change, int mode)
{
    if(check(msk_type, msk_change) == 0)
        return 0;

    if(i == diff_indx)
        return msk_change == 7 ? 1 : 0;

    ll &ret = cnt_dp[i][msk_type][msk_change][mode];
    if(ret != -1)
        return ret;

    ret = 0;

    int nxt = indx[i + 1], curr = indx[i];

    ///get max_value
    ll g = fn(i, msk_type, msk_change, mode);

    if(g < 0)
        return 0;
    int p = 0;
    ///don't change
    if(i < diff_indx - 1)
    {
        if(g == fn(i + 1,  msk_type, msk_change, 0) + get_ham(curr, nxt, msk_type))
            ret += cnt(i + 1, msk_type, msk_change, 0), p++;
    }
    else
    {
        if(g == fn(i + 1, msk_type, msk_change, 0))
            ret += cnt(i + 1, msk_type, msk_change, 0), p++;
    }

    if(mode == 0)
    {
        int v1 =bin_ans[i];
        int v2 = bin_ans2[i];




//if((i==3 && msk_type==6 && msk_change==0))
        for(int x = 1; x < 8; x++)
        {
            int new_msk_type = msk_type;
            int new_msk_change = msk_change;
            int flag = 1, u1 = 0, u2 = 0;

            for(int j = 0; j < 3 && flag; j++)
            {
                if(getbit(x, j) == 1)
                {
                    int t = getbit(msk_type, j);
                    if(t == 0)
                        u1++;
                    else
                        u2++;

                    if(getbit(msk_change, j) == 1 || (t == 0 && v1 == -1) || (t == 1 && v2 == -1))
                        flag = 0;
                    new_msk_type = setbit(new_msk_type, j, !t);
                    new_msk_change = setbit(new_msk_change, j, 1);
                }
            }

            if(u1 > v1 || u2 > v2)
                flag = 0;

            ll fac = C((ll)v1, (ll)u1) * C((ll)v2, (ll)u2);

            //  printf("%lld %d %d\n", fac,v1,v1-u1);
            if(flag)
            {

                if(fn(i, new_msk_type, new_msk_change, 1) == g)
                {
                    ret += fac * cnt(i, new_msk_type, new_msk_change, 1), p++;

                }
            }
        }
    }



    return ret;
}

ll C(ll x, ll y)
{
    if(x == 0 || y == 0)
        return 1;

    if(y == 1) return x;

    if(y == 2) return (ll)(x * (x - 1)) / 2;

    if(y == 3) return (ll)(x * (x - 1) * (x - 2)) / 6;
}

ll fn(int i, int msk_type, int msk_change, int mode)
{
    if(i == diff_indx)
    {
        // printf("%d\n", msk_change);
        return msk_change == 7 ? 0 : -inf;
    }

    ll &ret = dp[i][msk_type][msk_change][mode];
    if(ret != -1)
        return ret;

    ret = -inf;

    int nxt = indx[i + 1], curr = indx[i];

    ///don't change
    if(i < diff_indx - 1)
        ret = max(ret, fn(i + 1, msk_type, msk_change, 0) + get_ham(curr, nxt, msk_type));
    else
        ret = max(ret, fn(i + 1, msk_type, msk_change, 0));


    if(mode == 0)
    {
        int v1 =bin_ans[i];
        int v2 = bin_ans2[i];

        for(int x = 1; x < 8; x++)
        {
            int new_msk_type = msk_type;
            int new_msk_change = msk_change;
            int flag = 1, u1 = 0, u2 = 0;

            for(int j = 0; j < 3 && flag; j++)
            {
                if(getbit(x, j) == 1)
                {
                    int t = getbit(msk_type, j);
                    if(t == 0)
                        u1++;
                    else
                        u2++;
                    if(getbit(msk_change, j) == 1 || (t == 0 && v1 == -1) || (t == 1 && v2 == -1))
                        flag = 0;
                    new_msk_type = setbit(new_msk_type, j, !t);
                    new_msk_change = setbit(new_msk_change, j, 1);
                }
            }

            if(u1 > v1 || u2 > v2)
                flag = 0;
            if(flag)
                ret = max(ret, fn(i, new_msk_type, new_msk_change, 1));
        }
    }

    return ret;
}

int bin_search(int t, int val)
{
    int big = (t == 0 ? a : b);
    int small = 0, mid;
    pair<int, int> *arr = (t == 0 ? zero_one : one_zero);

    while(big >= small)
    {
        mid = (small + big) / 2;

        if(arr[mid].first == val)
            return arr[mid].second;

        if(arr[mid].first > val)
            big = mid - 1;
        else
            small = mid + 1;
    }

    return 0;

}

ll get_ham(int small, int big, int msk_type)
{
    ll ret = 0;
    int diff = big - small;

    ///a b
    if(getbit(msk_type, 0) != getbit(msk_type, 1))
        ret += diff;
    ///b c
    if(getbit(msk_type, 1) != getbit(msk_type, 2))
        ret += diff;

    ///a c
    if(getbit(msk_type, 0) != getbit(msk_type, 2))
        ret += diff;

    return ret;
}

void pre_process()
{
    memset(dp, -1, sizeof(dp));
    memset(cnt_dp, -1, sizeof(cnt_dp));

    sort(zero_one, zero_one + a);
    sort(one_zero, one_zero + b);

    int k = 0;
    for(int i = 0; i < max(a, b); i++)
    {
        if(i < a)indx[k++] = zero_one[i].first;
        if(i < b)indx[k++] = one_zero[i].first;
    }

    indx[k++] = 0, indx[k++] = l;
    sort(indx, indx + k);

    int j = 0, prev = -1, i = 0, tmp = 0;

    while(i < k)
    {
        if(prev != indx[i])
        {
            indx[j++] = indx[i];
            prev = indx[i];
        }

        i++;
    }

    diff_indx = j;


    j = 0, prev = zero_one[0].first, i = 0, tmp = 0;
    while(i < a)
    {
        if(prev != zero_one[i].first)
        {
            zero_one[j].first = prev, zero_one[j++].second = tmp;
            tmp = 1;
            prev = zero_one[i].first;

        }
        else
            tmp++;

        i++;
    }

    zero_one[j].first = prev, zero_one[j++].second = tmp;
    a = j;


    j = 0, prev = one_zero[0].first, i = 0, tmp = 0;
    while(i < b)
    {
        if(prev != one_zero[i].first)
        {
            one_zero[j].first = prev, one_zero[j++].second = tmp;
            tmp = 1;
            prev = one_zero[i].first;

        }
        else
            tmp++;

        i++;
    }

    one_zero[j].first = prev, one_zero[j++].second = tmp;
    b = j;

    for(int i = 0; i < diff_indx; i++)
    {
        bin_ans[i] = bin_search(0, indx[i]);
        bin_ans2[i] = bin_search(1, indx[i]);
    }
}

int setbit(int mask, int bit, int value)
{
    if(value == 1)
        return(mask | (1 << bit));
    else
        return (mask&~(1 << bit));
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}
