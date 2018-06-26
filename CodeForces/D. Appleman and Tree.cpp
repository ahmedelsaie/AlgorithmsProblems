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

ll fn(int curr, int need, int prnt, int indx);
void bfs(int root);

vector<int> tree[MAX], input[MAX];
int array[MAX], n, v[MAX];
ll dp[MAX][3];
ll mod = 1000000007 ;

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++)
    {
        int x;
        scanf("%d", &x);
        input[x].push_back(i + 1);
        input[i + 1].push_back(x);
    }

    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    bfs(0);
    int child = -1;
    if(tree[0].size())
        child = tree[0][0];
    int need = 0;
    if(array[0] == 0)
        need = 1;
//   printf("%d %d\n",tree[0][0],tree[0][1]);
    printf("%lld\n", fn(child, need, 0, 0));

    return 0;
}

void bfs(int root)
{
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

ll fn(int curr, int need, int prnt, int indx)
{
    //  printf("%d %d\n",curr,need);
    if(curr == -1)
        return need == 0;

    ll& ret = dp[curr][need];
    if(ret != -1)
        return ret;

    ret = 0;
    int child = -1, sib = -1;
    if(tree[prnt].size() > indx + 1)
        sib = tree[prnt][indx + 1];

    if(tree[curr].size())
        child = tree[curr][0];

    if(array[curr] == 0)
    {
        ///cut and pass
        ret += fn(child, 1, curr, 0) * fn(sib, need, prnt, indx + 1) % mod,ret=ret%mod;

        if(need == 0)
            ret += fn(child, need, curr, 0) * fn(sib, need, prnt, indx + 1) % mod,ret=ret%mod;
        else
        {
            ret += fn(child, need, curr, 0) * fn(sib, 0, prnt, indx + 1) % mod,ret=ret%mod;
            ret += fn(child, 0, curr, 0) * fn(sib, 1, prnt, indx + 1) % mod,ret=ret%mod;
        }
    }
    else
    {
        if(need == 0)
            ret += fn(child, 0, curr, 0) * fn(sib, 0, prnt, indx + 1) % mod,ret=ret%mod;
        else
        {
            ret += fn(child, 0, curr, 0) * fn(sib, 0, prnt, indx + 1) % mod,ret=ret%mod;
            ret += fn(child, 0, curr, 0) * fn(sib, 1, prnt, indx + 1) % mod,ret=ret%mod;
        }
    }

    return ret;
}
