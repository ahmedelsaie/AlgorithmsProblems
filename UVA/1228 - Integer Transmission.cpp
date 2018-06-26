#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ull unsigned long long
#define MAX 100

void pre_process();
ull fn(int zeros, int ones, int curr);
ull bin_int(bool p[]);
ull get(int zeros, int ones, int i, bool type);

ull dp[MAX][MAX], x, ans, power[MAX];
int array[MAX], visited[MAX][MAX], o[MAX], z[MAX];
int n, max_delay, n_z, n_o, cases = 0;
bool p[500];

int main()
{
    memset(visited, -1, sizeof(visited));
    power[0] = 1;

    for(int i = 1; i < MAX; i++)
        power[i] = power[i - 1] * 2;

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            break;
        scanf("%d %llu", &max_delay, &x);
        pre_process();
        ans = fn(0, 0, 1);
        printf("Case %d: %llu %llu %llu\n", cases, ans, get(0, 0, 1, 0), get(0, 0, 1, 1));
    }

    return 0;
}

void pre_process()
{
    int t = 0, t2 = 0;
    ull y = x;
    int i = n;
    memset(array, 0, sizeof(array));

    while(y)
    {
        array[i] = y % 2;
        y = y / 2, i--;
    }

    for(i = 1; i <= n; i++)
    {
        if(array[i] == 0)
            z[t] = i, t++;
        else
            o[t2] = i, t2++;
    }

    n_z = t, n_o = t2;
    z[t] = 1000, o[t2] = 1000;
    cases++;
}

ull bin_int(bool p[])
{
    ull ret = 0;
    for(int i = 1; i <= n; i++)
        ret += p[i] * power[n - i];
    return ret;
}

ull get(int zeros, int ones, int i, bool type)
{
    if(i > n)
        return bin_int(p);

    ull ret;

    if(type)
    {
        if(ones < n_o)
        {
            if(o[ones] > z[zeros])
            {
                if(o[ones] - z[zeros] <= max_delay)
                    p[i] = 1, ret = get(zeros , ones + 1, i + 1, type);
                else
                    p[i] = 0, ret = get(zeros + 1, ones, i + 1, type);
            }
            else
                p[i] = 1, ret = get(zeros , ones + 1, i + 1, type);
        }
        else
            p[i] = 0, ret = get(zeros + 1, ones, i + 1, type);
    }
    else
    {
        if(zeros < n_z)
        {
            if(z[zeros] > o[ones])
            {
                if(z[zeros] - o[ones] <= max_delay)
                    p[i] = 0, ret = get(zeros + 1, ones, i + 1, type);
                else
                    p[i] = 1, ret = get(zeros , ones + 1, i + 1, type);
            }
            else
                p[i] = 0, ret = get(zeros + 1, ones, i + 1, type);
        }
        else
            p[i] = 1, ret = get(zeros , ones + 1, i + 1, type);
    }

    return ret;
}

ull fn(int zeros, int ones, int curr)
{
    if(curr > n)
        return 1;

    int& flag = visited[zeros][ones];
    ull& ret = dp[zeros][ones];
    if(flag == cases)
        return ret;
    flag = cases, ret = 0;

    if(zeros < n_z)
        if(z[zeros] > o[ones])
        {
            if(z[zeros] - o[ones] <= max_delay)
                ret += fn(zeros + 1, ones, curr + 1);
        }
        else
            ret += fn(zeros + 1, ones, curr + 1);

    if(ones < n_o)
        if(o[ones] > z[zeros])
        {
            if(o[ones] - z[zeros] <= max_delay)
                ret += fn(zeros , ones + 1, curr + 1);
        }
        else
            ret += fn(zeros , ones + 1, curr + 1);

    return ret;
}
