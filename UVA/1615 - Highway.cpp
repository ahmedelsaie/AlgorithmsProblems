#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 1000009

int bin_search(int i, int flag);
int get_dist(int i, int mid);
void pre_process();
int bin_search2(int x);
int fn(int start, int end);

pair<int, int> array[MAX], a[MAX];
int n, l, d, k, flag[MAX], my_close[MAX], first_open[MAX], first_close[MAX], diff[4 * MAX];
const int inf = 999999999;

int main()
{
    while(scanf("%d %d", &l, &d) != EOF)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &array[i].first, &array[i].second);

        pre_process();
        //  printf("== %d\n",my_close[0]);
        printf("%d\n", fn(0, my_close[0]));
    }


    return 0;
}

void pre_process()
{
    for(int i = 0; i < n; i++)
    {
        a[i].first = bin_search(i, 1);
        a[i].second = bin_search(i, 0);

        //    printf("===== %d %d\n", a[i].first, a[i].second);
    }

    sort(a, a + n);

    int j = 0;
    for(int i = 0; i < n; i++)
        diff[j++] = a[i].first, diff[j++] = a[i].second;

    sort(diff, diff + j);

    k = 0;
    int i = 0, prev = diff[0];
    while(i < j)
    {
        if(prev != diff[i])
            diff[k++] = prev, prev = diff[i];
        i++;
    }
    diff[k++] = prev;

    memset(flag, -1, sizeof(flag));
    for(int i = 0; i < n; i++)
    {
        int tmp = bin_search2(a[i].first);
        if(flag[tmp] == -1)
            flag[tmp] = 0;
        else if(flag[tmp] == 1)
            flag[tmp] = 2;

        tmp = bin_search2(a[i].second);
        if(flag[tmp] == -1)
            flag[tmp] = 1;
        else if(flag[tmp] == 0)
            flag[tmp] = 2;
    }

    first_open[k] = first_close[k] = inf;
    for(int i = k - 1; i >= 0; i--)
    {
        if(flag[i] == 2 || flag[i] == 0)
            first_open[i] = i;
        else
            first_open[i] = first_open[i + 1];

        if(flag[i] == 2 || flag[i] == 1)
            first_close[i] = i;
        else
            first_close[i] = first_close[i + 1];

        my_close[i] = inf;
    }

    for(int i = 0; i < n; i++)
    {
        int tmp = bin_search2(a[i].first);
        int tmp2 = bin_search2(a[i].second);
        my_close[tmp] = min(my_close[tmp], tmp2);
    }

}

int fn(int start, int end)
{
    //if(start==inf || end==inf)
    //  return 0;

    int nxt_start = first_open[start];
    if(nxt_start == inf)
        return 1;

    if(nxt_start == start)
        nxt_start = first_open[start + 1];

    if(nxt_start == inf)
        return 1;

    int nxt_end = my_close[nxt_start];

//    printf("%d %d\n",nxt_start,nxt_end);

    if(nxt_start > end)
        return 1 + fn(nxt_start, nxt_end);
    else
        return fn(nxt_start, min(nxt_end, end));
}

int bin_search2(int x)
{
    int small = 0, big = k - 1, mid;

    while(big >= small)
    {
        mid = (big + small) / 2;
        if(diff[mid] == x)
            return mid;

        if(diff[mid] > x)
            big = mid - 1;
        else
            small = mid + 1;
    }
}

int bin_search(int i, int flag)
{
    if(flag == 0)
    {
        int small = array[i].first, big = l, mid, ret = -1;

        while(big >= small)
        {
            mid = (big + small) / 2;
            if(get_dist(i, mid) && mid > ret)
                ret = mid;

            if(get_dist(i, mid))
                small = mid + 1;
            else
                big = mid - 1;
        }
        return ret;
    }
    else
    {
        int small = 0, big = array[i].first, mid, ret = inf;

        while(big >= small)
        {
            mid = (big + small) / 2;
            if(get_dist(i, mid) && mid < ret)
                ret = mid;

            if(get_dist(i, mid))
                big = mid - 1;
            else
                small = mid + 1;
        }
        return ret;
    }
}

int get_dist(int i, int mid)
{
    int tmp = abs(array[i].first - mid);
    tmp = tmp * tmp;
    tmp += (array[i].second * array[i].second);
    double d2 = (double)d;
    double d3 = (double)tmp;
    d3 = sqrt(d3);

    return d3 <= d2;
}

