#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 105

double fn(int r, int s, int p, int who);
double dp[MAX][MAX][MAX][4];
bool visited[MAX][MAX][MAX][4];
int r1, s1, p1;

int main()
{
    memset(visited, 0, sizeof(visited));
    scanf("%d %d %d", &r1, &s1, &p1);

    printf("%.12lf %.12lf %.12lf\n", fn(r1, s1, p1, 0), fn(r1, s1, p1,1), fn(r1, s1, p1, 2));
    return 0;
}

double fn(int r, int s, int p, int who)
{
    if(who == 0)
    {
        if(r == 0)
            return 0;

        if(s + p == 0)
            return 1;
    }

    if(who == 1)
    {
        if(s == 0)
            return 0;

        if(r + p == 0)
            return 1;
    }

    if(who == 2)
    {
        if(p == 0)
            return 0;

        if(s + r == 0)
            return 1;
    }

    bool& flag = visited[r][s][p][who];
    double& ret = dp[r][s][p][who];
    if(flag)
        return ret;

    flag = 1, ret = 0;

    double all = (double)r + (double)s + (double)p;
    all = all * (all - 1);
    all = all / 2;

    double curr, c;
    c = (double)((s * (s - 1)) / 2) + (double)((r * (r - 1)) / 2) + (double)((p * (p - 1)) / 2);
    c = c / all;
    c = 1 - c;

    ///r kills s
    if(r && s)
    {
        curr = (double)r * (double)s;
        curr = curr / all;
        ret += curr * fn(r, s - 1, p, who);
    }

    ///s kills p
    if(s && p)
    {
        curr = (double)s * (double)p;
        curr = curr / all;
        ret += curr * fn(r, s, p - 1, who);
    }

    ///p kills r
    if(p && r)
    {
        curr = (double)p * (double)r;
        curr = curr / all;
        ret += curr * fn(r - 1, s, p, who);
    }

    ret = ret / c;
    return ret;
}
