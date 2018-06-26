#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define MAX 25

double fn(int first, int sec);
pair<int, int> validate();
double gn(int first, int sec, bool flag);

char array[105], b[105];
int len, total, visited[MAX][MAX], cases, p = 1;
double w, l, dp[MAX][MAX];
string var;

int main()
{
    pair<int, int> ret;
    memset(visited, -1, sizeof(visited));
    scanf("%d", &cases);
    double tmp, denom, num;

    while(cases--)
    {
        gets(b);
        getline (std::cin, var);

        len = var.length();

        scanf("%lf %lf", &w, &l);
        ret = validate();

        num = gn(15, 15, 1), denom = gn(15, 15, 0);

        if(denom == 1)
            tmp = 0;
        else
            tmp = num / (1 - denom);

        visited[15][15] = cases, dp[15][15] = tmp;

        printf("Case %d: %.06lf\n", p++, ret.first >= 0 && ret.second >= 0 ? fn(ret.first, ret.second) : -1);
    }

    return 0;
}

double fn(int first, int sec)
{
    if(first == 20 && sec == 20)
        return fn(15, 15);

    if(first == 21 || sec == 21)
        return first == 21;

    int& flag = visited[first][sec];
    double& ret = dp[first][sec];
    if(flag == cases)
        return ret;
    ret = 0, flag = cases;

    ///my serve
    if((first + sec) / 5 % 2 == 0)
        ret += w * fn(first + 1, sec) + (1 - w) * fn(first, sec + 1);
    else
        ret += l * fn(first + 1, sec) + (1 - l) * fn(first, sec + 1);

    return ret;
}

double gn(int first, int sec, bool flag)
{
    ///0 counting cycles
    ///1 counting win

    if(flag == 0)
    {
        if(first == 20 && sec == 20)
            return 1;

        if(first >= 21 || sec >= 21)
            return 0;
    }
    else
    {
        if(first == 20 && sec == 20)
            return 0;

        if(first >= 21 || sec >= 21)
            return first == 21;
    }

    double ret = 0;
    ///my serve
    if((first + sec) / 5 % 2 == 0)
        ret += w * gn(first + 1, sec, flag) + (1 - w) * gn(first, sec + 1, flag);
    else
        ret += l * gn(first + 1, sec, flag) + (1 - l) * gn(first, sec + 1, flag);

    return ret;
}

pair<int, int> validate()
{
    pair<int, int> ret;
    ret.first = ret.second = 0;
    total = 0;

    for(int i = 0; i < len; i++)
    {
        if((ret.first >= 21 || ret.second >= 21))
        {
            ret.first = ret.second = -1;
            return ret;
        }

        ///my serve
        if((ret.first + ret.second) / 5 % 2 == 0)
        {
            if((w == 0.0 && var[i] == 'W') || (w == 1.0 && var[i] != 'W'))
            {
                ret.first = ret.second = -1;
                return ret;
            }
        }
        else
        {
            if((l == 0.0 && var[i] == 'W') || (l == 1.0 && var[i] != 'W'))
            {
                ret.first = ret.second = -1;
                return ret;
            }

        }

        if(var[i] == 'W')
            ret.first++;
        else
            ret.second++;

        if(ret.first == 20 && ret.second == 20)
            ret.first = ret.second = 15;

        total++;
    }

    return ret;
}
