#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

double fn();
bool comp(pair<double, double> i, pair<double, double> j);
template <typename type>
void merge_sort(int start, int last, type arr, type swap);

pair<double, double> arr[10005], help[10005];
int n;

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%lf %lf", &arr[i].first, &arr[i].second);
        merge_sort(0, n - 1, arr, help);

        float res = fn();
        if(res >= 10000)
            printf("INFINITY");
        else
            printf("%.4lf", res);
        printf("\n");
    }

    return 0;
}

double fn()
{
    int x, y;
    double ret = 100000000, dx = 0, dy;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            dx = arr[j].first - arr[i].first;// dx = dx * dx;
            dy = fabs(arr[i].second - arr[j].second);
            if(dx > 10000.0)
                break;
            dx = dx * dx, dy = dy * dy;
            dx = dx + dy;
            ret = min(ret, dx);
        }

    return sqrt(ret);
}

///merge_sort
template <typename type>
void merge_sort(int start, int last, type arr, type swap)
{
    if(last <= start)
        return;

    int middle = (last - start) / 2;
    middle = start + middle;

    merge_sort(start, middle, arr, swap);
    merge_sort(middle + 1, last, arr, swap);

    ///MERGING  ///MERGING  ///MERGING  ///MERGING
    int p1 = start;
    int p2 = middle + 1;
    int main_p = start;

    for(int i = start; i <= middle; i++)
        swap[i] = arr[i];

    while(main_p <= last)
    {
        if(p1 > middle)
            arr[main_p] = arr[p2], p2++;

        else if(p2 > last)
            arr[main_p] = swap[p1], p1++;

        else if(comp(swap[p1], arr[p2]))
            arr[main_p] = swap[p1], p1++;

        else
            arr[main_p] = arr[p2], p2++;

        main_p++;
    }
    return;
}

bool comp(pair<double, double> i, pair<double, double> j)
{
    if(i.first == j.first)
        return i.second < j.second;

    return i.first < j.first;
}
