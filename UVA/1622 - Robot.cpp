#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 1009

ll fn(int right, int down, int row, int col);
ll gn(int row, int col);
ll sim(int row, int col);
void go(int& m, int& row, int& col, int h[], ll& ret);

int north, south, west, east;
int h[3], v[3];
const int inf = 999999;

int main()
{
    int cases = 1;
    int row, col;

    while((cin >> row >> col && col))
    {
        scanf("%d %d %d %d", &north, &south, &west, &east);

        ll a = gn(row, col);
        ll b = sim(row, col);
        printf("Case %d: %lld\n", cases++, a);
    }

    return 0;
}

ll fn(int right, int down, int row, int col)
{
    int c1, c2;
    ll ret = 0;
    while(row && col && ( right || down))
    {
        ///move right
        if(right)
            c1 = row;
        else
            c1 = inf;

        if(down)
            c2 = col;
        else
            c2 = inf;

        ret += (ll)row * col;

        if(c1 < c2)
            col--, right--;
        else
            row--, down--;
    }

    return ret;
}

ll gn(int row, int col)
{
    int r = row, c = col;
    ll ret = 0, ans;

    h[0] = west, h[1] = east;
    v[0] = north, v[1] = south;
    sort(h, h + 2), sort(v, v + 2);

    go(col, row, col, h, ret);
    go(row, row, col, v, ret);
    ans = (ll) fn(h[1], v[1], row, col) + ret;


    ret = 0;
    row = r, col = c;
    h[0] = west, h[1] = east;
    v[0] = north, v[1] = south;
    sort(h, h + 2), sort(v, v + 2);

    go(row, row, col, v, ret);
    go(col, row, col, h, ret);

    return max(fn(h[1], v[1], row, col) + ret, ans);

}

void go(int& m, int& row, int& col, int h[], ll& ret)
{
    if(m > 1)
    {
        if(h[1])
            ret += (ll) row * (ll)col;
        else
            return;
        m--;
        h[1]--;
        int f = 0;
        while(true)
        {
            if(f == 0)
            {
                if(h[0])
                    h[0]--;
                else
                    break;
            }
            else
            {
                if(h[1])
                    h[1]--;
                else
                    break;
            }
            f = !f;
            ret += (ll)((ll)row * (ll)col);

        }
        sort(h, h + 2);
    }

}

ll sim(int row, int col)
{
    ll ret = 0;
    int vn, vs, ve, vw;
    int c1 = 0, r1 = 0, r2 = row, c2 = col;
    int nr1, nr2, nc1, nc2;
    int sr1, sr2, sc1, sc2;
    int wr1, wr2, wc1, wc2;
    int er1, er2, ec1, ec2;

    while(c2 - c1 > 0 && r2 - r1 > 0 && (south + north + west + east))
    {
        vn = vs = ve = vw = -1 * inf;
        if((r2 - r1) * (c2 - c1) > 0)
            ret += (ll) (r2 - r1) * (c2 - c1);
        if(north)
        {
            nc1 = c1, nc2 = c2, nr1 = r1, nr2 = r2;
            nr1 = max(0, nr1 - 1);
            nr2 = max(0, nr2 - 1);
            vn = (c2 - c1) * ((nr2 - nr1));
        }

        if(south)
        {
            sc1 = c1, sc2 = c2, sr1 = r1, sr2 = r2;
            sr1 = min(row , sr1 + 1);
            sr2 = min(row , sr2 + 1);
            vs = (c2 - c1) * ((sr2 - sr1));
        }

        if(east)
        {
            ec1 = c1, ec2 = c2, er1 = r1, er2 = r2;
            ec2 = min(col, ec2 + 1);
            ec1 = min(col, ec1 + 1);
            ve = (r2 - r1) * ((ec2 - ec1));
        }

        if(west)
        {
            wc1 = c1, wc2 = c2, wr1 = r1, wr2 = r2;
            wc2 = max(0, wc2 - 1);
            wc1 = max(0, wc1 - 1);
            vw = (r2 - r1) * ((wc2 - wc1));
        }
        int tmp = vn, d = 0, sec = north;
        if(vn > tmp)
            r1 = nr1, r2 = nr2, c1 = nc1, c2 = nc2, tmp = vn, d = 0, sec = north;
        else if(vn == tmp && north >= sec)
            sec = north, d = 0, r1 = nr1, r2 = nr2, c1 = nc1, c2 = nc2, tmp = vn, d = 0;


        if(vs > tmp)
            r1 = sr1, r2 = sr2, c1 = sc1, c2 = sc2, tmp = vs, d = 1, sec = south;
        else if(vs == tmp && south >= sec)
            sec = south, d = 1, r1 = sr1, r2 = sr2, c1 = sc1, c2 = sc2, tmp = vs, d = 1;

        if(ve > tmp)
            r1 = er1, r2 = er2, c1 = ec1, c2 = ec2, tmp = ve, d = 2, sec = east;
        else if(ve == tmp && east >= sec)
            sec = east, d = 2, r1 = er1, r2 = er2, c1 = ec1, c2 = ec2, tmp = ve, d = 2;

        if(vw > tmp)
            r1 = wr1, r2 = wr2, c1 = wc1, c2 = wc2, tmp = vw, d = 3, sec = west;
        else if(vw == tmp && west >= sec)
            sec = west, d = 3, r1 = wr1, r2 = wr2, c1 = wc1, c2 = wc2, tmp = vw;

        if(d == 0)
            north--;
        else if(d == 1)
            south--;
        else if(d == 2)
            east--;
        else
            west--;
    }

    return ret;
}

