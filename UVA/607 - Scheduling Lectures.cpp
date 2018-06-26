#include <stdio.h>

void reset();
int min(int x, int y);
int no_lec(int topic, int time_left);
int calc(int topic, int time_left);
int power(int x, int y);
int disatis(int left);

const int inf = 100000000;
int l, n, c;
int topics[1005];
int dp[1005][510];
int dp2[1005][510];

int main()
{
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
        printf("Case %d:\n", cases);
        printf("Minimum number of lectures: %d\n", no_lec(0, l));
        printf("Total dissatisfaction index: %d\n", calc(0, l));
        cases++;

    }
    return 0;
}

int calc(int topic, int time_left)
{
    int &ret = dp2[topic][time_left];
    if(ret != inf)
        return ret;
    if(topic == n)
        return disatis(time_left);

    int result, ans1, ans2;

    if(time_left == l)
        return ret = calc(topic + 1, time_left - topics[topic]);

    if(time_left - topics[topic] >= 0)
        ans1 = dp[topic + 1][time_left - topics[topic]];
    else
        ans1 = inf;
    ans2 = dp[topic][l];

    if(ans1 < ans2)
    {
        result = calc(topic + 1, time_left - topics[topic]);
    }
    if(ans2 < ans1)
    {
        result = calc(topic, l) + disatis(time_left);
    }

    if(ans1 == ans2)
    {
        int r1 = calc(topic + 1, time_left - topics[topic]);
        int r2 = calc(topic, l) + disatis(time_left);
        return ret = min(r1, r2);
    }
    return ret = result;

}

int disatis(int left)
{

    if(left == 0)
        return 0;

    if(left >= 1 && left <= 10)
        return -1 * c;

    return power((left - 10), 2);

}

int power(int x, int y)
{
    int ans, counter;
    ans = 1;
    for(counter = 0; counter < y; counter++)
        ans = ans * x;
    return ans;
}

int no_lec(int topic, int time_left)
{
    if(time_left < 0)
        return inf;

    if(topic == n)
        return 0;
    int &ret = dp[topic][time_left];
    if(ret != -1)
        return ret;

    if(time_left == l)
        return ret = no_lec(topic + 1, time_left - topics[topic]) + 1;

    int ans1 = no_lec(topic + 1, time_left - topics[topic]);
    int ans2 = no_lec(topic, l);
    return ret = min(ans1, ans2);
}

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

void reset()
{
    for(int i = 0; i < n + 5; i++)
        for(int j = 0; j < l + 5; j++)
            dp[i][j] = -1;


    for(int i = 0; i < n + 5; i++)
        for(int j = 0; j < l + 5; j++)
            dp2[i][j] = inf;
}
