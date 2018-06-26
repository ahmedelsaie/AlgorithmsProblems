#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>

using namespace std;
template <typename type>
void merge_sort(int start, int last, type array, type swap);
int fn();

pair<int, int> array[1005], help[1005];
int n;

int main()
{
    int cases = 1;
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%d %d", &array[i].first, &array[i].second);
        printf("Case %d: %d\n", cases++, fn());
    }
    return 0;
}

int fn()
{
    merge_sort(0, n - 1, array, help);
    int curr = 0, ret = 0;
    for(int i = 0; i < n; i++)
    {
        curr += array[i].first;
        ret = max(ret, curr + array[i].second);
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

        else if(swap[p1].second > array[p2].second)
            array[main_p] = swap[p1], p1++;

        else
            array[main_p] = array[p2], p2++;

        main_p++;
    }
    return;
}
