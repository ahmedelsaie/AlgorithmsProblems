#include <stdio.h>
#include <cstring>
#include <math.h>

double dist(int i, int j);
double min(double x, double y);
double fn(int last1, int last2, bool f1, bool f2, int i);
void trace();

double dp[105][105][2][2];
bool visited[105][105][2][2];
int x[105];
int y[105];
int go[105];
int back[105];

int n, s1, s2, first, sec;
const int inf = 999999;

int main()
{
    int cases = 1;
    double ans;

    while(true)
    {
        scanf("%d %d %d", &n, &s1, &s2);
        if(n == 0 && s1 == 0 && s2 == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%d %d", &x[i], &y[i]);

        memset(visited, false, sizeof(visited));
        ans = fn(0, 0, 0, 0, 1);

        printf("Case %d: %.2lf\n", cases++, ans);
        trace();

        printf("0 %d", go[0]);
        for(int i = 1; i < first; i++)
            printf(" %d", go[i]);

        printf(" %d", back[sec - 1]);
        for(int i = sec - 2; i >= 0; i--)
            printf(" %d", back[i]);
        printf(" 0");
        printf("\n");
    }

    return 0;
}

double fn(int last1, int last2, bool f1, bool f2, int i)
{
    bool &flag = visited[last1][last2][f1][f2];
    double &ret = dp[last1][last2][f1][f2];

    if(flag)
        return ret;

    flag = true;

    if(i == n)
        return ret = dist(last1, last2);

    ret = 9999999.0;
    double temp;

    if(i == s1 || i == s2)
    {
        if(!f1)
            ret = min(ret, fn(i, last2, true, f2, i + 1) + dist(i, last1));

        if(!f2)
            ret = min(ret, fn(last1, i, f1, true, i + 1) + dist(i, last2));
    }
    else
    {
        temp = fn(i, last2, f1, f2, i + 1) + dist(i, last1);
        ret = min(ret, temp);
        temp = fn(last1, i, f1, f2, i + 1) + dist(i, last2);
        ret = min(ret, temp);
    }

    return ret;
}

void trace()
{
    int i = 1, last1 = 0, last2 = 0;
    bool f1 = false, f2 = false;
    double temp, ret;
    int flag;

    first = 0;
    sec = 0;

    while(i < n)
    {
        ret = inf;
        if(i == s1 || i == s2)
        {
            if(!f1)
            {
                temp = dp[i][last2][true][f2] + dist(i, last1);
                if(temp < ret)
                {
                    ret = temp;
                    flag = 0;
                }
            }

            if(!f2)
            {
                temp = dp[last1][i][f1][true] + dist(i, last2);
                if(temp < ret)
                {
                    ret = temp;
                    flag = 1;
                }
            }
        }
        else
        {
            temp = dp[i][last2][f1][f2] + dist(i, last1);
            if(temp < ret)
            {
                ret = temp;
                flag = 2;
            }

            temp = dp[last1][i][f1][f2] + dist(i, last2);
            if(temp < ret)
            {
                ret = temp;
                flag = 3;
            }
        }
        ///////update///////
        switch (flag)
        {
        case 0:
            last1 = i;
            f1 = true;
            go[first] = i;
            first++;
            break;

        case 1:
            last2 = i;
            f2 = true;
            back[sec] = i;
            sec++;
            break;

        case 2:
            last1 = i;
            go[first] = i;
            first++;
            break;

        case 3:
            last2 = i;
            back[sec] = i;
            sec++;
            break;
        }

        i++;
    }

    return ;
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
