#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

double fn(int i);

const double inf = 0x3f3f3f3f3f3f3f3f;
int n;
double shelf_width;

bool visited[1005];
double dp[1005];
double height[1005];
double width[1005];

int main()
{
    double ans;

    while (scanf("%d%lf", &n, &shelf_width) == 2 && n + shelf_width)
    {
        for(int i = 0; i < n; i++)
            scanf("%lf%lf", &height[i], &width[i]);

        memset(visited, false, sizeof(visited));
        ans = fn(0);

        printf("%.4lf\n", ans);
    }

    return 0;
}

double fn(int i)
{
    if(i == n)
        return 0;

    bool &flag = visited[i];
    double &ret = dp[i];

    if(flag)
        return ret;
    ret = inf;
    flag = true;

    double w = 0, h = 0;

    for(int j = i; j < n ; j++)
    {
        w += width[j];
        h = max(h, height[j]);
        if (w - shelf_width > 1e-9) break;
        ret = min(ret, h + fn(j + 1));
    }

    return ret;
}


