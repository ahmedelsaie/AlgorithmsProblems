#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

#define ll long long
using namespace std;
ll fn(int curr, int parent, vector<int>::iterator t, bool state);
void trace(int curr, int parent, vector<int>::iterator t, bool state);

int n;
vector<int> tree[500009];
ll dp[500009][2];
ll inf = 99999999999999;
bool flag = 0;

int main()
{
    int x;
    scanf("%d", &n);
    for(int i = 0; i < n + 3; i++)
        tree[i].clear();

    int j = 1;
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d", &x);
        tree[x].push_back(j + 1);
        j++;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[0][1] = 0;

/*    for(int i = 1; i <= n; i++)
    {
        printf("%d ====", i);
        for(vector<int>::iterator t = tree[i].begin(); t != tree[i].end(); t++)
            printf("%d ", *t);
        printf("\n");
    }
    */
    vector<int>::iterator t = tree[1].begin();

    ll ans = fn(*(t), 1, t, 1);
    //printf("dffd %d %d\n", *(t), 1);
    printf("%lld\n", ans);
    trace(*(t), 1, t, 1);
    return 0;
}


void trace(int curr, int parent, vector<int>::iterator t, bool state)
{
    if(t == tree[parent].end() || curr == 0)
        return ;

    int nxt, child;
    vector<int>::iterator r;

    if(t + 1 == tree[curr].end())
        nxt = 0;
    else
    {
        t++, nxt = *(t);
        if(t == tree[parent].end())
            nxt=0;

    }

    if(tree[curr].size() == 0)
        child = 0;
    else
    {
        r = tree[curr].begin();
        child = *(r);
    }
    ll choice2;
    ll choice1 = dp[child][state] + dp[nxt][state];
    if(state)
        choice2 = dp[child][0] + dp[nxt][0] + 1000;
    else
        choice2 = -1 * inf;

    if(choice1 > choice2)
    {
        trace(nxt, parent, t, state);
        trace(child, curr, r, state);
    }
    else
    {
        if(flag)
            printf(" ");
        else
            flag = 1;
        printf("%d", curr);
        trace(nxt, parent, t, 0);
        trace(child, curr, r, 0);
    }

}


ll fn(int curr, int parent, vector<int>::iterator t, bool state)
{
    //printf("iam %d\n",curr);
    if(t == tree[parent].end() || curr == -1)
        return 0;

    ll& ret = dp[curr][state];
    if(ret != -1)
        return ret;

    ret = -1 * inf;
    int nxt, child;
    vector<int>::iterator r;

    if(t + 1 == tree[curr].end())
        nxt = -1;
    else
        t++, nxt = *(t);

    if(tree[curr].size() == 0)
        child = -1;
    else
    {
        r = tree[curr].begin();
        child = *(r);
    }

    ret = max(ret, fn(child, curr, r, state) + fn(nxt, parent, t, state));
    if(state)
        ret = max(ret, fn(child, curr, r, 0) + fn(nxt, parent, t, 0) + 1000);

    return ret;
}
