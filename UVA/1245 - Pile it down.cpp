#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

pair<bool, int> dp[1001][1001][4];
bool visited[1001][1001][4];
pair<bool, int> fn(int x, int y, int mode);
pair<bool, int> max(pair<bool, int>x, pair<bool, int> y);
void tabular();

int main()
{
    int x, y, p, cases;
    pair<bool, int> ans;
    //memset(visited, 0, sizeof(visited));
    tabular();
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d %d", &x, &y, &p);
        //ans = fn(x, y, 0);
        ans = dp[x][y][0];
        printf("%s %d\n", ans.first ? "Sita" : "Gita", ans.second + 2 * p);
    }

    return 0;
}

void tabular()
{
    for(int x = 0; x <= 1000; x++)
        for(int y = 0; y <= 1000; y++)
            for(int mode = 0; mode <= 3; mode++)
            {
                pair<bool, int>& ret = dp[x][y][mode];
                ret.first = ret.second = 0;

                if(x == 0 && y == 0)
                {
                    if(mode != 0)
                        ret.first = 1;
                }
                else
                {
                    if(mode == 0)
                    {
                        if(x > 0)
                            ret = max(ret, dp[x - 1][y][1]);

                        if(y > 0)
                            ret = max(ret, dp[x][y - 1][2]);

                        if(y > 0 && x > 0)
                            ret = max(ret, dp[x - 1][y - 1][3]);

                        ret.second++;
                    }
                    else if(mode == 1)
                    {
                        if(x > 0)
                            ret = max(ret, dp[x - 1][y][mode]);
                    }
                    else if(mode == 2)
                    {
                        if(y > 0)
                            ret = max(ret, dp[x][y - 1][mode]);
                    }

                    else if(mode == 3)
                        if(y > 0 && x > 0)
                            ret = max(ret, dp[x - 1][y - 1][mode]);

                    if(mode != 0)
                    {
                        pair<bool, int> tmp = dp[x][y][0];
                        tmp.first = !tmp.first;
                        ret = max(ret, tmp);
                    }
                }
            }
}

pair<bool, int> fn(int x, int y, int mode)
{
    if(x == 0 && y == 0)
    {
        pair<bool, int> tmp;
        tmp.first = 1, tmp.second = 0;
        if(mode == 0)
            tmp.first = 0;
        return tmp;
    }

    pair<bool, int>& ret = dp[x][y][mode];
    bool& flag = visited[x][y][mode];
    if(flag)
        return ret;

    flag = 1, ret.first = ret.second = 0;

    if(mode == 0)
    {
        if(x > 0)
            ret = max(ret, fn(x - 1, y, 1));

        if(y > 0)
            ret = max(ret, fn(x, y - 1, 2));

        if(y > 0 && x > 0)
            ret = max(ret, fn(x - 1, y - 1, 3));

        ret.second++;
    }

    if(x > 0 && mode == 1)
        ret = max(ret, fn(x - 1, y, mode));

    if(y > 0 && mode == 2)
        ret = max(ret, fn(x, y - 1, mode));

    if(mode == 3 && y > 0 && x > 0)
        ret = max(ret, fn(x - 1, y - 1, mode));

    if(mode != 0)
    {
        pair<bool, int> tmp = fn(x, y, 0);
        tmp.first = !tmp.first;
        ret = max(ret, tmp);
    }

    return ret;
}

pair<bool, int> max(pair<bool, int>x, pair<bool, int> y)
{
    if(x.first && y.first)
    {
        if(x.second <= y.second)
            return x;
        return y;
    }

    if(!x.first && !y.first)
    {
        if(x.second >= y.second)
            return x;
        return y;
    }

    if(x.first && !y.first)
        return x;
    return y;

}

/*
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

pair<bool, int>  dp[1001][1001][4];
bool visited[1001][1001][4];
pair<bool, int> fn(int x, int y, int mode);
pair<bool, int> max(pair<bool, int>x, pair<bool, int> y);
void tabular();

int main()
{
    int x, y, p, cases;
    pair<bool, int> ans;
    //memset(visited, 0, sizeof(visited));
    tabular();
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d %d", &x, &y, &p);
        //ans = fn(x, y, 0);
        ans = dp[x][y][0];
        printf("%s %d\n", ans.first ? "Sita" : "Gita", ans.second + 2 * p);
    }

    return 0;
}

void tabular()
{
    for(int x = 0; x <= 1000; x++)
        for(int y = 0; y <= 1000; y++)
            for(int mode = 0; mode <= 3; mode++)
            {
                pair<bool, int>& ret = dp[x][y][mode];
                ret.first = ret.second = 0;

                if(x == 0 && y == 0)
                {
                    if(mode != 0)
                        ret.first = 1;
                }
                else
                {
                    if(mode == 0)
                    {
                        if(x > 0)
                            ret = max(ret, dp[x - 1][y][1]);

                        if(y > 0)
                            ret = max(ret, dp[x][y - 1][2]);

                        if(y > 0 && x > 0)
                            ret = max(ret, dp[x - 1][y - 1][3]);

                        ret.second++;
                    }

                    if(x > 0 && mode == 1)
                        ret = max(ret, dp[x - 1][y][mode]);

                    if(y > 0 && mode == 2)
                        ret = max(ret, dp[x][y - 1][mode]);

                    if(mode == 3 && y > 0 && x > 0)
                        ret = max(ret, dp[x - 1][y - 1][mode]);

                    if(mode != 0)
                    {
                        pair<bool, int> tmp = dp[x][y][0];
                        tmp.first = !tmp.first;
                        ret = max(ret, tmp);
                    }
                }
            }
}

pair<bool, int> fn(int x, int y, int mode)
{
    if(x == 0 && y == 0)
    {
        pair<bool, int> tmp;
        tmp.first = 1, tmp.second = 0;
        if(mode == 0)
            tmp.first = 0;
        return tmp;
    }

    pair<bool, int>& ret = dp[x][y][mode];
    bool& flag = visited[x][y][mode];
    if(flag)
        return ret;

    flag = 1, ret.first = ret.second = 0;

    if(mode == 0)
    {
        if(x > 0)
            ret = max(ret, fn(x - 1, y, 1));

        if(y > 0)
            ret = max(ret, fn(x, y - 1, 2));

        if(y > 0 && x > 0)
            ret = max(ret, fn(x - 1, y - 1, 3));

        ret.second++;
    }

    if(x > 0 && mode == 1)
        ret = max(ret, fn(x - 1, y, mode));

    if(y > 0 && mode == 2)
        ret = max(ret, fn(x, y - 1, mode));

    if(mode == 3 && y > 0 && x > 0)
        ret = max(ret, fn(x - 1, y - 1, mode));

    if(mode != 0)
    {
        pair<bool, int> tmp = fn(x, y, 0);
        tmp.first = !tmp.first;
        ret = max(ret, tmp);
    }

    return ret;
}

pair<bool, int> max(pair<bool, int>x, pair<bool, int> y)
{
    if(x.first && y.first)
    {
        if(x.second <= y.second)
            return x;
        return y;
    }

    if(!x.first && !y.first)
    {
        if(x.second >= y.second)
            return x;
        return y;
    }

    if(x.first && !y.first)
        return x;
    return y;

}
*/
