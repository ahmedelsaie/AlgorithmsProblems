#include <stdio.h>

double calc(int dist);
double min(double x, double y);
void reset();
double fn(int last, int current);

int n, r;
double b, v, e, f;
double dp[110][110];
double dp2[10005];
int dist[110];

int main()
{
    dist[0] = 0;
    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        for(int i = 1; i <= n; i++)
            scanf("%d", &dist[i]);

        scanf("%lf", &b);
        scanf("%d %lf %lf %lf", &r, &v, &e, &f);

        reset();
        printf("%.4f\n", fn(0, 1));
    }

    return 0;
}

double fn(int last, int current)
{
    if(current == n)
        return calc(dist[current] - dist[last]);

    double &ret = dp[last][current];
    if(ret != -1)
        return ret;

    double choice1, choice2;
    choice1 = fn(current, current + 1) + calc(dist[current] - dist[last]) + b;
    choice2 = fn(last, current + 1);

    return ret = min(choice1, choice2);
}

double calc(int dist)
{
    double &time = dp2[dist];
    if(time != -1)
        return time;

    time = 0;
    for(int x = 0; x < dist ; x++)
    {
        if (x >= r)
            time += 1.0 / (v - e * (x - r));
        else
            time += 1.0 / (v - f * (r - x));
    }
    return time;
}

double min(double x, double y)
{
    if(x < y)
        return x;
    else
        return y;
}

void reset()
{
    for(int i = 0; i < n + 5; i++)
        for(int j = 0; j < n + 5; j++)
            dp[i][j] = -1;

    for(int i = 0; i < 10005; i++)
        dp2[i] = -1;
}
