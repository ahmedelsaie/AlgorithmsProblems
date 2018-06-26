#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

template <typename type>
void merge_sort(int start, int last, type array, type swap);
bool check(pair<int, int> x, pair<int, int> y);
int fn();

pair<int, int> array[30], help[30];
int n;

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &array[i].first);

        for(int i = 0; i < n; i++)
            scanf("%d", &array[i].second);

        merge_sort(0, n - 1, array, help);
        printf("%d\n",fn());
    }
    return 0;
}

int fn()
{
    int curr = 0, sec = 0;

    for(int i = 0; i < n; i++)
    {
        curr += array[i].first;
        sec += (curr > sec) * (curr - sec) + array[i].second;
    }

    return sec;
}

bool check(pair<int, int> x, pair<int, int> y)
{
    int curr = 0, sec = 0, t, f;
    curr = x.first, sec = x.first + x.second;
    curr += y.first, sec += (curr > sec) * (curr - sec) + y.second;
    t = sec;

    curr = sec = 0;
    curr = y.first, sec = y.first + y.second;
    curr += x.first, sec += (curr > sec) * (curr - sec) + x.second;
    f = sec;

    return t < f;
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

        else if(check(swap[p1], array[p2]))
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}

