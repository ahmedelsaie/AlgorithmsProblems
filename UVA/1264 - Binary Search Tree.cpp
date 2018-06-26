#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 25

struct node
{
    int num, left, right;
};

ll fn(int i);
ll comb(int f, int s);
int fn_cnt(int i);
void  insert(int i, int val);

node tree[MAX];
int cnt[MAX], visited_cnt[MAX], visited[MAX], n, x, idx;
ll fac[MAX], dp[MAX], mod = 9999991, cases;

int main()
{
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 20; i++)
        fac[i] = i * fac[i - 1];

    memset(visited_cnt, -1, sizeof(visited_cnt));
    memset(visited, -1, sizeof(visited));

    scanf("%d", &cases);
    while(cases--)
    {
        for(int i = 0; i <= 20; i++)
            tree[i].left = tree[i].right = -1;

        scanf("%d", &n);
        scanf("%d", &x), tree[1].num = x, idx = 2;

        for(int i = 1; i < n; i++)
            scanf("%d", &x), insert(1, x);

        printf("%lld\n", fn(1));
    }

    return 0;
}

ll fn(int i)
{
    if(i == -1)
        return 1;

    ll& ret = dp[i];
    int& flag = visited[i];
    if(flag == cases)
        return ret;
    flag = cases;
    ret = fn(tree[i].right) % mod * fn(tree[i].left) % mod * comb(fn_cnt(tree[i].right), fn_cnt(tree[i].left)) % mod;
    return ret % mod;
}

ll comb(int f, int s)
{
    return (fac[f + s] / (fac[f] * fac[s]));
}

int fn_cnt(int i)
{
    if(i == -1)
        return 0;

    int& ret = cnt[i];
    int& flag = visited_cnt[i];
    if(flag == cases)
        return ret;
    flag = cases, ret = 0;
    ret = fn_cnt(tree[i].right) + fn_cnt(tree[i].left) + 1;

    return ret;
}

void  insert(int i, int val)
{
    if(tree[i].num < val)
    {
        if(tree[i].right == -1)
            tree[idx].num = val, tree[i].right = idx, idx++;
        else
            insert(tree[i].right, val);
    }
    else if(tree[i].left == -1)
        tree[idx].num = val, tree[i].left = idx, idx++;
    else
        insert(tree[i].left, val);
}
