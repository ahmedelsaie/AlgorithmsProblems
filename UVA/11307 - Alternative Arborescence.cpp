#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string.h>
#define MAX 10009
using namespace std;

int fn(int before, int curr);
int process(char tmp[]);
int min(int x, int y);

vector<int> tree[MAX];
int visited[7][MAX];
int dp[7][MAX];
char tmp1[MAX + 100];

int visited_root[MAX + 100];

int n, cases, start;
const int inf = 9999999;

int main()
{
    memset(visited, -1, sizeof(visited));
    memset(visited_root, -1, sizeof(visited_root));
    cases = 0;

    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        for(int i = 0; i < n;)
        {
            gets(tmp1);
            if(process(tmp1) == 1)
                i++;
        }

        for(int i = 0; i < n; i++)
            if(visited_root[i] != cases)
            {
                start = i;
                break;
            }


        printf("%d\n", fn(0, start));

        cases++;
    }
    return 0;
}

int fn(int before, int curr)
{
    int &ret = dp[before][curr];
    int &flag = visited[before][curr];

    if(flag == cases)
        return ret;

    flag = cases;
    ret = inf;
    int tmp;

    for(int i = 1; i <= 6; i++)
    {
        if(before != i)
        {
            tmp = 0;
            for (std::vector<int>::iterator t = tree[curr].begin(); t != tree[curr].end(); t++)
                tmp += fn(i, *t);
            ret = min(ret, tmp + i);
        }
    }

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
    if(tmp[0] == '\0')
        return 0;

    char *pch;

    pch = strtok (tmp, ":");
    int curr = atoi(pch);
    tree[curr].clear();

    while ((pch = strtok (NULL, " ")))
    {
        int x = atoi(pch);
        visited_root[x] = cases;
        tree[curr].push_back(x);
    }

    return 1;
}
