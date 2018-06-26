#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 1506

int fn(int node, int prnt, int indx, int mode);

vector<int>tree[MAX];
int visited[MAX][2], dp[MAX][2];

int cases = 0, n;
const int inf = 9999999;

int main()
{
    int x, no, tmp, ans, child, start;
    memset(visited, -1, sizeof(visited));

    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            tree[i].clear();

        for(int i = 0; i < n; i++)
        {
            scanf("%d:(%d)", &x, &no);
            for(int j = 0; j < no; j++)
                scanf("%d", &tmp), tree[min(x, tmp)].push_back(max(x, tmp));
        }

        child = -1;

        start = 0;
        if(tree[start].size() != 0)
            child = tree[start][0];

        ans = min(fn(child, start, 0, 0), fn(child, start, 0, 1) + 1);
        printf("%d\n", ans);
        cases++;
    }

    return 0;
}

int fn(int node, int prnt, int indx, int mode)
{
    if(node == -1)
        return 0;

    int& flag = visited[node][mode];
    int& ret = dp[node][mode];
    if(flag == cases)
        return ret;

    flag = cases, ret = inf;
    int child = -1, sibling = -1;

    if(tree[node].size() != 0)
        child = tree[node][0];

    if(indx + 1 < tree[prnt].size())
        sibling = tree[prnt][indx + 1];

    ///node before nt taken
    if(mode == 0)
        ret = min(ret, fn(child, node, 0, 1) + fn(sibling, prnt, indx + 1, mode) + 1);

    ///before me taken
    if(mode == 1)
    {
        ret = min(ret, fn(child, node, 0, 0) + fn(sibling, prnt, indx + 1, mode));
        ret = min(ret, fn(child, node, 0, 1) + fn(sibling, prnt, indx + 1, mode) + 1);
    }

    return ret;
}

