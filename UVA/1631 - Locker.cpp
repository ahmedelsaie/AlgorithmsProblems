#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 1005

struct state
{
    int f, s, t, p, val;
};

const int inf = 9999999999;
bool v[11][11][11][1005];
int array[1005], array2[1005], n;
char input[MAX];
int bfs();

int main()
{
    while(scanf("%s", input) != EOF)
    {
        n = strlen(input);
        for(int i = 0; i < n; i++)
            array[i] = input[i] - '0';

        scanf("%s", input);
        for(int i = 0; i < n; i++)
            array2[i] = input[i] - '0';

        printf("%d\n", bfs());
    }

    return 0;
}

int bfs()
{
    memset(v, 0, sizeof(v));
    int ret = inf;
    state tmp, tmp2;
    queue<state> q;

    tmp.val = tmp.p = 0;
    int p = tmp.p;
    tmp.f = array2[0], tmp.s = array2[1], tmp.t = array2[2];
    v[tmp.f][tmp.s][tmp.t][p] = 1;
    q.push(tmp);

    while(q.empty() == 0)
    {
        tmp = q.front();
        q.pop();
        p = tmp.p;
        ///100
        tmp2 = tmp;
        tmp2.f = (tmp.f + 1) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///010
        tmp2 = tmp;
        tmp2.s = (tmp.s + 1) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///001
        tmp2 = tmp;
        tmp2.t = (tmp.t + 1) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///100
        tmp2 = tmp;
        tmp2.f = (tmp.f - 1 + 10) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///010
        tmp2 = tmp;
        tmp2.s = (tmp.s  - 1 + 10) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///001
        tmp2 = tmp;
        tmp2.t = (tmp.t - 1 + 10) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///011
        tmp2 = tmp;
        tmp2.t = (tmp.t - 1 + 10) % 10;
        tmp2.s = (tmp.s - 1 + 10) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///011
        tmp2 = tmp;
        tmp2.t = (tmp.t + 1) % 10;
        tmp2.s = (tmp.s + 1) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///110
        tmp2 = tmp;
        tmp2.f = (tmp.f - 1 + 10) % 10;
        tmp2.s = (tmp.s - 1 + 10) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;


        ///110
        tmp2 = tmp;
        tmp2.f = (tmp.f + 1) % 10;
        tmp2.s = (tmp.s + 1) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///111
        tmp2 = tmp;
        tmp2.f = (tmp.f - 1 + 10) % 10;
        tmp2.s = (tmp.s - 1 + 10) % 10;
        tmp2.t = (tmp.t - 1 + 10) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        ///111
        tmp2 = tmp;
        tmp2.f = (tmp.f + 1) % 10;
        tmp2.s = (tmp.s + 1) % 10;
        tmp2.t = (tmp.t + 1) % 10;
        tmp2.val++;
        if(v[tmp2.f][tmp2.s][tmp2.t][p] == 0)
            q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;

        if(array[p] == tmp.f)
        {
            tmp2 = tmp;
            tmp2.f = tmp2.s;
            tmp2.s = tmp2.t;
            tmp2.t = array2[p + 3];
            tmp2.p++;
            if(v[tmp2.f][tmp2.s][tmp2.t][tmp2.p] == 0)
                q.push(tmp2), v[tmp2.f][tmp2.s][tmp2.t][p] = 1;
        }

        if(tmp.p == n)
            ret = min(ret, tmp.val);

    }

    return ret;
}
