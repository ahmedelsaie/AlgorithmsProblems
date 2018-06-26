#include <stdio.h>
#include <cstring>
#include <math.h>

double dist(int i, int j);
double min(double x, double y);
double fn(int last1, int last2, int i);

double dp[1005][1005];
bool visited[1005][1005];
int x[1005];
int y[1005];

int n, s1, s2, first, sec;
const int inf = 999999;

int main()
{
    int cases = 1;
    double ans;

    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d %d", &x[i], &y[i]);

        memset(visited, false, sizeof(visited));
        ans = fn(0, 0, 1);

        printf("%.2lf\n", ans);
    }

    return 0;
}

double fn(int last1, int last2, int i)
{
    bool &flag = visited[last1][last2];
    double &ret = dp[last1][last2];

    if(flag)
        return ret;

    flag = true;

    if(i == n)
        return ret = dist(last1, last2);

    ret = inf;
    double temp;

    temp = fn(i, last2, i + 1) + dist(i, last1);
    ret = min(ret, temp);
    temp = fn(last1, i, i + 1) + dist(i, last2);
    ret = min(ret, temp);

    return ret;
}

double dist(int i, int j)
{
    double x1 = (double)x[i];
    double x2 = (double)x[j];
    double dx = fabs(x1 - x2);
    dx = dx * dx;

    double y1 = (double)y[i];
    double y2 = (double)y[j];
    double dy = fabs(y1 - y2);
    dy = dy * dy;

    dx = dx + dy;
    dx = sqrt(dx);
    return dx;
}

double min(double x, double y)
{
    if(x < y)
        return x;
    else
        return y;
}
