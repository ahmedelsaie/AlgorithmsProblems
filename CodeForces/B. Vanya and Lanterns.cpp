#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>
#define round(x) ((x < 0) ? (ceil((x)-0.000000009)) : (floor((x)+0.000000009)))
using namespace std;
template <typename type>
void merge_sort(int start, int last, type array, type swap);
int lamps[1005], help[1005];
int n, l;
double binary_srch();
bool simulate(double d);
double get();
double diff, first, sec;
int main()
{
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++)
        scanf("%d", &lamps[i]);
    merge_sort(0, n - 1, lamps, help);
    diff = get();
    //printf("cjndjn %d\n",simulate(2.0));
    double ans = max(first, sec);
    ans = max(ans, diff / 2);
    printf("%.9lf\n", ans);
    return 0;
}

double binary_srch()
{
    double big = (double)l, small = (double)0, mid;
    double ans;
    while(big >= small)
    {
        mid = big - small;
        mid = small + .5 * mid;
        //  printf("%lf %lf %lf\n", small, mid, big);

        if(simulate(mid))
        {
            big = mid - 0.00001;
            ans = mid;
        }
        else
            small = mid + 0.00001;
    }

    return ans;
}

double get()
{
    first = (double)lamps[0], sec = (double)l - (double)lamps[n - 1];
        double ret = (double)lamps[1] - (double)lamps[0], diff;

    if(n == 1)
        ret = 0;

    for(int i = 0; i < n - 1; i++)
    {
        diff = (double)lamps[i + 1] - (double)lamps[i];
        ret = max(ret, diff);
    }
    return ret;
}

bool simulate(double d)
{
    if(d >= first && d >= sec)
    {
        if(n == 0)
            return true;

        if(n > 1 && diff <= 2 * d)
            return true;
    }
    return false;



    int i = 0;
    double before, last_covered = (double) lamps[0] - d;
    //  printf("%lf\n", d);
    if(last_covered < 0)
        last_covered = 0;

    if(last_covered > 0)
        return false;

    while(i < n)
    {
        // printf("%lf %lf\n", last_covered, before);

        before = (double) lamps[i] - d;
        if(before < 0)
            before = 0;

        if(last_covered < before)
            return false;

        last_covered = (double) lamps[i] + d;
        i++;
    }

    if(last_covered >= l)
        return true;
    return false;
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

        else if(swap[p1] < array[p2])
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
