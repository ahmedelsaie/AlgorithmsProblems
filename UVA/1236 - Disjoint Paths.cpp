#include <stdio.h>
#include <cstring>
#define MAX 65
int fn(int curr, int first_edge, int left, int state, int before);
int get_first(int curr, int before);
int get_nxt(int before, int curr, int first_edge);
int make_leaf();
int max(int x, int y);

int visited[MAX][MAX][MAX][3];
int dp[MAX][MAX][MAX][3];
int tree[MAX][MAX];
bool leafs[MAX];

const int inf = 999999999;
int cases, n, k, start, start_son;

int main()
{
    int x, y, val;
    memset(visited, -1, sizeof(visited));

    scanf("%d", &cases);

    while(cases--)
    {
        memset(tree, 0, sizeof(tree));

        scanf("%d %d", &n, &k);
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d %d", &x, &y, &val);
            tree[x][y] = val;
            tree[y][x] = val;
        }

        start = make_leaf();
        for(int i = 0; i <= n; i++)
        {
            if(tree[start][i] != 0 && i != start)
            {
                start_son = i;
                break;
            }
        }
        printf("%d", fn(start_son, start, k, 0, start));
        printf("\n");

    }
    return 0;
}

int fn(int curr, int first_edge, int left, int state, int before)
{
    if(left < 0)
        return -1 * inf;

    int& ret = dp[curr][first_edge][left][state];
    int& flag = visited[curr][first_edge][left][state];

    if(flag == cases)
        return ret;

    ret = 0;
    flag = cases;
    int tmp;

    ///first son & nxt colleague
    int son = get_first(curr, before);
    int col = get_nxt(before, curr, first_edge);

    for(int i = 0; i <= left; i++)
    {
        if(state == 1)
        {
            ///take it
            tmp = 0;
            if(col != -1)
                tmp += fn(col, first_edge, i, state + 1, before);
            if(son != -1)
                tmp += fn(son, before, left - i, 1, curr);
            ret = max(tmp + tree[curr][before], ret);
        }

        ///dont take anything
        tmp = 0;
        if(col != -1)
            tmp += fn(col, first_edge, i, state, before);
        if(son != -1)
            tmp += fn(son, before, left - i, 0, curr);
        ret = max(tmp, ret);

    }

    int new_left = left - 1;
    for(int i = 0; i <= new_left; i++)
    {
        if(state == 0)
        {
            ///take it
            tmp = 0;
            if(son != -1)
                tmp += fn(son, before, new_left - i, state + 1, curr);
            if(col != -1)
                tmp += fn(col, first_edge, i, state + 1, before);
            ret = max(tmp + tree[curr][before], ret);
        }
    }

    return ret;
}

int get_first(int curr, int before)
{
    if(leafs[curr])
        return -1;

    for(int i = 0; i <= n; i++)
        if(tree[curr][i] != 0 && i != before)
            return i;
}

int get_nxt(int before, int curr, int first_edge)
{
    for(int i = curr + 1; i <= n; i++)
        if(tree[before][i] != 0 && i != curr && i != first_edge && i != before)
            return i;
    return -1;
}

int make_leaf()
{
    int flag, ret = 0;

    for(int i = 1; i <= n; i++)
    {
        flag = 0;
        for(int j = 0; j <= n; j++)
        {
            if(tree[i][j] != 0)
                flag++;
            if(flag > 1)
                break;
        }

        if(flag == 1)
        {
            leafs[i] = true;
            if(ret == 0)
                ret = i;
        }
        else
            leafs[i] = false;
    }

    return ret;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
