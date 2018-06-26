#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#define MAX 250

///input functions
int get(char tmp[], int limit);
void cpy(char tmp1[], char input[]);
int process(char tmp[]);
void build_bigboss();

///Algo functions
int fn(int left, int curr, int prev);
int min(int x, int y);
int collect(int i);

char input[MAX][MAX];
bool tree[MAX][MAX];
int visited[MAX][MAX];
int dp[MAX][MAX];
int dp2[MAX];
char tmp1[MAX];
int price[MAX];

const int inf = 999999;
const int bigboss = MAX - 1;
int n, cases, limit, desired, ans;

int main()
{
    cases = 0;
    memset(visited, -1, sizeof(visited));

    while(true)
    {
        limit = 0;

        scanf("%d %d", &n, &desired);

        memset(tree, false, sizeof(tree));
        memset(dp2, -1, sizeof(dp2));
        for(int i = 0; i < n;)
        {
            gets(tmp1);
            int d = process(tmp1);
            if(d == inf)
                return 0;

            if(d == 1)
                i++;
        }

        build_bigboss();

        int f;
        for(int i = 0; i < n; i++)
            if(tree[bigboss][i])
            {
                f = i;
                break;
            }
        ans = fn(desired, f, bigboss);

        printf("%d\n", ans);

        cases++;
    }

    return 0;
}

int fn(int left, int curr, int prev)
{
    if(left <= 0)
        return 0;

    if(curr == -1)
        return inf;

    int &ret = dp[left][curr];
    int &flag = visited[left][curr];
    if(flag == cases)
        return ret;
    flag = cases;

    ret = inf;
    int tmp;

    int nxt = -1;
    for(int i = curr + 1; i < n; i++)
        if(tree[prev][i])
        {
            nxt = i;
            break;
        }

    ///take & collect
    int c = collect(curr);
    tmp = price[curr];
    tmp += fn(left - c, nxt, prev);
    ret = min(ret, tmp);

    ///getting sons
    int nxt2 = -1;
    for(int i = 0; i < n; i++)
        if(tree[curr][i] && i != curr)
        {
            nxt2 = i;
            break;
        }

    ///dont take & collect
    for(int i = 0; i <= left; i++)
        ret = min(ret, fn(i, nxt, prev) + fn(left - i, nxt2, curr));

    return ret;
}

int collect(int i)
{
    int &ret = dp2[i];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int j = 0; j < n; j++)
        if(j != i && tree[i][j])
            ret += collect(j);
    ret++;

    return ret;
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int process(char tmp[])
{
    if(tmp[0] == '#')
        return inf;

    if(tmp[0] == '\0')
        return 0;

    char *pch;

    pch = strtok (tmp, " ");
    int h = get(pch, limit);

    if(h == -1)
    {
        cpy(pch, input[limit]);
        h = limit;
        pch = strtok (NULL, " ");
        price[h] = atoi(pch);
        limit++;
    }
    else
    {
        pch = strtok (NULL, " ");
        price[h] = atoi(pch);
    }

    while ((pch = strtok (NULL, " ")))
    {
        int t = get(pch, limit);
        if(t == -1)
        {
            cpy(pch, input[limit]);
            t = limit;
            limit++;
        }
        tree[h][t] = true;
    }

    return 1;
}

int get(char tmp[], int limit)
{
    for(int i = 0; i < limit; i++)
        if(strcmp(tmp, input[i]) == 0)
            return i;
    return -1;
}

void cpy(char tmp1[], char input[])
{
    int l = strlen(tmp1);
    int i;

    for(i = 0; i < l; i++)
        input[i] = tmp1[i];

    input[i] = '\0';

    return ;
}

void build_bigboss()
{
    bool flag;
    for(int i = 0; i < n; i++)
    {
        flag = true;
        for(int j = 0; j < n; j++)
            if(tree[j][i] == true)
            {
                flag = false;
                break;
            }

        if(flag)
            tree[bigboss][i] = true;
    }

}

