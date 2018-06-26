#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 1005
#define type long long

double fn(int mass, int level);
double get(type mass, int i);

type T[MAX], C[MAX], L[MAX], S[MAX];
int visited[10005][MAX];
double dp[10005][MAX];
const double inf = 99999999;
int n, cases;

int main()
{
    memset(visited, -1, sizeof(visited));
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%lld %lld %lld %lld", &S[i], &L[i], &T[i], &C[i]);
        printf("%.0f\n", fn(0, 0));
    }
    return 0;
}

double fn(int mass, int level)
{
    if(level == n)
        return 0;

    int& flag = visited[mass][level];
    double& ret = dp[mass][level];
    if(flag == cases)
        return ret;
    flag = cases, ret = fn(mass, level + 1);
    double thrust = get(mass + S[level] + L[level], level);

    if(10 * T[level] >= 98 * (mass + S[level] + L[level]) && (mass + S[level] + L[level]) <= 10000)
        ret = max(ret, fn(mass + S[level] + L[level], level + 1) + thrust);
    return ret;
}

double get(type mass, int i)
{
    double ret = (T[i] * log((double)mass / (mass - L[i])) - 9.8 * L[i]) / C[i];
    return ret;
}
