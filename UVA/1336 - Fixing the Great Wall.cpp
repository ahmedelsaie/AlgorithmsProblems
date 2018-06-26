#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <stdio.h>
using namespace std;
#define ll int

struct block
{
    ll x, cost, penalty;
};
block array[1100];
block help[1100];

template <typename type>
void merge_sort(int start, int last, type array, type swap);
double fn(int last, int curr);
int pre_process();
bool check(int last, int curr, int mode, int mode1);

ll n, start_pos, cases = 0, v;
const int inf = 999999999; // 1 << 29;
double dp[1100][1100];
int visited[1100][1100];
int accum[1100];

int main()
{
    int tmp;

    memset(visited, -1, sizeof(visited));
    while(scanf("%d %d %d", &n, &v, &start_pos) != EOF)
    {
        if(n + v + start_pos == 0)
            break;

        for(int i = 1; i <= n; i++)
            scanf("%d %d %d", &array[i].x, &array[i].cost, &array[i].penalty);
        printf("%d\n", pre_process());
    }

    return 0;
}

double fn(int last, int curr)
{
    if((curr == n + 1 && last == 1) || (last == n && curr == 0))
        return 0;

    int& flag = visited[last][curr];
    double& ret = dp[last][curr];

    if(flag == cases)
        return ret;

    flag = cases, ret = (double)inf;
    double time, tmp,delay;

    if(curr >= last)
    {
        time = abs(array[curr + 1].x - array[curr].x) * 1.0 / v;

        delay = (accum[last - 1] + accum[n] - accum[curr]);
        ///go right
        if(check(last, curr, 0, 0))
            tmp = fn(last, curr + 1) + delay * time, ret = min(ret, tmp);

        ///reverse
        time = abs(array[curr].x - array[last - 1].x) * 1.0 / v;
        if(check(last, curr, 0, 1))
            tmp = fn(curr, last - 1) + delay * time, ret = min(ret, tmp);
    }

    if(curr <= last)
    {
        time = abs(array[curr].x - array[curr - 1].x) * 1.0 / v;
        delay = (accum[curr - 1] + accum[n] - accum[last]);

        ///go left
        if(check(last, curr, 1, 0))
            tmp = fn(last, curr - 1) + delay * time, ret = min(ret, tmp);

        ///reverse
        time = abs(array[last + 1].x - array[curr].x) * 1.0 / v;
        if(check(last, curr, 1, 1))
            tmp = fn(curr, last + 1) + delay * time, ret = min(ret, tmp);
    }

    return ret;
}

bool check(int last, int curr, int mode, int mode1)
{
    if(mode == 0)
    {
        if(mode1 == 0)
            return (curr + 1 <= n || (curr + 1 == n + 1 && last == 1));
        else
            return (last - 1 >= 1 || (last - 1 == 0 && curr == n));
    }

    if(mode == 1)
    {
        ///go left
        if(mode1 == 0)
            return (curr - 1 >= 1 || (curr - 1 == 0 && last == n));
        else
            return (last + 1 <= n || (last + 1 == n + 1 && curr == 1));
    }
}

int pre_process()
{
    int t = n;
    int sum = 0;
    merge_sort(1, n, array, help);

    for(int i = 1; i <= n; i++)
    {
        if(array[i].x > start_pos)
        {
            t = i;
            break;
        }
    }
    for(int i = n + 1; i > t && i - 1 >= 0; i--)
        array[i] = array[i - 1];

    array[0].penalty = array[0].cost = array[0].cost = 0;
    array[t].cost = array[t].penalty = 0, array[t].x = start_pos;
    n++;
    array[n + 1].penalty = array[n + 1].cost = array[n + 1].cost = 0;

    accum[0] = 0;
    for(int i = 1; i <= n; i++)
        accum[i] = accum[i - 1] + array[i].penalty, sum += array[i].cost;

    cases++;

    return sum + fn(t, t);
}

template <typename type>
void merge_sort(int start, int last, type array, type swap)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort(start, middle, array, swap);
    merge_sort(middle + 1, last, array, swap);

    ///MERGING  ///MERGING  ///MERGING  ///MERGING
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        swap[i] = array[i];

    while(main_p <= last)
    {
        if(p1 > middle)
            array[main_p] = array[p2], p2++;

        else if(p2 > last)
            array[main_p] = swap[p1], p1++;

        else if(swap[p1].x < array[p2].x)
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
