#include <stdio.h>
#include <cstring>
struct time
{
    int burgers, beer;
};

time max(time x, time y);
time fn(int time_left);
void reset();

int first, sec, t;
const int inf = 9999999;
time dp[10005];
bool visited[10005];

int main()
{
    time ans;
    while(scanf("%d %d %d", &first, &sec, &t) != EOF)
    {
        //memset(visited, false, sizeof(visited));
        reset();
        ans = fn(t);
        printf("%d", ans.burgers);
        if(ans.beer > 0)
            printf(" %d", ans.beer);
        printf("\n");

    }
    return 0;
}

time fn(int time_left)
{
    if(time_left < 0)
    {
        time temp;
        temp.burgers = -1 * inf;
        temp.beer = inf;
        return temp;
    }

    if(time_left == 0)
    {
        time temp;
        temp.burgers = 0;
        temp.beer = 0;
        return temp;
    }
    bool &flag = visited[time_left];
    if(flag)
        return dp[time_left];
    flag = true;
    time temp, ret;

    ret.beer = time_left;
    ret.burgers = 0;

    temp = fn(time_left - first);
    temp.burgers++;
    ret = max(temp, ret);

    temp = fn(time_left - sec);
    temp.burgers++;
    ret = max(temp, ret);

    return dp[time_left] = ret;
}

time max(time x, time y)
{
    if(x.beer == 0 && y.beer == 0)
    {
        if(x.burgers > y.burgers)
            return x;
        else
            return y;
    }

    if(x.beer == 0)
        return x;

    if(y.beer == 0)
        return y;

    if(x.beer < y.beer)
        return x;

    if(y.beer < x.beer)
        return y;


    if(x.beer == y.beer)
    {
        if(x.burgers > y.burgers)
            return x;
        else
            return y;

    }
}

void reset()
{
    for(int i = 0; i < t + 2; i++)
        visited[i] = false;
}
