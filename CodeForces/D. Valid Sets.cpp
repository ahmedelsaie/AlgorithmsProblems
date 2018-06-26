#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define MAX 100009

void bfs(int root);
ll fn(int curr, int check, int prnt, int indx);

int n, d, val[MAX], diff[MAX], visited[MAX][2], x, cases = 0, v[MAX];
vector<int> tree[MAX], input[MAX];
ll dp[MAX][3];
ll mod = 1000000007;
int check[MAX];

int main()
{
    memset(visited, -1, sizeof(visited));
    memset(diff, 0, sizeof(diff));
    memset(check, 0, sizeof(check));

    scanf("%d %d", &d, &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &val[i]), diff[val[i]] = 1;

    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        input[x].push_back(y);
        input[y].push_back(x);
    }

    bfs(1);
    int child ;
    ll ret = 0;
    for(int i = 0; i <= 2000; i++)
    {
        if(diff[i])
        {
            x = i;

            for(int j = 1; j <= n; j++)
            {
                child = -1;
                if(tree[j].size())
                    child = tree[j][0];

                if(val[j] <= x && x - val[j] <= d)
                {
                    if(val[j] == x)
                        ret += fn(child, 0, j, 0), ret = ret % mod;
                    ret += fn(child, 1, j, 0), ret = ret % mod;
                }
            }

            cases++;
        }
    }

    printf("%lld\n", ret);

    return 0;
}

ll fn(int curr, int check, int prnt, int indx)
{
    if(curr == -1)
        return check == 0;
    //  printf("===== %d %d\n",curr,check);

    int& flag = visited[curr][check];
    ll& ret = dp[curr][check];
    if(flag == cases)
        return ret;

    flag = cases, ret = 0;

    int child = -1, sib = -1;
    if(tree[curr].size())
        child = tree[curr][0];

    if(indx + 1 < tree[prnt].size())
        sib = tree[prnt][indx + 1];

    int new_check = check | (x == val[curr]);

    ///i must not find
    if(check == 0)
    {
        if(val[curr] < x && x - val[curr] <= d)
            ret += fn(child, 0, curr, 0) * fn(sib, 0, prnt, indx + 1) % mod, ret = ret % mod;

        ret += fn(sib, 0, prnt, indx + 1);
        ret = ret % mod;

    }
    else
    {
        if(val[curr] == x)
        {
            ret += fn(child, 0, curr, 0) * fn(sib, 0, prnt, indx + 1) % mod;
            ret = ret % mod;
            ret += fn(child, 1, curr, 0) * fn(sib, 1, prnt, indx + 1) % mod;
            ret = ret % mod;
            ret += fn(child, 0, curr, 0) * fn(sib, 1, prnt, indx + 1) % mod;
            ret = ret % mod;
            ret += fn(child, 1, curr, 0) * fn(sib, 0, prnt, indx + 1) % mod;
            ret = ret % mod;

        }
        else if(val[curr] < x && x - val[curr] <= d)
        {
            ret += fn(child, 1, curr, 0) * fn(sib, 1, prnt, indx + 1) % mod;
            ret = ret % mod;
            ret += fn(child, 0, curr, 0) * fn(sib, 1, prnt, indx + 1) % mod;
            ret = ret % mod;
            ret += fn(child, 1, curr, 0) * fn(sib, 0, prnt, indx + 1) % mod;
            ret = ret % mod;

        }
        ret += fn(sib, 1, prnt, indx + 1);
        ret = ret % mod;

    }

    return ret;

}

void bfs(int root)
{
    for(int i = 0; i <= n; i++)
        tree[i].clear();
    memset(v, 0, sizeof(v));
    queue<int> q;
    q.push(root);

    while(q.empty() == 0)
    {
        int tmp = q.front();
        v[tmp] = 1;
        q.pop();

        for(int i = 0; i < input[tmp].size(); i++)
        {
            int tmp2 = input[tmp][i];
            if(v[tmp2] == 0)
            {
                v[tmp2] = 1;
                q.push(tmp2);
                tree[tmp].push_back(tmp2);
            }
        }
    }

    return;
}


