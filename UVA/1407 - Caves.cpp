#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll long long

ll fn(int curr, int left, int back, int parent, int indx);
int collect(int i);

vector<pair<int, int> > tree[505];
ll dp[505][505][2];
int dp2[505];
int visited[505][505][2];
int cases = 1;
const ll inf = 99999999999;
int n;

int main()
{
    int x, y, z, prnt, child, q;
    ll ans, cost;
    pair<int, int> tmp;
    memset(visited, -1, sizeof(visited));
    bool c;
    while(true)
    {
        memset(dp2, -1, sizeof(dp2));
        c = 1;
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            tree[i].clear();

        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            prnt = min(x, y), child = max(x, y);
            tmp.first = child, tmp.second = z;
            tree[prnt].push_back(tmp);
        }

        if(tree[0].size() == 0)
            c = 0;

        collect(0);
        scanf("%d", &q);
        printf("Case %d:\n", cases);
        for(int i = 0; i < q; i++)
        {
            scanf("%lld", &cost);
            if(c != 0)
            {
                ans = 0;
                for(int i = 0; i <= n; i++)
                {
                    if(fn(tree[0][0].first, i, 1, 0, 0) <= cost) // || dp[tree[0][0].first][i][0])
                        ans = i;
                }
            }
            else
                ans = 0;

            printf("%lld\n", ans + 1);
        }

        cases++;
    }

    return 0;
}

ll fn(int curr, int left, int back, int parent, int indx)
{
    if(left < 0 || left == 0)
        return 0;

    ///out of tree
    if(curr == -1)
        return inf;

    ll& ret = dp[curr][left][back];
    int& flag = visited[curr][left][back];
    if(flag == cases)
        return ret;
    flag = cases;
    ret = inf;
    ll tmp;

    int new_left = left - 1, cost = tree[parent][indx].second;

    int sibling = -1, child = -1;
    if(tree[parent].size() != 0)
        if(indx + 1 < tree[parent].size())
            sibling = tree[parent][indx + 1].first;

    if(tree[curr].size() != 0)
        child = tree[curr][0].first;

    ///0 wil return
    if(back == 0)
    {
        tmp = fn(sibling, left, 0, parent, indx + 1);
        ret = min(ret, tmp);
        for(int i = 0; i <= min(new_left, dp2[curr]); i++)
        {
            tmp = fn(sibling, new_left - i, 0, parent, indx + 1) + fn(child, i, 0, curr, 0) + 2 * cost;
            ret = min(ret, tmp);
        }
    }

    ///1 wont return
    if(back == 1)
    {
        tmp = fn(sibling, left, 1, parent, indx + 1);
        ret = min(ret, tmp);
        for(int i = 0; i <= min(new_left, dp2[curr]) ; i++)
        {
            tmp = fn(sibling, new_left - i, 0, parent, indx + 1) + fn(child, i, 1, curr, 0) + cost;
            ret = min(ret, tmp);

            tmp = fn(sibling, new_left - i, 1, parent, indx + 1) + fn(child, i, 0, curr, 0) + 2 * cost;
            ret = min(ret, tmp);
        }
    }

    return ret;
}

int collect(int i)
{
    int& ret = dp2[i];
    if(ret != -1)
        return ret;
    ret = 0;

    if(tree[i].size() > 0)
        for(int j = 0; j < tree[i].size(); j++)
            ret += collect(tree[i][j].first);

    return ret + 1;
}

