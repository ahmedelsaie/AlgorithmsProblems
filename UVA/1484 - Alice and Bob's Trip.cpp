#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
#define ll long long

pair<ll, bool> fn(int node, int player, ll accum);
pair<ll, bool> min(pair<ll, bool> x, pair<ll, bool> y);
pair<ll, bool> max(pair<ll, bool> x, pair<ll, bool> y);

vector<pair<int, ll> >tree[500009];
int visited_tree[500009];

ll small, big, z;
const ll inf = 99999999999;
int cases = 0, n, x, y;

int main()
{
    memset(visited_tree, -1, sizeof(visited_tree));
    pair<int, ll> tmp;
    pair<ll, bool> ans;

    while(scanf("%d %lld %lld", &n, &small, &big) != EOF)
    {
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d %lld", &x, &y, &z);
            tmp.first = y, tmp.second = z;
            if(visited_tree[x] == cases)
                tree[x].push_back(tmp);
            else
                visited_tree[x] = cases, tree[x].clear(), tree[x].push_back(tmp);
        }

        ans = fn(0, 0, 0);
        if(ans.second == 0)
            printf("Oh, my god!\n");
        else
            printf("%lld\n", ans.first);
        cases++;
    }

    return 0;
}

pair<ll, bool> fn(int node, int player, ll accum)
{
    if((tree[node].size() == 0 &&  visited_tree[node] == cases) || visited_tree[node] != cases)
    {
        pair<ll, bool> ret;
        if(accum >= small && accum <= big)
            ret.first = 0, ret.second = 1;
        else
            ret.first = 0, ret.second = 0;
        return ret;
    }

    pair<ll, bool> ret;

    ret.second = 0;
    pair<ll, bool> tmp;

    ///bob maximizwe
    if(player == 0)
    {
        ret.first = -inf;
        for(int i = 0; i < tree[node].size(); i++)
        {
            tmp = fn(tree[node][i].first, !player, accum + tree[node][i].second);
            tmp.first += tree[node][i].second;
            ret = max(ret, tmp);
        }
    }
    else
    {
        ret.first = inf;
        for(int i = 0; i < tree[node].size(); i++)
        {
            tmp = fn(tree[node][i].first, !player, accum + tree[node][i].second);
            tmp.first += tree[node][i].second;
            ret = min(ret, tmp);
        }
    }

    return ret;
}

pair<ll, bool> min(pair<ll, bool> x, pair<ll, bool> y)
{
    if(x.second == 0)
        return y;

    if(y.second == 0)
        return x;

    if(x.first < y.first)
        return x;
    return y;
}

pair<ll, bool> max(pair<ll, bool> x, pair<ll, bool> y)
{
    if(x.second == 0)
        return y;

    if(y.second == 0)
        return x;

    if(x.first > y.first)
        return x;
    return y;
}
