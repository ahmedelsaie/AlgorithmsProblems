#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAX 10009

int fn(int curr, int mode, int parent, vector<int>::iterator prnt);

bool leafs[MAX];
bool taken[MAX];
bool root[MAX];
int dp[MAX][4];
int visited[MAX][4];
vector<int> tree[MAX];

int cases = 0, nodes;
const int inf = 999999999;

int main()
{
    int start, x, y;
    vector<int>::iterator child;

    memset(visited, -1, sizeof(visited));

    while(true)
    {
        cases++;
        scanf("%d", &nodes);

        memset(leafs, true, sizeof(leafs));
        memset(taken, true, sizeof(taken));
        memset(root, true, sizeof(root));

        for(int i = 1; i <= nodes; i++)
            tree[i].clear();

        while(true)
        {
            scanf("%d", &x);
            if(x == 0 || x == -1)
                break;
            scanf("%d", &y);
            if(taken[x] == true && taken[y] == false)
            {
                int swap = x;
                x = y;
                y = swap;
            }

            tree[x].push_back(y);
            leafs[x] = false;
            root[y] = false;
            taken[x] = false;
            taken[y] = false;
        }

        for(int i = 1; i <= nodes; i++)
            if(leafs[i])
                tree[i].push_back(-1);

        for(int i = 1; i <= nodes; i++)
            if(root[i] && tree[i].size() != 0)
            {
                start = i;
                break;
            }

        child = tree[start].begin();

        printf("%d", min(fn(*child, 0, start, child), fn(*child, 2, start, child) + 1));
        printf("\n");
        if(x == -1)
            break;
    }

    return 0;
}

int fn(int curr, int mode, int parent, vector<int>::iterator prnt)
{
    /// 0 = before_nt_served   1 = before_served   2 = before_server
    if(prnt == tree[parent].end() || curr == -1)
    {
        if(mode == 0)
            return inf;
        return 0;
    }

    int& flag = visited[curr][mode];
    int& ret = dp[curr][mode];
    if(flag == cases)
        return ret;

    ret = inf;
    flag = cases;
    int tmp;

    vector<int>::iterator child;
    /// 0 = before_nt_served   1 = before_served   2 = before_server
    if(mode == 0)
    {
        child = tree[curr].begin();
        prnt++;

        tmp = fn(*child, 2, curr, child) + fn(*prnt, 1, parent, prnt) + 1;;
        ret = min(ret, tmp);

        tmp = fn(*child, 0, curr, child) + fn(*prnt, 0, parent, prnt);
        ret = min(ret, tmp);
    }

    /// 0 = before_nt_served   1 = before_served   2 = before_server
    if(mode == 1)
    {
        child = tree[curr].begin();
        prnt++;

        tmp = fn(*child, 0 , curr, child) + fn(*prnt, 1, parent, prnt);
        ret = min(ret, tmp);
    }

    /// 0 = before_nt_served   1 = before_served   2 = before_server
    if(mode == 2)
    {
        child = tree[curr].begin();
        prnt++;

        int r = fn(*prnt, 2, parent, prnt);

        tmp = fn(*child, 1, curr, child) + r;
        ret = min(ret, tmp);

        tmp = fn(*child, 2, curr, child) + r + 1;
        ret = min(ret, tmp);
    }

    return ret;
}

