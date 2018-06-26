#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAX 20009

int fn(int node, int prnt, int indx, int mode);
int trace(int node, int prnt, int indx, int mode, int p);
void process(int x);
void reset();
void bfs(int root);

vector<int> tree[MAX], vec[MAX], input[MAX];
const int inf = (1 << 20);
int v[MAX], cnt = 0, tc, n, dp[MAX][5], x, y;;

int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        if(n <= 1)
        {
            printf("1\n1\n");
            continue;
        }
        reset();

        int first = 1;


        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d", &x, &y);
            input[x].push_back(y);
            input[y].push_back(x);
        }

        bfs(1);

        first = 1;
        for(int i = 1; i <= n; i++)
            if(v[i] == 0)
                x = 1 / 0;

        int  son = -1;
        if(tree[first].size())
            son = tree[first][0];

        int a = fn(son, first, 0, 1) + 1;
        int b = fn(son, first, 0, 2) + 1;
        int ans = min(a, b);
        printf("%d\n", ans);

        if(a <= b)
            vec[0].push_back(first), trace(son, first, 0, 1, 0);
        else
            vec[0].push_back(first), trace(son, first, 0, 2, 0);

        for(int i = 0; i < ans; i++)
            process(i), printf("\n");

    }


    return 0;
}

void bfs(int root)
{
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

void process(int x)
{
    int f = -1;
    for(int i = 0; i < vec[x].size(); i++)
    {
        if(vec[x][i] < 0)
        {
            f = i;
            break;
        }
    }

    if(f == -1)
    {
        for(int j = 0; j < vec[x].size(); j++)
        {
            if(j)
                printf(" ");
            printf("%d", abs(vec[x][j]));
        }
    }
    else
    {
        for(int j = f - 1; j >= 0; j--)
            printf("%d ", abs(vec[x][j]));
        printf("%d", abs(vec[x][f]));

        for(int j = f + 1; j < vec[x].size(); j++)
            printf(" %d", abs(vec[x][j]));
    }

}

int fn(int node, int prnt, int indx, int mode)
{
    if(node == -1)
        return 0;

    int& ret = dp[node][mode];
    if(ret != -1)
        return ret;

    ret = inf;

    int son = -1, bro = -1;
    if(tree[node].size())
        son = tree[node][0];

    if(tree[prnt].size() > indx + 1)
        bro = tree[prnt][indx + 1];

    ///i must start new one
    ret = 1 + fn(son, node, 0, 1) + fn(bro, prnt, indx + 1, mode);
    ret = min(ret, 1 + fn(son, node, 0, 2) + fn(bro, prnt, indx + 1, mode));

    ///take my self && pass to the next
    if(mode)
        ret = min(ret, fn(son, node, 0, 1) + fn(bro, prnt, indx + 1, mode - 1));

    return ret;
}

int trace(int node, int prnt, int indx, int mode, int p)
{
    if(node == -1)
        return 0;

    int son = -1, bro = -1;
    if(tree[node].size())
        son = tree[node][0];

    if(tree[prnt].size() > indx + 1)
        bro = tree[prnt][indx + 1];

    int a = inf;
    int b = fn(son, node, 0, 1) + fn(bro, prnt, indx + 1, mode) + 1;
    int c = fn(son, node, 0, 2) + fn(bro, prnt, indx + 1, mode) + 1;

    if(mode)
        a = fn(son, node, 0, 1) + fn(bro, prnt, indx + 1, mode - 1);

    if(a <= b && a <= c)
    {
        if(mode == 1)
        {
            vec[p].push_back(node);
            trace(son, node, 0, 1, p);
            trace(bro, prnt, indx + 1, mode - 1, p);
            return 0;
        }
        else
        {
            vec[p].clear();
            vec[p].push_back(node);
            trace(son, node, 0, 1, p);
            vec[p].push_back(-1 * prnt);
            trace(bro, prnt, indx + 1, mode - 1, p);
            return 0;

        }
    }
    else if (b <= a && b <= c)
    {
        cnt++;
        vec[cnt].push_back(node);
        trace(son, node, 0, 1, cnt), trace(bro, prnt, indx + 1, mode, p);
        return 0;

    }
    else
    {
        cnt++;
        vec[cnt].push_back(-1 * node);
        trace(son, node, 0, 2, cnt), trace(bro, prnt, indx + 1, mode, p);
        return 0;

    }
}

void reset()
{
    memset(dp, -1, sizeof(dp));
    cnt = 0;
    memset(v, 0, sizeof(v));
    for(int i = 0; i <= n; i++)
        v[0] = 0;
    for(int i = 0; i <= n + 5; i++)
        tree[i].clear(), vec[i].clear(), input[i].clear();
}
