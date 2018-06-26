#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 101

ll gn(int row, int left, int s1, int s2, int h1, int h2, int dv1, int dv2);
ll solve(int row, int col, int left);
void pre_comb();
int cntbit(int mask);
int getbit(int mask, int bit);
ll f2(int row, int col, int left);
ll f1(int row, int col, int left, int f);
ll rem(int row, int col, int left, int h1, int h2, int s1, int s2);

ll const MOD = 1000000007LL;
ll dp_gn[MAX][MAX][2][2][2][2][2][2];
ll dp_rem[MAX][MAX][MAX][2][2][2][2];
ll C[MAX* MAX][MAX];
ll dp_f2[MAX][MAX][MAX], dp_f1[MAX][MAX][MAX][2];

int main()
{
    pre_comb();

    int tc, row, col, left, cases = 1;

    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d %d", &row, &col, &left);
        printf("Case %d: %lld\n", cases++, solve(row, col, left));
    }

    return 0;
}

ll solve(int row, int col, int left)
{
    if(left > row * col) return 0;
    if(row == 1 && col == 1) return left;
    if(row == 1 || col == 1) return C[row * col][left];
    if(row == 2 || col == 2)
    {
        if(col == 2) swap(row, col);

        ll tmp = C[row * col][left];

        if(left < col) tmp = tmp - (2 * C[col][left] % MOD) + MOD;

        return tmp % MOD;
    }

    ll ret = 0LL;
    for(int i = 1; i <= left; i++)
    {
        ///two are done
        ret += gn(col, i, 1, 1, 0, 0, 1, 1) * C[(row - 2) * col][left - i] % MOD, ret %= MOD;;; ///both are done

        ///no one is done
        ll tmp = f1(row - 2, col, left - i, 1);
        ll tmp2 = 2 * f2(row - 2, col - 1, left - i) - f2(row - 2, col - 2, left - i);
        ret += gn(col, i, 1, 1, 0, 0, 0, 0) * (tmp + tmp2);

        ///one is left
        tmp = f1(row - 2, col, left - i, 0);
        tmp2 = f2(row - 2, col - 1, left - i);
        ret += 2 * gn(col, i, 1, 1, 0, 0, 1, 0) * (tmp + tmp2);
    }

    ll m = 0;
    ///PART TWO
    swap(row, col);
    if(row == col)
        ret *= 2;
    else
    {
        for(int i = 1; i <= left; i++)
        {
            ///two are done
            ret += gn(col, i, 1, 1, 0, 0, 1, 1) * C[(row - 2) * col][left - i] % MOD, ret %= MOD;;; ///both are done

            ///no one is done
            ll tmp = f1(row - 2, col, left - i, 1);
            ll tmp2 = 2 * f2(row - 2, col - 1, left - i) - f2(row - 2, col - 2, left - i);
            ret += gn(col, i, 1, 1, 0, 0, 0, 0) * (tmp + tmp2);

            ///one is left
            tmp = f1(row - 2, col, left - i, 0);
            tmp2 = f2(row - 2, col - 1, left - i);
            ret += 2 * gn(col, i, 1, 1, 0, 0, 1, 0) * (tmp + tmp2);
        }

    }

    for(int i = 0; i <= left; i++)
        m += rem(row - 2, col - 2, i, 0, 0, 1, 1) * C[(row - 2) * (col - 2)][left - i] % MOD, m %= MOD;

    ret = (ret - m + MOD) % MOD;
    return ret;
}

ll f2(int row, int col, int left)
{
    if(left < 0)return 0;
    if(row == 0)return left == 0;
    if(left == 0)return 0;

    ll& ret = dp_f2[row][col][left];
    if(ret != -1) return ret;
    ret = 0;

    int a = min(col, left);
    for(int i = 1; i <= a; i++)
        ret += C[col][i] * f2(row - 1, col, left - i) % MOD, ret %= MOD;

    return ret;
}

ll f1(int row, int col, int left, int f)
{
    if(left < 0) return 0;

    ll& ret = dp_f1[row][col][left][f];
    if(ret != -1) return ret;
    ret = 0;
    if(f == 0) ///one side is left
    {
        int a = min(row, left);
        for(int i = 1; i <= a; i++)
            ret += C[row][i] * C[row * (col - 1)][left - i] % MOD, ret %= MOD;
    }
    else /// 2 sides are left
    {
        int a = min(2 * row, left);
        for(int i = 1; i <= a; i++)
        {
            ll tmp = 0;
            if(i <= row)
                tmp = 2 * C[row][i] % MOD;
            ret += (C[2 * row][i] - tmp + MOD) % MOD * C[row * (col - 2)][left - i], ret %= MOD;
        }
    }

    return ret;
}

ll rem(int row, int col, int l, int h1, int h2, int s1, int s2)
{
    if(l < 0 || col < 0)
        return 0LL;

    if(col == 0)
    {
        if(s1) h2 = 1;
        if(s2) h1 = 1;

        return l == 0 && h1 + h2 == 2;
    }

    ll& ret = dp_rem[row + 2][col][l][h1][h2][s1][s2];
    if(ret != -1)
        return ret;
    ret = 0LL;

    if(row == 0)  ///the corners
    {
        if(s1 && !h1) s1 = 0;
        if(s2 && !h2) s2 = 0;

        int nv1, nv2, nh1, nh2, ns1, ns2;
        for(int i = 0; i < (1 << 4); i++)
        {
            nv1 = nv2 = 0, nh1 = h1, nh2 = h2, ns1 = 0, ns2 = 0;

            if(getbit(i, 0))nh1 = nv1 = 1;
            if(getbit(i, 1))nh2 = nv1 = 1;
            if(getbit(i, 2))nh1 = nv2 = 1;
            if(getbit(i, 3))nh2 = nv2 = 1;

            if(getbit(i, 0) && getbit(i, 2) && s1) ns1 = 1;
            if(getbit(i, 1) && getbit(i, 3) && s2) ns2 = 1;

            if(ns1)nh2 = nh1 = 1;
            if(ns2)nh1 = nh2 = 1;

            int t1 = getbit(i, 0) && getbit(i, 1);
            int t2 = getbit(i, 3) && getbit(i, 2);

            if(nh1 && nh2)
                ret += rem(row - 1, col, l - cntbit(i), nv1, nv2, t1, t2), ret %= MOD;
        }
    }
    else if(row == -1)
    {
        ret += rem(row, col - 1, l - 2, 1, 1,  s1,  s2), ret %= MOD; ///put two
        ret += rem(row, col - 1, l - 1, 1, h2,  s1,  0), ret %= MOD; ///put one
        ret += rem(row, col - 1, l - 1, h1, 1,  0,  s2), ret %= MOD; ///put one
        ret += rem(row, col - 1, l, h1, h2,  0,  0), ret %= MOD; ///put zero
    }
    else if(row > 0)
    {
        ret += rem(row - 1, col, l - 2, 1, 1,  s1,  s2), ret %= MOD; ///put two
        ret += rem(row - 1, col, l - 1, 1, h2,  s1,  0), ret %= MOD; ///put one
        ret += rem(row - 1, col, l - 1, h1, 1,  0,  s2), ret %= MOD; ///put one
        ret += rem(row - 1, col, l, h1, h2,  0,  0), ret %= MOD; ///put zero
    }

    return ret;
}

ll gn(int row, int left, int s1, int s2, int h1, int h2, int dv1, int dv2)
{
    if(left < 0)
        return 0LL;

    ll& ret = dp_gn[row][left][s1][s2][h1][h2][dv1][dv2];
    if(ret != -1LL)
        return ret;
    ret = 0LL;

    if(row == 2)
    {
        if(s1 && !h1) s1 = 0;
        if(s2 && !h2) s2 = 0;

        int nv1, nv2, nh1, nh2, ns1, ns2;
        for(int i = 0; i < (1 << 4); i++)
        {
            nv1 = nv2 = 0, nh1 = h1, nh2 = h2, ns1 = 0, ns2 = 0;

            if(getbit(i, 0))nh1 = nv1 = 1;
            if(getbit(i, 1))nh2 = nv1 = 1;
            if(getbit(i, 2))nh1 = nv2 = 1;
            if(getbit(i, 3))nh2 = nv2 = 1;

            if(getbit(i, 0) && getbit(i, 2) && s1) ns1 = 1;
            if(getbit(i, 1) && getbit(i, 3) && s2) ns2 = 1;

            if(ns1)nh2 = nh1 = 1;
            if(ns2)nh1 = nh2 = 1;

            ret += left - cntbit(i) == 0 && nh1 + nh2 == 2 && nv1 == dv1 && nv2 == dv2;
        }

        return ret;
    }


    ret += gn(row - 1, left - 2, s1, s2, 1, 1, dv1, dv2), ret %= MOD; ///put in both
    ret += gn(row - 1, left - 1, s1, 0, 1, h2, dv1, dv2), ret %= MOD; ///put on one
    ret += gn(row - 1, left - 1, 0, s2, h1, 1, dv1, dv2), ret %= MOD; ///put on one
    ret += gn(row - 1, left , 0, 0, h1, h2, dv1, dv2), ret %= MOD; ///put on none

    return ret;
}

void pre_comb()
{
    memset(dp_f1, -1, sizeof(dp_f1));
    memset(dp_f2, -1, sizeof(dp_f2));
    memset(dp_gn, -1, sizeof(dp_gn));
    memset(dp_rem, -1, sizeof(dp_rem));

    for(int left = 0; left <= 10000; left++)
        for(int p = 0; p <= 100; p++)
        {
            ll& ret = C[left][p];
            if(left == 0)
                ret = (p == 0);
            else
            {
                ret = (ret % MOD + C[left - 1][p] % MOD) % MOD;
                if(p > 0)
                    ret = (ret % MOD + C[left - 1][p - 1] % MOD) % MOD;
            }
        }
}

int getbit(int mask, int bit)
{
    mask = (mask >> bit) & 1;
    return (mask == 1);
}

int cntbit(int mask)
{
    int ret = 0;
    while(mask)
    {
        if(mask % 2)
            ret++;
        mask = mask / 2;
    }
    return ret;
}
