#include <stdio.h>
struct table
{
    int lec;
    int dis;
};

void reset();
table min(table x, table y);
table no_lec(int topic, int time_left);
int power(int x, int y);
int disatis(int left);

const int inf = 100000000;
int l, n, c;
int topics[1005];
table dp[1005][510];

int main()
{
    table last;
    int cases = 1;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        scanf("%d %d", &l, &c);

        for(int i = 0; i < n; i++)
            scanf("%d", &topics[i]);

        reset();

        if(cases > 1)
            printf("\n");
        last = no_lec(0, l);
        printf("Case %d:\n", cases);
        printf("Minimum number of lectures: %d\n", last.lec);
        printf("Total dissatisfaction index: %d\n", last.dis);
        cases++;
    }
    return 0;
}

table no_lec(int topic, int time_left)
{
    table ans;
    if(time_left < 0)
    {
        ans.lec = inf;
        ans.dis = inf;
        return ans;
    }
    if(topic == n)
    {
        ans.lec = 0;
        ans.dis = disatis(time_left);
        return ans;
    }
    table &ret = dp[topic][time_left];
    if(ret.lec != -1)
        return ret;

    if(time_left == l)
    {
        ret = no_lec(topic + 1, time_left - topics[topic]);
        ret.lec += 1;
        return ret;
    }

    table ans1 = no_lec(topic + 1, time_left - topics[topic]);
    table ans2 = no_lec(topic, l);
    ans2.dis += disatis(time_left);
    return ret = min(ans1, ans2);
}

int disatis(int left)
{
    if(left == 0)
        return 0;

    if(left >= 1 && left <= 10)
        return -1 * c;

    return power((left - 10), 2);
}

table min(table x, table y)
{
    if(x.lec < y.lec)
        return x;
    if(x.lec > y.lec)
        return y;

    if(x.dis < y.dis)
        return x;
    else
        return y;
}

int power(int x, int y)
{
    int ans = 1;
    for(int i = 0; i < y; i++)
        ans = ans * x;
    return ans;
}

void reset()
{
    for(int i = 0; i < n + 5; i++)
        for(int j = 0; j < l + 5; j++)
            dp[i][j].lec = -1;
}
