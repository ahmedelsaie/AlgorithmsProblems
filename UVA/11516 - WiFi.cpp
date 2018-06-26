#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool check(double x);
void fn();
int nxt_city(double last_router, int current_city, double x);
void merge(int start, int end);
void merge_sort(int start, int last);

int routers;
int cities;
int city[1000009];
int help[1000009];
double ans;

int main()
{
    int cases;
    scanf("%d", &cases);

    for(int c = 0; c < cases; c++)
    {
        scanf("%d %d", &routers, &cities);
        for(int i = 0; i < cities; i++)
            scanf("%d", &city[i]);
        merge_sort(0, cities - 1);
        fn();

        printf("%.1f\n", ans + 10E-4);
    }

    return 0;
}

void merge_sort(int start, int last)
{
    //printf("start= %d end= %d\n",start,last);
    if(start == last)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;
    merge_sort(start, middle);
    merge_sort(middle + 1, last);
    merge(start, last);
    return;
}

void merge(int start, int end)
{
    int middle = (end - start) / 2;
    middle = middle + start;
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        help[i] = city[i];

    while(main_p <= end)
    {
        if(p1 > middle)
        {
            city[main_p] = city[p2];
            p2++;
            main_p++;
            continue;
        }

        if(p2 > end)
        {
            city[main_p] = help[p1];
            p1++;
            main_p++;
            continue;
        }

        if(help[p1] < city[p2])
        {
            city[main_p] = help[p1];
            p1++;
        }
        else
        {
            city[main_p] = city[p2];
            p2++;
        }
        main_p++;
    }
    return ;
}

void fn()
{
    double big, small, mid;
    small = 0;
    big = (double)city[cities - 1];

    while(big >= small)
    {
        mid = big - small;
        mid = small + .5 * mid;

        if(check(mid))
        {
            big = mid - .01;
            ans = mid;
        }
        else
            small = mid + .01;
    }

    return ;
}

bool check(double x)
{
    int current_city = 0;
    int used_routers = 0;
    double last_router;

    while(current_city < cities)
    {
        last_router = city[current_city] + x;
        used_routers++;
        if(used_routers > routers)
            return false;
        current_city = nxt_city(last_router, current_city, x);
    }
    return true;
}

int nxt_city(double last_router, int current_city, double x)
{
    int i;
    for(i = current_city; i < cities; i++)
    {
        if(city[i] - last_router > x)
            return i;
    }
    return i;
}

