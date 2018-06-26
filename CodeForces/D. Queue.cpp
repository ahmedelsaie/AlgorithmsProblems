#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define ll long long
#define MAX 100009

template <typename type>
void merge_sort(int start, int last, type array, type swap);
int fn();

ll array[MAX], help[MAX];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 0;i < n; i++)
        scanf("%lld", &array[i]);

    printf("%d\n", fn());

    return 0;
}

int fn()
{
    merge_sort(0, n - 1, array, help);
    ll time = 0;
    int i = 0, ret = 0;

    while(i < n)
    {
        if(time <= array[i])
            time += array[i], ret++;
        i++;
    }

    return ret;
}

///merge_sort
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
